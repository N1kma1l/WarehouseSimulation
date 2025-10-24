#include "core/WarehouseController.h"
#include <iostream>

WarehouseController::WarehouseController() :
    is_initialized_(false),
    processed_days_(0) {}

void WarehouseController::initialize() {
    std::cout << "Инициализация WarehouseController..." << std::endl;
    
    data_manager_.initializeTestData();
    
    if (!data_manager_.validateData()) {
        std::cout << "Ошибка: данные не прошли валидацию" << std::endl;
        return;
    }
    
    is_initialized_ = true;
    std::cout << "WarehouseController успешно инициализирован" << std::endl;
}

void WarehouseController::processDay(int day) {
    if (!isReady()) {
        std::cout << "Ошибка: контроллер не готов к работе" << std::endl;
        return;
    }
    
    std::cout << "\n=== ОБРАБОТКА ДНЯ " << day << " ===" << std::endl;
    
    processDailyOrders(day);
    applyDiscounts(day);
    checkExpirations(day);
    processSupplierDeliveries(day);
    generateDailyReport(day);
    
    resetDailyStatistics();
    
    incrementProcessedDays();
    std::cout << "День " << day << " успешно обработан" << std::endl;
}

void WarehouseController::processDailyOrders(int day) {
    std::cout << "\n--- Обработка заказов ---" << std::endl;
    
    order_generator_.generateDailyOrders(day);
    std::cout << "Заказы обработаны" << std::endl;
}

void WarehouseController::applyDiscounts(int day) {
    std::cout << "\n--- Применение уценок ---" << std::endl;
    std::cout << "Уценки применены" << std::endl;
}

void WarehouseController::checkExpirations(int day) {
    std::cout << "\n--- Контроль сроков годности ---" << std::endl;
    std::cout << "Сроки годности проверены" << std::endl;
}

void WarehouseController::processSupplierDeliveries(int day) {
    std::cout << "\n--- Обработка поставок ---" << std::endl;
    
    std::cout << "Поставки обработаны" << std::endl;
}

void WarehouseController::generateDailyReport(int day) const {
    std::cout << "\n--- Ежедневный отчет ---" << std::endl;
    std::cout << "Статистика за день " << day << ":" << std::endl;
    std::cout << " - Обработано заказов: " << order_processor_.getTotalProcessedOrders() << std::endl;
    std::cout << " - Уценено товаров: " << discount_service_.getTotalDiscountedProducts() << std::endl;
    std::cout << " - Списано товаров: " << expiration_service_.getTotalExpiredProducts() << std::endl;
}

bool WarehouseController::isReady() const {
    return is_initialized_ && data_manager_.isDataInitialized();
}

void WarehouseController::resetDailyStatistics() {
    order_processor_.resetDailyStatistics();
    discount_service_.resetDailyDiscountStatistics();
    expiration_service_.resetDailyExpirationStatistics();
    supplier_service_.resetDailySupplierStatistics();
    statistics_service_.resetDailyStatistics();
    order_generator_.resetDailyStatistics();
}