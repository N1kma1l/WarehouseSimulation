#include "services/StatisticsService.h"
#include <iostream>
#include <iomanip>

StatisticsService::StatisticsService() :
    total_days_(0),
    total_orders_processed_(0),
    total_orders_fulfilled_(0),
    total_orders_partially_fulfilled_(0),
    total_orders_unfulfilled_(0),
    total_revenue_(0.0),
    total_discount_loss_(0.0),
    total_expiration_loss_(0.0),
    total_products_sold_(0),
    total_products_discounted_(0),
    total_products_expired_(0),
    total_shipments_created_(0),
    total_supplier_requests_(0),
    total_supplier_deliveries_(0) {}

double StatisticsService::getOrderFulfillmentRate() const {
    if (total_orders_processed_ == 0) return 0.0;
    return (static_cast<double>(total_orders_fulfilled_) / total_orders_processed_) * 100.0;
}

double StatisticsService::getTotalLosses() const {
    return total_discount_loss_ + total_expiration_loss_;
}

double StatisticsService::getAverageDailyRevenue() const {
    if (total_days_ == 0) return 0.0;
    return total_revenue_ / total_days_;
}

double StatisticsService::getProfit() const {
    return total_revenue_ - getTotalLosses();
}

void StatisticsService::resetDailyStatistics() {
}

void StatisticsService::printSummary() const {
    std::cout << "=== СТАТИСТИКА СИСТЕМЫ ===" << std::endl;
    std::cout << "Дни работы: " << total_days_ << std::endl;
    std::cout << "Заказы: " << total_orders_processed_ 
              << " (выполнено: " << total_orders_fulfilled_ 
              << ", частично: " << total_orders_partially_fulfilled_ 
              << ", не выполнено: " << total_orders_unfulfilled_ << ")" << std::endl;
    std::cout << "Процент выполнения: " << std::fixed << std::setprecision(2) 
              << getOrderFulfillmentRate() << "%" << std::endl;
    std::cout << "Выручка: " << total_revenue_ << " руб." << std::endl;
    std::cout << "Потери: " << getTotalLosses() << " руб." << std::endl;
    std::cout << "Прибыль: " << getProfit() << " руб." << std::endl;
}