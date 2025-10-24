#ifndef ORDERPROCESSOR_H
#define ORDERPROCESSOR_H

// Сервис обработки заказов
class OrderProcessor {
    public:
    OrderProcessor();
    
    // Геттер общего количества обработанных заказов
    int getTotalProcessedOrders() const {
        return total_processed_orders_;
    }
    // Геттер общего количества успешно выполненных заказов
    int getTotalFulfilledOrders() const {
        return total_fulfilled_orders_;
    }
    // Геттер общего количества частично выполненных заказов
    int getTotalPartiallyFulfilledOrders() const {
        return total_partially_fulfilled_orders_;
    }
    // Геттер общего количества невыполненных заказов
    int getTotalUnfulfilledOrders() const {
        return total_unfulfilled_orders_;
    }
    // Геттер общей стоимости обработанных заказов
    double getTotalOrderValue() const {
        return total_order_value_;
    }
    // Геттер дневного количества обработанных заказов
    int getDailyProcessedOrders() const {
        return daily_processed_orders_;
    }
    // Геттер дневного количества успешно выполненных заказов
    int getDailyFulfilledOrders() const {
        return daily_fulfilled_orders_;
    }
    // Геттер дневной стоимости заказов
    double getDailyOrderValue() const {
        return daily_order_value_;
    }

    // Сеттер общего количества обработанных заказов
    void setTotalProcessedOrders(int count) {
        total_processed_orders_ = count;
    }
    // Сеттер общего количества успешно выполненных заказов
    void setTotalFulfilledOrders(int count) {
        total_fulfilled_orders_ = count;
    }
    // Сеттер общего количества частично выполненных заказов
    void setTotalPartiallyFulfilledOrders(int count) {
        total_partially_fulfilled_orders_ = count;
    }
    // Сеттер общего количества невыполненных заказов
    void setTotalUnfulfilledOrders(int count) {
        total_unfulfilled_orders_ = count;
    }
    // Сеттер общей стоимости обработанных заказов
    void setTotalOrderValue(double value) {
        total_order_value_ = value;
    }
    // Сеттер дневного количества обработанных заказов
    void setDailyProcessedOrders(int count) {
        daily_processed_orders_ = count;
    }
    // Сеттер дневного количества успешно выполненных заказов
    void setDailyFulfilledOrders(int count) {
        daily_fulfilled_orders_ = count;
    }
    // Сеттер дневной стоимости заказов
    void setDailyOrderValue(double value) {
        daily_order_value_ = value;
    }
    
    // Метод увеличения счетчика обработанных заказов
    void incrementProcessedOrders() {
        total_processed_orders_++;
        daily_processed_orders_++;
    }
    // Метод увеличения счетчика выполненных заказов
    void incrementFulfilledOrders() {
        total_fulfilled_orders_++;
        daily_fulfilled_orders_++;
    }
    // Метод увеличения счетчика частично выполненных заказов
    void incrementPartiallyFulfilledOrders() {
        total_partially_fulfilled_orders_++;
    }
    // Метод увеличения счетчика невыполненных заказов
    void incrementUnfulfilledOrders() {
        total_unfulfilled_orders_++;
    }
    // Метод добавления стоимости заказа
    void addOrderValue(double value) {
        total_order_value_ += value;
        daily_order_value_ += value;
    }

    // Метод сброса дневной статистики
    void resetDailyStatistics();
    // Метод получения процента успешных заказов
    double getSuccessRate() const;

    private:
    int total_processed_orders_; // Общее количество обработанных заказов
    int total_fulfilled_orders_; // Общее количество полностью выполненных заказов
    int total_partially_fulfilled_orders_; // Общее количество частично выполненных заказов
    int total_unfulfilled_orders_; // Общее количество невыполненных заказов
    double total_order_value_; // Общая стоимость всех заказов
    int daily_processed_orders_; // Дневное количество обработанных заказов
    int daily_fulfilled_orders_; // Дневное количество выполненных заказов
    double daily_order_value_; // Дневная стоимость заказов
};

#endif