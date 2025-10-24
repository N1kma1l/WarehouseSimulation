#ifndef STATISTICSSERVICE_H
#define STATISTICSSERVICE_H

// Сервис сбора и анализа статистики работы склада
class StatisticsService {
    public:
    StatisticsService();
    
    // Геттер общего количества дней работы
    int getTotalDays() const {
        return total_days_;
    }
    // Геттер общего количества обработанных заказов
    int getTotalOrdersProcessed() const {
        return total_orders_processed_;
    }
    // Геттер общего количества полностью выполненных заказов
    int getTotalOrdersFulfilled() const {
        return total_orders_fulfilled_;
    }
    // Геттер общего количества частично выполненных заказов
    int getTotalOrdersPartiallyFulfilled() const {
        return total_orders_partially_fulfilled_;
    }
    // Геттер общего количества невыполненных заказов
    int getTotalOrdersUnfulfilled() const {
        return total_orders_unfulfilled_;
    }
    // Геттер общей выручки
    double getTotalRevenue() const {
        return total_revenue_;
    }
    // Геттер общих потерь от уценки
    double getTotalDiscountLoss() const {
        return total_discount_loss_;
    }
    // Геттер общих потерь от списания
    double getTotalExpirationLoss() const {
        return total_expiration_loss_;
    }
    // Геттер общего количества проданных товаров
    int getTotalProductsSold() const {
        return total_products_sold_;
    }
    // Геттер общего количества уцененных товаров
    int getTotalProductsDiscounted() const {
        return total_products_discounted_;
    }
    // Геттер общего количества списанных товаров
    int getTotalProductsExpired() const {
        return total_products_expired_;
    }
    // Геттер общего количества созданных перевозок
    int getTotalShipmentsCreated() const {
        return total_shipments_created_;
    }
    // Геттер общего количества заявок поставщикам
    int getTotalSupplierRequests() const {
        return total_supplier_requests_;
    }
    // Геттер общего количества выполненных поставок
    int getTotalSupplierDeliveries() const {
        return total_supplier_deliveries_;
    }
    // Геттер дневной выручки
    double getDailyRevenue() const {
        return daily_revenue_;
    }
    // Геттер дневных потерь от уценки
    double getDailyDiscountLoss() const {
        return daily_discount_loss_;
    }
    // Геттер дневных потерь от списания
    double getDailyExpirationLoss() const {
        return daily_expiration_loss_;
    }
    // Геттер дневного количества проданных товаров
    int getDailyProductsSold() const {
        return daily_products_sold_;
    }
    
    // Сеттер общего количества дней работы
    void setTotalDays(int days) {
        total_days_ = days;
    }
    // Сеттер общего количества обработанных заказов
    void setTotalOrdersProcessed(int count) {
        total_orders_processed_ = count;
    }
    // Сеттер общего количества полностью выполненных заказов
    void setTotalOrdersFulfilled(int count) {
        total_orders_fulfilled_ = count;
    }
    // Сеттер общего количества частично выполненных заказов
    void setTotalOrdersPartiallyFulfilled(int count) {
        total_orders_partially_fulfilled_ = count;
    }
    // Сеттер общего количества невыполненных заказов
    void setTotalOrdersUnfulfilled(int count) {
        total_orders_unfulfilled_ = count;
    }
    // Сеттер общей выручки
    void setTotalRevenue(double revenue) {
        total_revenue_ = revenue;
    }
    // Сеттер общих потерь от уценки
    void setTotalDiscountLoss(double loss) {
        total_discount_loss_ = loss;
    }
    // Сеттер общих потерь от списания
    void setTotalExpirationLoss(double loss) {
        total_expiration_loss_ = loss;
    }
    // Сеттер общего количества проданных товаров
    void setTotalProductsSold(int count) {
        total_products_sold_ = count;
    }
    // Сеттер общего количества уцененных товаров
    void setTotalProductsDiscounted(int count) {
        total_products_discounted_ = count;
    }
    // Сеттер общего количества списанных товаров
    void setTotalProductsExpired(int count) {
        total_products_expired_ = count;
    }
    // Сеттер общего количества созданных перевозок
    void setTotalShipmentsCreated(int count) {
        total_shipments_created_ = count;
    }
    // Сеттер общего количества заявок поставщикам
    void setTotalSupplierRequests(int count) {
        total_supplier_requests_ = count;
    }
    // Сеттер общего количества выполненных поставок
    void setTotalSupplierDeliveries(int count) {
        total_supplier_deliveries_ = count;
    }
    // Сеттер дневной выручки
    void setDailyRevenue(double revenue) {
        daily_revenue_ = revenue;
    }
    // Сеттер дневных потерь от уценки
    void setDailyDiscountLoss(double loss) {
        daily_discount_loss_ = loss;
    }
    // Сеттер дневных потерь от списания
    void setDailyExpirationLoss(double loss) {
        daily_expiration_loss_ = loss;
    }
    // Сеттер дневного количества проданных товаров
    void setDailyProductsSold(int count) {
        daily_products_sold_ = count;
    }
        
    // Метод увеличения счетчика дней работы
    void incrementTotalDays() {
        total_days_++;
    }
    // Метод увеличения счетчика обработанных заказов
    void incrementOrdersProcessed() {
        total_orders_processed_++;
    }
    // Метод увеличения счетчика полностью выполненных заказов
    void incrementOrdersFulfilled() {
        total_orders_fulfilled_++;
    }
    // Метод увеличения счетчика частично выполненных заказов
    void incrementOrdersPartiallyFulfilled() {
        total_orders_partially_fulfilled_++;
    }
    // Метод увеличения счетчика невыполненных заказов
    void incrementOrdersUnfulfilled() {
        total_orders_unfulfilled_++;
    }
    // Метод добавления выручки
    void addRevenue(double amount) {
        total_revenue_ += amount;
        daily_revenue_ += amount;
    }
    // Метод добавления потерь от уценки
    void addDiscountLoss(double loss) {
        total_discount_loss_ += loss;
        daily_discount_loss_ += loss;
    }
    // Метод добавления потерь от списания
    void addExpirationLoss(double loss) {
        total_expiration_loss_ += loss;
        daily_expiration_loss_ += loss;
    }
    // Метод добавления проданных товаров
    void addProductsSold(int count) {
        total_products_sold_ += count;
        daily_products_sold_ += count;
    }
    // Метод увеличения счетчика уцененных товаров
    void incrementProductsDiscounted() {
        total_products_discounted_++;
    }
    // Метод увеличения счетчика списанных товаров
    void incrementProductsExpired() {
        total_products_expired_++;
    }
    // Метод увеличения счетчика созданных перевозок
    void incrementShipmentsCreated() {
        total_shipments_created_++;
    }
    // Метод увеличения счетчика заявок поставщикам
    void incrementSupplierRequests() {
        total_supplier_requests_++;
    }
    // Метод увеличения счетчика выполненных поставок
    void incrementSupplierDeliveries() {
        total_supplier_deliveries_++;
    }
    
    // Метод получения процента выполнения заказов
    double getOrderFulfillmentRate() const;
    // Метод получения общих потерь
    double getTotalLosses() const;
    // Метод получения средней дневной выручки
    double getAverageDailyRevenue() const;
    // Метод получения прибыли
    double getProfit() const;
    // Метод сброса дневной статистики
    void resetDailyStatistics();
    // Метод вывода сводной статистики
    void printSummary() const;

    private:
    int total_days_; // Общее количество дней работы
    int total_orders_processed_; // Общее количество обработанных заказов
    int total_orders_fulfilled_; // Общее количество полностью выполненных заказов
    int total_orders_partially_fulfilled_; // Общее количество частично выполненных заказов
    int total_orders_unfulfilled_; // Общее количество невыполненных заказов
    double total_revenue_; // Общая выручка
    double total_discount_loss_; // Общие потери от уценки
    double total_expiration_loss_; // Общие потери от списания
    int total_products_sold_; // Общее количество проданных товаров
    int total_products_discounted_; // Общее количество уцененных товаров
    int total_products_expired_; // Общее количество списанных товаров
    int total_shipments_created_; // Общее количество созданных перевозок
    int total_supplier_requests_; // Общее количество заявок поставщикам
    int total_supplier_deliveries_; // Общее количество выполненных поставок
    double daily_revenue_; // Дневная выручка
    double daily_discount_loss_; // Дневные потери от уценки
    double daily_expiration_loss_; // Дневные потери от списания
    int daily_products_sold_; // Дневное количество проданных 
};

#endif