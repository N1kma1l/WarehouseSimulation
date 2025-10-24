#include "services/OrderProcessor.h"

OrderProcessor::OrderProcessor() :
    total_processed_orders_(0),
    total_fulfilled_orders_(0),
    total_partially_fulfilled_orders_(0),
    total_unfulfilled_orders_(0),
    total_order_value_(0.0),
    daily_processed_orders_(0),
    daily_fulfilled_orders_(0),
    daily_order_value_(0.0) {}

void OrderProcessor::resetDailyStatistics() {
    daily_processed_orders_ = 0;
    daily_fulfilled_orders_ = 0;
    daily_order_value_ = 0.0;
}

double OrderProcessor::getSuccessRate() const {
    if (total_processed_orders_ == 0) return 0.0;
    return (static_cast<double>(total_fulfilled_orders_) / total_processed_orders_) * 100.0;
}