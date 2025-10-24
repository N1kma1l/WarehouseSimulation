#ifndef ORDERGENERATOR_H
#define ORDERGENERATOR_H

#include "utils/RandomGenerator.h"

// Класс для генерации заказов от магазинов
class OrderGenerator {
    public:
    OrderGenerator();
    
    // Геттер общего количества сгенерированных заказов
    int getTotalOrdersGenerated() const {
        return total_orders_generated_;
    }
    // Геттер базовой вероятности заказа
    double getBaseOrderProbability() const {
        return base_order_probability_;
    }
    // Геттер вероятности заказа уцененного товара
    double getDiscountedOrderProbability() const {
        return discounted_order_probability_;
    }
    // Геттер минимального количества позиций в заказе
    int getMinOrderItems() const {
        return min_order_items_;
    }
    // Геттер максимального количества позиций в заказе
    int getMaxOrderItems() const {
        return max_order_items_;
    }
    
    // Сеттер базовой вероятности заказа
    void setBaseOrderProbability(double probability) {
        base_order_probability_ = probability;
    }
    // Сеттер вероятности заказа уцененного товара
    void setDiscountedOrderProbability(double probability) {
        discounted_order_probability_ = probability;
    }
    // Сеттер минимального количества позиций в заказе
    void setMinOrderItems(int count) {
        min_order_items_ = count;
    }
    // Сеттер максимального количества позиций в заказе
    void setMaxOrderItems(int count) {
        max_order_items_ = count;
    }
    
    // Метод увеличения счетчика сгенерированных заказов
    void incrementOrdersGenerated() {
        total_orders_generated_++;
    }

    // Метод сброса дневной статистики генерации
    void resetDailyStatistics();
    // Метод проверки, делает ли магазин заказ сегодня
    bool shouldStoreMakeOrder(int store_id, int day) const;
    // Метод генерации количества позиций в заказе
    int generateOrderItemsCount() const;
    // Метод генерации количества товара для позиции
    int generateProductQuantity() const;
    // Метод выбора товара для заказа
    int selectProductForOrder(bool prefer_discounted) const;
    // Метод генерации заказа для магазина
    void generateOrderForStore(int store_id, int day);
    // Метод генерации заказов на день
    void generateDailyOrders(int day);
    // Метод получения процента заказов с уцененными товарами
    double getDiscountedOrdersPercentage() const;

    private:
    int total_orders_generated_; // Общее количество сгенерированных заказов
    double base_order_probability_; // Базовая вероятность заказа магазина
    double discounted_order_probability_; // Вероятность заказа уцененного товара
    int min_order_items_; // Минимальное количество позиций в заказе
    int max_order_items_; // Максимальное количество позиций в заказе
    mutable RandomGenerator random_; // Генератор случайных чисел
};

#endif