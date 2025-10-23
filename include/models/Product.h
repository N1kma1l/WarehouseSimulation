#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <chrono>

// Класс Товаров
class Product {

    public:
    Product(int id, const std::string& name, int pack_size, int max_stock,
        double price, const std::chrono::system_clock::time_point& expDate);

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
    // Геттер текущей цены товара
    double getPrice() const;
    // Геттер количества дней до окончания срока годности Товара
    int getDaysUntilExpiration() const;
    // Геттер срока годности Товара
    int getExprationDate() const;
    // Геттер количества дней на складе Товара
    int getDaysInStock() const;
    // Геттер скидки на уцененный Товар (в процентах)
    double getDiscount() const;
    
    // Сеттер размера скидки на уценненый Товар (в процентах)
    void setDiscount(double percent);
    // Сеттер на уменьшение количества упаковок Товарм на складе
    bool reduceStock(int packs);
    // Сеттер на увеличение количества упаковок Товара на складе
    void addStock(int packs);

    // Метод определения необходимости установления уценки на Товар
    bool needsDiscount() const;
    // Метод для проверки просроченности Товара
    bool isExpired() const;
    // Метод для проверки уценен ли Товар
    bool isDiscounted() const;
    // Метод вывода вывода полной информации о Товаре
    void printInfo() const;

    protected:
    int id_; // id Товара
    std::string name_; // Название Товара
    int pack_size_; // Размер одной упаковки Товара
    int max_stock_; // Максимальное количество упаковок Товара на складе
    int current_stock_; // Текущее количество упаков Товара на складе
    double start_price_; // Начальная цена за упаковку Товара
    bool is_discounted_; // Флаг применения скидки к Товару
    double discount_; // Размер скидки на Товар в процентах
    int expiration_date_; // Срок годности Товара
};

#endif