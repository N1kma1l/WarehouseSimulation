#include "services/OrderGenerator.h"
#include <iostream>

OrderGenerator::OrderGenerator() :
    total_orders_generated_(0),
    base_order_probability_(0.7),
    discounted_order_probability_(0.6),
    min_order_items_(1),
    max_order_items_(5) {}

bool OrderGenerator::shouldStoreMakeOrder(int store_id, int day) const {
    return random_.checkProbability(base_order_probability_);
}

int OrderGenerator::generateOrderItemsCount() const {
    return random_.getInt(min_order_items_, max_order_items_);
}

int OrderGenerator::generateProductQuantity() const {
    return random_.getInt(10, 100);
}

int OrderGenerator::selectProductForOrder(bool prefer_discounted) const {
    return random_.getInt(1, 15);
}

void OrderGenerator::generateOrderForStore(int store_id, int day) {
    if (shouldStoreMakeOrder(store_id, day)) {
        std::cout << "Магазин #" << store_id << " делает заказ" << std::endl;
        
        int items_count = generateOrderItemsCount();
        std::cout << "Количество позиций в заказе: " << items_count << std::endl;
        
        for (int i = 0; i < items_count; ++i) {
            int product_id = selectProductForOrder(false);
            int quantity = generateProductQuantity();
            std::cout << "  Позиция " << (i + 1) << ": Товар #" << product_id 
                      << ", Количество: " << quantity << " ед." << std::endl;
        }
        
        incrementOrdersGenerated();
    } else {
        std::cout << "Магазин #" << store_id << " не делает заказ сегодня" << std::endl;
    }
}

void OrderGenerator::generateDailyOrders(int day) {
    std::cout << "\n=== ГЕНЕРАЦИЯ ЗАКАЗОВ НА ДЕНЬ " << day << " ===" << std::endl;
    
    // Временная заглушка - генерируем заказы для 5 магазинов
    for (int store_id = 1; store_id <= 5; ++store_id) {
        generateOrderForStore(store_id, day);
    }
    
    std::cout << "Всего сгенерировано заказов за все время: " 
              << total_orders_generated_ << std::endl;
}

double OrderGenerator::getDiscountedOrdersPercentage() const {
    return 25.0;
}

void OrderGenerator::resetDailyStatistics() {
}