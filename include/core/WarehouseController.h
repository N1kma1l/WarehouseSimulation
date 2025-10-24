#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

#include "core/DataManager.h"
#include "services/OrderProcessor.h"
#include "services/DiscountService.h"
#include "services/ExpirationService.h"
#include "services/SupplierService.h"
#include "services/StatisticsService.h"
#include "services/OrderGenerator.h"
#include "models/Order.h"
#include "models/Product.h"

// Главный контроллер управления операциями склада
class WarehouseController {
    public:
    WarehouseController();
    
    // Геттер ссылки на менеджер данных
    DataManager& getDataManager() {
        return data_manager_;
    }    
    // Геттер константной ссылки на менеджер данных
    const DataManager& getDataManager() const {
        return data_manager_;
    }
    // Геттер ссылки на процессор заказов
    OrderProcessor& getOrderProcessor() {
        return order_processor_;
    }
    // Геттер константной ссылки на процессор заказов
    const OrderProcessor& getOrderProcessor() const {
        return order_processor_;
    }
    // Геттер ссылки на сервис уценки
    DiscountService& getDiscountService() {
        return discount_service_;
    }
    // Геттер константной ссылки на сервис уценки
    const DiscountService& getDiscountService() const {
        return discount_service_;
    }
    // Геттер ссылки на сервис контроля сроков
    ExpirationService& getExpirationService() {
        return expiration_service_;
    }
    // Геттер константной ссылки на сервис контроля сроков
    const ExpirationService& getExpirationService() const {
        return expiration_service_;
    }
    // Геттер ссылки на сервис поставщиков
    SupplierService& getSupplierService() {
        return supplier_service_;
    }
    // Геттер константной ссылки на сервис поставщиков
    const SupplierService& getSupplierService() const {
        return supplier_service_;
    }
    // Геттер ссылки на сервис статистики
    StatisticsService& getStatisticsService() {
        return statistics_service_;
    }
    // Геттер константной ссылки на сервис статистики
    const StatisticsService& getStatisticsService() const {
        return statistics_service_;
    }
    // Геттер ссылки на генератор заказов
    OrderGenerator& getOrderGenerator() {
        return order_generator_;
    }
    // Геттер константной ссылки на генератор заказов
    const OrderGenerator& getOrderGenerator() const {
        return order_generator_;
    }
    // Геттер флага инициализации контроллера
    bool isInitialized() const {
        return is_initialized_;
    }
    // Геттер количества обработанных дней
    int getProcessedDays() const {
        return processed_days_;
    }
    
    // Сеттер флага инициализации контроллера
    void setInitialized(bool initialized) {
        is_initialized_ = initialized;
    }
    // Сеттер количества обработанных дней
    void setProcessedDays(int days) {
        processed_days_ = days;
    }
    
    // Метод увеличения счетчика обработанных дней
    void incrementProcessedDays() {
        processed_days_++;
    }

    // Метод сброса дневной статистики всех сервисов
    void resetDailyStatistics();
    // Метод инициализации контроллера
    void initialize();
    // Метод обработки одного дня работы склада
    void processDay(int day);

    // Метод обработки заказов на день
    void processDailyOrders(int day);
    // Метод обработки заказов для конкретного магазина
    void processStoreOrders(int store_id, int day);
    // Метод обработки одной позиции заказа
    void processOrderItem(Order& order, Product& product, int requested_quantity);
    
    // Метод применения уценок к товарам
    void applyDiscounts(int day);
    // Метод контроля сроков годности
    void checkExpirations(int day);
    // Метод обработки поставок от поставщиков
    void processSupplierDeliveries(int day);
    // Метод генерации отчетов за день
    void generateDailyReport(int day) const;
    // Метод проверки готовности контроллера к работе
    bool isReady() const;

    private:
    DataManager data_manager_; // Менеджер данных
    OrderProcessor order_processor_; // Процессор заказов
    DiscountService discount_service_; // Сервис уценки
    ExpirationService expiration_service_; // Сервис контроля сроков
    SupplierService supplier_service_; // Сервис поставщиков
    StatisticsService statistics_service_; // Сервис статистики
    OrderGenerator order_generator_; // Генератор заказов
    bool is_initialized_; // Флаг инициализации
    int processed_days_; // Количество обработанных дней
};

#endif