#include "core/Warehouse.h"

Warehouse::Warehouse() : 
    total_products_count_(0),
    total_capacity_(1000),
    total_sales_(0.0),
    total_discount_losses_(0.0),
    total_expiration_losses_(0.0) {}