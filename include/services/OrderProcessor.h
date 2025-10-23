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
    
    // Метод увеличения счетчика обработанных заказов
    void incrementProcessedOrders() {
        total_processed_orders_++;
    }
    // Метод увеличения счетчика выполненных заказов
    void incrementFulfilledOrders() {
        total_fulfilled_orders_++;
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
};

#endif