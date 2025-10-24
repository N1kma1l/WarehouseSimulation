#ifndef SUPPLIERSERVICE_H
#define SUPPLIERSERVICE_H

#include <vector>

// Сервис управления поставщиками и заявками
class SupplierService {
    public:
    SupplierService();
    
    // Геттер общего количества созданных заявок
    int getTotalRequestsCreated() const {
        return total_requests_created_;
    }
    // Геттер общего количества выполненных поставок
    int getTotalDeliveriesCompleted() const {
        return total_deliveries_completed_;
    }    
    // Геттер общего количества просроченных поставок
    int getTotalDeliveriesDelayed() const {
        return total_deliveries_delayed_;
    }    
    // Геттер общего объема поставленных товаров
    int getTotalProductsDelivered() const {
        return total_products_delivered_;
    }    
    // Геттер общей стоимости поставок
    double getTotalDeliveryCost() const {
        return total_delivery_cost_;
    }
    // Геттер порога для создания заявки
    int getRestockThreshold() const {
        return restock_threshold_;
    }    
    // Геттер стандартного количества для заказа
    int getStandardOrderQuantity() const {
        return standard_order_quantity_;
    }
    // Геттер дневного количества созданных заявок
    int getDailyRequestsCreated() const {
        return daily_requests_created_;
    }
    // Геттер дневного количества выполненных поставок
    int getDailyDeliveriesCompleted() const {
        return daily_deliveries_completed_;
    }
    // Геттер дневного количества просроченных поставок
    int getDailyDeliveriesDelayed() const {
        return daily_deliveries_delayed_;
    }
    // Геттер дневного объема поставленных товаров
    int getDailyProductsDelivered() const {
        return daily_products_delivered_;
    }
    // Геттер дневной стоимости поставок
    double getDailyDeliveryCost() const {
        return daily_delivery_cost_;
    }

    // Сеттер общего количества созданных заявок
    void setTotalRequestsCreated(int count) {
        total_requests_created_ = count;
    }
    // Сеттер общего количества выполненных поставок
    void setTotalDeliveriesCompleted(int count) {
        total_deliveries_completed_ = count;
    }
    // Сеттер общего количества просроченных поставок
    void setTotalDeliveriesDelayed(int count) {
        total_deliveries_delayed_ = count;
    }
    // Сеттер общего объема поставленных товаров
    void setTotalProductsDelivered(int count) {
        total_products_delivered_ = count;
    }
    // Сеттер общей стоимости поставок
    void setTotalDeliveryCost(double cost) {
        total_delivery_cost_ = cost;
    }
    // Сеттер порога для создания заявки
    void setRestockThreshold(int threshold) {
        restock_threshold_ = threshold;
    }
    // Сеттер стандартного количества для заказа
    void setStandardOrderQuantity(int quantity) {
        standard_order_quantity_ = quantity;
    }
    // Сеттер дневного количества созданных заявок
    void setDailyRequestsCreated(int count) {
        daily_requests_created_ = count;
    }
    // Сеттер дневного количества выполненных поставок
    void setDailyDeliveriesCompleted(int count) {
        daily_deliveries_completed_ = count;
    }
    // Сеттер дневного количества просроченных поставок
    void setDailyDeliveriesDelayed(int count) {
        daily_deliveries_delayed_ = count;
    }
    // Сеттер дневного объема поставленных товаров
    void setDailyProductsDelivered(int count) {
        daily_products_delivered_ = count;
    }
    // Сеттер дневной стоимости поставок
    void setDailyDeliveryCost(double cost) {
        daily_delivery_cost_ = cost;
    }

    // Метод увеличения счетчика созданных заявок
    void incrementRequestsCreated() {
        total_requests_created_++;
        daily_requests_created_++;
    }
    // Метод увеличения счетчика выполненных поставок
    void incrementDeliveriesCompleted() {
        total_deliveries_completed_++;
        daily_deliveries_completed_++;
    }
    // Метод увеличения счетчика просроченных поставок
    void incrementDeliveriesDelayed() {
        total_deliveries_delayed_++;
        daily_deliveries_delayed_++;
    }
    // Метод добавления поставленных товаров
    void addProductsDelivered(int count) {
        total_products_delivered_ += count;
        daily_products_delivered_ += count;
    }
    // Метод добавления стоимости поставки
    void addDeliveryCost(double cost) {
        total_delivery_cost_ += cost;
        daily_delivery_cost_ += cost;
    }

    // Метод проверки необходимости пополнения запаса
    bool needsRestock(int current_stock, int max_stock) const;
    // Метод расчета количества для заказа
    int calculateOrderQuantity(int current_stock, int max_stock) const;
    // Метод сброса дневной статистики поставок
    void resetDailySupplierStatistics();


    private:
    int total_requests_created_; // Общее количество созданных заявок
    int total_deliveries_completed_; // Общее количество выполненных поставок
    int total_deliveries_delayed_; // Общее количество просроченных поставок
    int total_products_delivered_; // Общее количество поставленных товаров
    double total_delivery_cost_; // Общая стоимость поставок

    int daily_requests_created_; // Дневное количество созданных заявок
    int daily_deliveries_completed_; // Дневное количество выполненных поставок
    int daily_deliveries_delayed_; // Дневное количество просроченных поставок
    int daily_products_delivered_; // Дневное количество поставленных товаров
    double daily_delivery_cost_; // Дневная стоимость поставок
    
    int restock_threshold_; // Порог для создания заявки
    int standard_order_quantity_; // Стандартное количество для заказа
};

#endif