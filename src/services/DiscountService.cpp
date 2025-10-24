#include "services/DiscountService.h"

DiscountService::DiscountService() :
    base_discount_percent_(10.0),
    max_discount_percent_(50.0),
    days_before_expiration_for_discount_(3),
    total_discounted_products_(0),
    total_discount_revenue_(0.0),
    total_discount_loss_(0.0),
    daily_discounted_products_(0),
    daily_discount_revenue_(0.0),
    daily_discount_loss_(0.0) {}

double DiscountService::calculateDiscountPercent(int days_until_expiration) const {
    if (days_until_expiration <= 1) {
        return max_discount_percent_;
    } else if (days_until_expiration == 2) {
        return base_discount_percent_ * 2;
    } else if (days_until_expiration == 3) {
        return base_discount_percent_;
    }
    return 0.0;
}

bool DiscountService::shouldApplyDiscount(int days_until_expiration) const {
    return days_until_expiration <= days_before_expiration_for_discount_ && days_until_expiration > 0;
}

void DiscountService::resetDailyDiscountStatistics() {
    daily_discounted_products_ = 0;
    daily_discount_revenue_ = 0.0;
    daily_discount_loss_ = 0.0;
}