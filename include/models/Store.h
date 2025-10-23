#ifndef STORE_H
#define STORE_H

#include <string>

// Класс магазина
class Store {
    public:
    Store(int id, const std::string& name);
    
    // Геттер id магазина
    int getId() const {
        return id_;
    }
    // Геттер названия магазина
    const std::string& getName() const {
        return name_;
    }
    // Геттер вероятности заказа уцененных товаров
    double getDiscountedProductProbability() const {
        return discounted_product_probability_;
    }
    // Геттер базовой вероятности заказа
    double getBaseOrderProbability() const {
        return base_order_probability_;
    }    
    // Геттер минимального количества позиций в заказе
    int getMinOrderItems() const {
        return min_order_items_;
    }    
    // Геттер максимального количества позиций в заказе
    int getMaxOrderItems() const {
        return max_order_items_;
    }
    // Геттер количества позиций в сегодняшнем заказе
    int getTodaysOrderItemCount() const;

    // Сеттер вероятности заказа уцененных товаров
    void setDiscountedProductProbability(double probability) {
        discounted_product_probability_ = probability;
    }
    // Сеттер базовой вероятности заказа
    void setBaseOrderProbability(double probability) {
        base_order_probability_ = probability;
    }
    // Сеттер минимального количества позиций в заказе
    void setMinOrderItems(int count) {
        min_order_items_ = count;
    }
    // Сеттер максимального количества позиций в заказе
    void setMaxOrderItems(int count) {
        max_order_items_ = count;
    }

    // Метод проверки, делает ли магазин заказ сегодня
    bool shouldMakeOrder(int day) const;

    private:
    int id_; // id магазина
    std::string name_; // Название магазина
    
    double base_order_probability_; // Базовая вероятность заказа в день
    double discounted_product_probability_; // Вероятность заказа уцененного товара
    
    int min_order_items_; // Минимальное количество позиций в заказе
    int max_order_items_; // Максимальное количество позиций в заказе
};

#endif