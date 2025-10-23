#include "models/Store.h"

Store::Store(int id, const std::string& name) : 
    id_(id), 
    name_(name),
    base_order_probability_(0.8),
    discounted_product_probability_(0.6),
    min_order_items_(1),
    max_order_items_(5) {}

int Store::getTodaysOrderItemCount() const {
    return (min_order_items_ + max_order_items_) / 2;
}

bool Store::shouldMakeOrder(int day) const {
    return (day % 2 == 0);
}
