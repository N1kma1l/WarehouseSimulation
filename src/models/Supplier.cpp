#include "models/Supplier.h"

Supplier::Supplier(int id, const std::string& name, const std::string& contact_info) : 
    id_(id),
    name_(name),
    contact_info_(contact_info),
    min_delivery_days_(1),
    max_delivery_days_(5),
    reliability_(0.9) {}

int Supplier::calculateDeliveryTime() const {
    return (min_delivery_days_ + max_delivery_days_) / 2;
}