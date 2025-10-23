#ifndef DISCOUNTSERVICE_H
#define DISCOUNTSERVICE_H

// Сервис управления уценкой товаров
class DiscountService {
    public:
    DiscountService();
    
    // Геттер базового процента уценки
    double getBaseDiscountPercent() const {
        return base_discount_percent_;
    }
    // Геттер максимального процента уценки
    double getMaxDiscountPercent() const {
        return max_discount_percent_;
    }
    // Геттер дней до уценки
    int getDaysBeforeExpirationForDiscount() const {
        return days_before_expiration_for_discount_;
    }    
    // Геттер общего количества уцененных товаров
    int getTotalDiscountedProducts() const {
        return total_discounted_products_;
    }    
    // Геттер общей выручки от уцененных товаров
    double getTotalDiscountRevenue() const {
        return total_discount_revenue_;
    }    
    // Геттер общих потерь от уценки
    double getTotalDiscountLoss() const {
        return total_discount_loss_;
    }

    // Сеттер базового процента уценки
    void setBaseDiscountPercent(double percent) {
        base_discount_percent_ = percent;
    }
    // Сеттер максимального процента уценки
    void setMaxDiscountPercent(double percent) {
        max_discount_percent_ = percent;
    }
    // Сеттер дней до уценки
    void setDaysBeforeExpirationForDiscount(int days) {
        days_before_expiration_for_discount_ = days;
    }
    // Сеттер общего количества уцененных товаров
    void setTotalDiscountedProducts(int count) {
        total_discounted_products_ = count;
    }
    // Сеттер общей выручки от уцененных товаров
    void setTotalDiscountRevenue(double revenue) {
        total_discount_revenue_ = revenue;
    }
    // Сеттер общих потерь от уценки
    void setTotalDiscountLoss(double loss) {
        total_discount_loss_ = loss;
    }

    // Метод увеличения счетчика уцененных товаров
    void incrementDiscountedProducts() {
        total_discounted_products_++;
    }
    // Метод добавления выручки от уценки
    void addDiscountRevenue(double revenue) {
        total_discount_revenue_ += revenue;
    }
    // Метод добавления потерь от уценки
    void addDiscountLoss(double loss) {
        total_discount_loss_ += loss;
    }
    
    // Метод расчета процента уценки на основе дней до истечения срока
    double calculateDiscountPercent(int days_until_expiration) const;
    // Метод проверки необходимости уценки товара
    bool shouldApplyDiscount(int days_until_expiration) const;
    // Метод сброса дневной статистики уценки
    void resetDailyDiscountStatistics();

    private:
    double base_discount_percent_;          // Базовый процент уценки
    double max_discount_percent_;           // Максимальный процент уценки
    int days_before_expiration_for_discount_; // За сколько дней до истечения срока делать уценку
    
    int total_discounted_products_;         // Общее количество уцененных товаров
    double total_discount_revenue_;         // Общая выручка от уцененных товаров
    double total_discount_loss_;            // Общие потери от уценки
};

#endif