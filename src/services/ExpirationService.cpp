#include "services/ExpirationService.h"

ExpirationService::ExpirationService() :
    total_expired_products_(0),
    total_expiration_losses_(0.0),
    total_expiration_checks_(0),
    min_expiration_warning_days_(5) {}

bool ExpirationService::isProductExpired(int days_until_expiration) const {
    return days_until_expiration <= 0;
}

bool ExpirationService::needsExpirationWarning(int days_until_expiration) const {
    return days_until_expiration <= min_expiration_warning_days_ && days_until_expiration > 0;
}

int ExpirationService::getExpirationUrgencyLevel(int days_until_expiration) const {
    if (days_until_expiration <= 0) {
        return 2;
    } else if (days_until_expiration <= min_expiration_warning_days_) {
        return 1;
    }
    return 0;
}

void ExpirationService::resetDailyExpirationStatistics() {
    daily_expired_products_ = 0;
    daily_expiration_losses_ = 0.0;
    daily_expiration_checks_ = 0;
}