#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <memory>

// Класс главного склада
class Warehouse {
    public:
    Warehouse();
    
    // Геттер общего количества товаров на складе
    int getTotalProductsCount() const {
        return total_products_count_;
    }    
    // Геттер общей вместимости склада
    int getTotalCapacity() const {
        return total_capacity_;
    }    
    // Геттер текущей загруженности склада (в процентах)
    double getOccupancyRate() const {
        if (total_capacity_ == 0) return 0.0;
        return (static_cast<double>(total_products_count_) / total_capacity_) * 100.0;
    }
    // Геттер общего объема продаж
    double getTotalSales() const {
        return total_sales_;
    }    
    // Геттер общих потерь от уценки
    double getTotalDiscountLosses() const {
        return total_discount_losses_;
    }    
    // Геттер общих потерь от списания
    double getTotalExpirationLosses() const {
        return total_expiration_losses_;
    }

    // Сеттер общего количества товаров на складе
    void setTotalProductsCount(int count) {
        total_products_count_ = count;
    }
    // Сеттер общей вместимости склада
    void setTotalCapacity(int capacity) {
        total_capacity_ = capacity;
    }
    // Сеттер общего объема продаж
    void setTotalSales(double sales) {
        total_sales_ = sales;
    }
    // Сеттер общих потерь от уценки
    void setTotalDiscountLosses(double losses) {
        total_discount_losses_ = losses;
    }
    // Сеттер общих потерь от списания
    void setTotalExpirationLosses(double losses) {
        total_expiration_losses_ = losses;
    }

    // Метод добавления продажи
    void addSale(double amount) {
        total_sales_ += amount;
    }
    // Метод добавления потерь от уценки
    void addDiscountLoss(double loss) {
        total_discount_losses_ += loss;
    }
    // Метод добавления потерь от списания
    void addExpirationLoss(double loss) {
        total_expiration_losses_ += loss;
    }
    // Метод обновления количества товаров
    void updateProductsCount(int change) {
        total_products_count_ += change;
    }
    // Метод проверки перегруженности склада
    bool isOverloaded() const {
        return getOccupancyRate() > 90.0;
    }
    // Метод проверки недогруженности склада
    bool isUnderloaded() const {
        return getOccupancyRate() < 20.0;
    }




    private:
    int total_products_count_; // Общее количество товаров на складе
    int total_capacity_; // Общая вместимость склада
    double total_sales_; // Общий объем продаж
    double total_discount_losses_; // Общие потери от уценки
    double total_expiration_losses_; // Общие потери от списания
};

#endif