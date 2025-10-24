#ifndef EXPIRATIONSERVICE_H
#define EXPIRATIONSERVICE_H

// Сервис контроля сроков годности товаров
class ExpirationService {
    public:
    ExpirationService();
    
    // Геттер общего количества списанных товаров
    int getTotalExpiredProducts() const {
        return total_expired_products_;
    }    
    // Геттер общих потерь от списания
    double getTotalExpirationLosses() const {
        return total_expiration_losses_;
    }    
    // Геттер количества проверок на просроченность
    int getTotalExpirationChecks() const {
        return total_expiration_checks_;
    }
    // Геттер минимального срока годности для предупреждения
    int getMinExpirationWarningDays() const {
        return min_expiration_warning_days_;
    }
    // Геттер дневного количества списанных товаров
    int getDailyExpiredProducts() const {
        return daily_expired_products_;
    }
    // Геттер дневных потерь от списания
    double getDailyExpirationLosses() const {
        return daily_expiration_losses_;
    }
    // Геттер дневного количества проверок на просроченность
    int getDailyExpirationChecks() const {
        return daily_expiration_checks_;
    }

    // Сеттер общего количества списанных товаров
    void setTotalExpiredProducts(int count) {
        total_expired_products_ = count;
    }
    // Сеттер общих потерь от списания
    void setTotalExpirationLosses(double losses) {
        total_expiration_losses_ = losses;
    }
    // Сеттер количества проверок на просроченность
    void setTotalExpirationChecks(int checks) {
        total_expiration_checks_ = checks;
    }
    // Сеттер минимального срока годности для предупреждения
    void setMinExpirationWarningDays(int days) {
        min_expiration_warning_days_ = days;
    }
    // Сеттер дневного количества списанных товаров
    void setDailyExpiredProducts(int count) {
        daily_expired_products_ = count;
    }
    // Сеттер дневных потерь от списания
    void setDailyExpirationLosses(double losses) {
        daily_expiration_losses_ = losses;
    }
    // Сеттер дневного количества проверок на просроченность
    void setDailyExpirationChecks(int checks) {
        daily_expiration_checks_ = checks;
    }

    // Метод увеличения счетчика списанных товаров
    void incrementExpiredProducts() {
        total_expired_products_++;
        daily_expired_products_++;
    }
    // Метод увеличения счетчика проверок
    void incrementExpirationChecks() {
        total_expiration_checks_++;
        daily_expiration_checks_++;
    }
    // Метод добавления потерь от списания
    void addExpirationLoss(double loss) {
        total_expiration_losses_ += loss;
        daily_expiration_losses_ += loss;
    }

    // Метод проверки просроченности товара
    bool isProductExpired(int days_until_expiration) const;
    // Метод проверки необходимости предупреждения о скором истечении срока
    bool needsExpirationWarning(int days_until_expiration) const;
    // Метод получения уровня срочности (0-нет, 1-скоро истекает, 2-просрочен)
    int getExpirationUrgencyLevel(int days_until_expiration) const;
    // Метод сброса дневной статистики списаний
    void resetDailyExpirationStatistics();



    private:
    int total_expired_products_; // Общее количество списанных товаров
    double total_expiration_losses_; // Общие потери от списания
    int total_expiration_checks_; // Общее количество проверок на просроченность
    int min_expiration_warning_days_; // Минимальный срок для предупреждения
    int daily_expired_products_; // Дневное количество списанных товаров
    double daily_expiration_losses_; // Дневные потери от списания
    int daily_expiration_checks_; // Дневное количество проверок на просроченность
};

#endif