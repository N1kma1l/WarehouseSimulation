#include "core/WarehouseController.h"
#include <iostream>

// Конструктор по умолчанию
WarehouseController::WarehouseController() :
    is_initialized_(false),
    processed_days_(0) {}

// Метод инициализации контроллера
void WarehouseController::initialize() {
    std::cout << "Инициализация WarehouseController..." << std::endl;
    
    // Инициализируем менеджер данных
    data_manager_.initializeTestData();
    
    // Проверяем готовность данных
    if (!data_manager_.validateData()) {
        std::cout << "Ошибка: данные не прошли валидацию" << std::endl;
        return;
    }
    
    is_initialized_ = true;
    std::cout << "WarehouseController успешно инициализирован" << std::endl;
}

// Метод обработки одного дня работы склада
void WarehouseController::processDay(int day) {
    if (!isReady()) {
        std::cout << "Ошибка: контроллер не готов к работе" << std::endl;
        return;
    }
    
    std::cout << "\n=== ОБРАБОТКА ДНЯ " << day << " ===" << std::endl;
    
    // Основная последовательность операций за день
    processDailyOrders(day);
    applyDiscounts(day);
    checkExpirations(day);
    processSupplierDeliveries(day);
    generateDailyReport(day);
    
    // Сбрасываем дневную статистику
    resetDailyStatistics();
    
    incrementProcessedDays();
    std::cout << "День " << day << " успешно обработан" << std::endl;
}

// Метод обработки заказов на день
void WarehouseController::processDailyOrders(int day) {
    std::cout << "\n--- Обработка заказов ---" << std::endl;
    
    // Генерируем заказы от магазинов
    order_generator_.generateDailyOrders(day);
    
    // Получаем сгенерированные заказы (временная логика)
    // В реальной системе здесь будет работа с реальными объектами Order
    
    // Обрабатываем каждый магазин
    const auto& stores = data_manager_.getStores();
    for (const auto& store : stores) {
        processStoreOrders(store.getId(), day);
    }
    
    std::cout << "Заказы обработаны" << std::endl;
}

// Метод обработки заказов для конкретного магазина
void WarehouseController::processStoreOrders(int store_id, int day) {
    // Проверяем, делает ли магазин заказ сегодня
    if (order_generator_.shouldStoreMakeOrder(store_id, day)) {
        std::cout << "Обработка заказа для магазина #" << store_id << std::endl;
        
        // Создаем объект заказа
        Order order(order_processor_.getTotalProcessedOrders() + 1, store_id);
        
        // Генерируем позиции заказа
        int items_count = order_generator_.generateOrderItemsCount();
        for (int i = 0; i < items_count; ++i) {
            int product_id = order_generator_.selectProductForOrder(false);
            int quantity = order_generator_.generateProductQuantity();
            
            // Ищем товар в базе данных
            Product* product = data_manager_.getProductById(product_id);
            if (product) {
                std::string product_name = product->getName();
                order.addItem(product_id, product_name, quantity);
                
                // Обрабатываем позицию заказа
                processOrderItem(order, *product, quantity);
            }
        }
        
        // Увеличиваем счетчик обработанных заказов
        order_processor_.incrementProcessedOrders();
        
        // Проверяем выполнение заказа
        if (order.isFullyAllocated()) {
            order_processor_.incrementFulfilledOrders();
            std::cout << "  Заказ #" << order.getId() << " полностью выполнен" << std::endl;
        } else if (order.getItemCount() > 0) {
            order_processor_.incrementPartiallyFulfilledOrders();
            std::cout << "  Заказ #" << order.getId() << " выполнен частично" << std::endl;
        } else {
            order_processor_.incrementUnfulfilledOrders();
            std::cout << "  Заказ #" << order.getId() << " не выполнен" << std::endl;
        }
        
        // Добавляем стоимость заказа в статистику
        order.calculateTotalCost();
        order_processor_.addOrderValue(order.getTotalCost());
        statistics_service_.addRevenue(order.getTotalCost());
    }
}

// Метод обработки одной позиции заказа
void WarehouseController::processOrderItem(Order& order, Product& product, int requested_quantity) {
    std::cout << "  Обработка товара: " << product.getName() 
              << " (запрошено: " << requested_quantity << " ед.)" << std::endl;
    
    int pack_size = product.getPackSize();
    int available_stock = product.getCurrentStock();
    
    // Рассчитываем сколько упаковок можем выделить
    int requested_packs = (requested_quantity + pack_size - 1) / pack_size; // Округление вверх
    int allocated_packs = std::min(requested_packs, available_stock);
    
    if (allocated_packs > 0) {
        // Выделяем товар со склада
        if (product.reduceStock(allocated_packs)) {
            double actual_quantity = allocated_packs * pack_size;
            double item_cost = allocated_packs * product.getPrice();
            
            // Обновляем информацию в заказе
            order.updateItemAllocation(product.getId(), allocated_packs, actual_quantity, item_cost);
            
            // Обновляем статистику
            statistics_service_.addProductsSold(allocated_packs);
            
            std::cout << "    Выделено: " << allocated_packs << " уп. (" 
                      << actual_quantity << " ед.) на сумму " << item_cost << " руб." << std::endl;
        } else {
            std::cout << "    Ошибка: не удалось выделить товар со склада" << std::endl;
        }
    } else {
        std::cout << "    Товар отсутствует на складе" << std::endl;
    }
    
    // Проверяем необходимость пополнения запаса
    if (supplier_service_.needsRestock(product.getCurrentStock(), product.getMaxStock())) {
        std::cout << "    ВНИМАНИЕ: Необходимо пополнение запаса товара #" << product.getId() << std::endl;
        supplier_service_.incrementRequestsCreated();
        statistics_service_.incrementSupplierRequests();
    }
}

// Метод применения уценок к товарам
void WarehouseController::applyDiscounts(int day) {
    (void)day; // Подавляем предупреждение
    std::cout << "\n--- Применение уценок ---" << std::endl;
    
    const auto& products = data_manager_.getProducts();
    int discounted_count = 0;
    
    for (const auto& product : products) {
        // Проверяем необходимость уценки (упрощенная логика)
        int days_in_stock = product.getDaysInStock(day);
        int expiration_date = product.getExpirationDate();
        int days_until_expiration = expiration_date - days_in_stock;
        
        if (discount_service_.shouldApplyDiscount(days_until_expiration)) {
            double discount_percent = discount_service_.calculateDiscountPercent(days_until_expiration);
            
            // Применяем уценку
            // В реальной системе здесь будет вызов product.setDiscount(discount_percent)
            
            discount_service_.incrementDiscountedProducts();
            statistics_service_.incrementProductsDiscounted();
            
            std::cout << "  Уценка товара: " << product.getName()
                      << " (" << discount_percent << "%)" << std::endl;
            discounted_count++;
        }
    }
    
    std::cout << "Уценки применены к " << discounted_count << " товарам" << std::endl;
}

// Метод контроля сроков годности
void WarehouseController::checkExpirations(int day) {
    (void)day; // Подавляем предупреждение
    std::cout << "\n--- Контроль сроков годности ---" << std::endl;
    
    const auto& products = data_manager_.getProducts();
    int expired_count = 0;
    
    for (const auto& product : products) {
        // Проверяем просроченность (упрощенная логика)
        int days_in_stock = product.getDaysInStock(day);
        if (expiration_service_.isProductExpired(product.getExpirationDate() - days_in_stock)) {
            // Списание товара
            // В реальной системе здесь будет product.reduceStock(product.getCurrentStock())
            
            expiration_service_.incrementExpiredProducts();
            statistics_service_.incrementProductsExpired();
            
            double loss = product.getCurrentStock() * product.getPrice();
            expiration_service_.addExpirationLoss(loss);
            statistics_service_.addExpirationLoss(loss);
            
            std::cout << "  СПИСАНИЕ: " << product.getName()
                      << " (" << product.getCurrentStock() << " уп.)"
                      << " убыток: " << loss << " руб." << std::endl;
            expired_count++;
        }
    }
    
    std::cout << "Списано " << expired_count << " просроченных товаров" << std::endl;
}

// Метод обработки поставок от поставщиков
void WarehouseController::processSupplierDeliveries(int day) {
    (void)day; // Подавляем предупреждение
    std::cout << "\n--- Обработка поставок ---" << std::endl;
    
    // Упрощенная логика поставок
    // В реальной системе здесь будет обработка реальных поставок
    
    std::cout << "Поставки обработаны" << std::endl;
}

// Метод генерации отчетов за день
void WarehouseController::generateDailyReport(int day) const {
    std::cout << "\n--- Ежедневный отчет ---" << std::endl;
    
    // Выводим основную статистику за день
    std::cout << "Статистика за день " << day << ":" << std::endl;
    std::cout << " - Обработано заказов: " << order_processor_.getDailyProcessedOrders() << std::endl;
    std::cout << " - Выполнено заказов: " << order_processor_.getDailyFulfilledOrders() << std::endl;
    std::cout << " - Уценено товаров: " << discount_service_.getDailyDiscountedProducts() << std::endl;
    std::cout << " - Списано товаров: " << expiration_service_.getDailyExpiredProducts() << std::endl;
    std::cout << " - Выручка: " << statistics_service_.getDailyRevenue() << " руб." << std::endl;
}

// Метод проверки готовности контроллера к работе
bool WarehouseController::isReady() const {
    return is_initialized_ && data_manager_.isDataInitialized();
}

// Метод сброса дневной статистики всех сервисов
void WarehouseController::resetDailyStatistics() {
    order_processor_.resetDailyStatistics();
    discount_service_.resetDailyDiscountStatistics();
    expiration_service_.resetDailyExpirationStatistics();
    supplier_service_.resetDailySupplierStatistics();
    statistics_service_.resetDailyStatistics();
    order_generator_.resetDailyStatistics();
}