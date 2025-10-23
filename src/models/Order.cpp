#include "Order.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

OrderItem::OrderItem(int id, const std::string& name, int quantity)
    : product_id(id), product_name(name), requested_quantity(quantity),
      allocated_packs(0), actual_quantity(0.0), item_cost(0.0) {}

Order::Order(int id, int store_id) 
    : order_id_(id), store_id_(store_id), is_processed_(false), total_cost_(0.0) {}

Order::Order(int id, int store_id, const std::vector<OrderItem>& initial_items)
    : order_id_(id), store_id_(store_id), items_(initial_items), 
      is_processed_(false), total_cost_(0.0) {
    calculateTotalCost();
}

void Order::addItem(int product_id, const std::string& product_name, int quantity) {
    if (quantity > 0) {
        items_.emplace_back(product_id, product_name, quantity);
    }
}

void Order::updateItemAllocation(int product_id, int allocated_packs, 
                                double actual_quantity, double cost) {
    auto it = std::find_if(items_.begin(), items_.end(),
        [product_id](const OrderItem& item) { 
            return item.product_id == product_id; 
        });
    
    if (it != items_.end()) {
        it->allocated_packs = allocated_packs;
        it->actual_quantity = actual_quantity;
        it->item_cost = cost;
        calculateTotalCost();
    }
}

void Order::calculateTotalCost() {
    total_cost_ = 0.0;
    for (const auto& item : items_) {
        total_cost_ += item.item_cost;
    }
}

bool Order::isFullyAllocated() const {
    if (items_.empty()) return false;
    
    for (const auto& item : items_) {
        if (item.allocated_packs == 0) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Order& order) {    
    os << "Заказ #" << order.order_id_ << " (Магазин #" << order.store_id_ << ")" << std::endl;
    os << "Статус: " << (order.is_processed_ ? "ОБРАБОТАН" : "В ОЖИДАНИИ") << std::endl;
    os << "Позиций: " << order.items_.size() << std::endl;
    os << "Стоимость: " << std::fixed << std::setprecision(2) << order.total_cost_ << " руб." << std::endl;
    
    if (!order.items_.empty()) {
        os << "Товары: ";
        for (size_t i = 0; i < order.items_.size(); ++i) {
            const auto& item = order.items_[i];
            os << item.product_name << "(" << item.requested_quantity << "→" 
               << item.actual_quantity << " ед.)";
            if (i < order.items_.size() - 1) os << ", ";
        }
    } 
    else {
        os << "Товары: нет позиций";
    }

    return os;
}