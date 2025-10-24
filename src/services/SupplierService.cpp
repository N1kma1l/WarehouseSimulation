#include "services/SupplierService.h"

SupplierService::SupplierService() :
    total_requests_created_(0),
    total_deliveries_completed_(0),
    total_deliveries_delayed_(0),
    total_products_delivered_(0),
    total_delivery_cost_(0.0),
    restock_threshold_(3),
    standard_order_quantity_(50),
    daily_requests_created_(0),
    daily_deliveries_completed_(0),
    daily_deliveries_delayed_(0),
    daily_products_delivered_(0),
    daily_delivery_cost_(0.0) {}

bool SupplierService::needsRestock(int current_stock, int max_stock) const {
    return current_stock <= restock_threshold_;
}

int SupplierService::calculateOrderQuantity(int current_stock, int max_stock) const {
    int needed = max_stock - current_stock;
    return std::min(needed, standard_order_quantity_);
}

void SupplierService::resetDailySupplierStatistics() {
    daily_requests_created_ = 0;
    daily_deliveries_completed_ = 0;
    daily_deliveries_delayed_ = 0;
    daily_products_delivered_ = 0;
    daily_delivery_cost_ = 0.0;
}