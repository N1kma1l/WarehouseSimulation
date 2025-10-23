#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// Класс Товаров
class Product {

    public:
    Product(int id, const std::string& name, int pack_size, 
        int max_stock, double price, int expiration_date,
        int arrival_day);

    // Геттер id Товара
    int getId() const {
        return id_;
    }
    // Геттер названия Товара
    const std::string& getName() const {
        return name_;
    }
    // Геттер размера упаковки Товара
    int getPackSize() const {
        return pack_size_;
    }
    // Геттер максимального количества упаковок Товара на складе
    int getMaxStock() const {
        return max_stock_;
    }
    // Геттер текущего количества упаковок Товара на складе
    int getCurrentStock() const {
        return current_stock_;
    }
    // Геттер старотовой цены Товара
    double getStartPrice() const {
        return start_price_;
    }
    // Геттер скидки на уцененный Товар (в процентах)
    double getDiscount() const {
        return discount_;
    }
    // Геттер срока годности Товара
    int getExpirationDate() const {
        return expiration_date_;
    }
    // Геттер даты поступления Товара
    int getArrivalDate() const {
        return arrival_day_;
    }
    // Геттер текущей цены товара
    double getPrice() const;
    // Геттер количества дней до окончания срока годности Товара
    int getDaysUntilExpiration(const int now_date) const;
    // Геттер количества дней на складе Товара
    int getDaysInStock(const int now_date) const;
    
    // Сеттер размера скидки на уценненый Товар (в процентах)
    void setDiscount(double percent);
    // Сеттер на уменьшение количества упаковок Товарм на складе
    bool reduceStock(int packs);
    // Сеттер на увеличение количества упаковок Товара на складе
    void addStock(int packs);

    // Метод определения необходимости установления уценки на Товар
    bool needsDiscount(const int now_date) const;
    // Метод для проверки просроченности Товара
    bool isExpired(const int now_date) const;
    // Метод для проверки уценен ли Товар
    bool isDiscounted() const;

    friend std::ostream& operator<<(std::ostream& os, const Product& product);

    protected:
    int id_; // id Товара
    std::string name_; // Название Товара
    int pack_size_; // Размер одной упаковки Товара
    int max_stock_; // Максимальное количество упаковок Товара на складе
    int current_stock_; // Текущее количество упаков Товара на складе
    double start_price_; // Начальная цена за упаковку Товара
    bool is_discounted_; // Флаг применения скидки к Товару
    double discount_; // Размер скидки на Товар в процентах
    int expiration_date_; // Срок годности Товара в днях
    int arrival_day_; // День поступления Товара на склад
};

#endif