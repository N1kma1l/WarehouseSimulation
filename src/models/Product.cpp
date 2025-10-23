#include "Product.h"

#include <iostream>
#include <iomanip>

Product::Product(int id, std::string& name, int pack_size, 
        int max_stock, double price, int expiration_date,
        int arrival_day) : 
        id_(id), name_(name), pack_size_(pack_size), max_stock_(max_stock),
        current_stock_(0), start_price_(price), is_discounted_(false), discount_(0),
        expiration_date_(expiration_date), arrival_day_(arrival_day) {}

double Product::getPrice() const {
    double price = start_price_;

    if (is_discounted_) {
        price *= (1.0 - discount_ / 100.0);
    }

    return price;
}

int Product::getDaysUntilExpiration(const int now_date) const {
    return getExpirationDate() - getDaysInStock(now_date);
}

int Product::getDaysInStock(const int now_date) const {
    return now_date - getArrivalDate();
}

void Product::setDiscount(double percent) {
    discount_ = percent;
    is_discounted_ = true;
}

bool Product::reduceStock(int packs) {
    if (packs <= current_stock_ && packs > 0) {
        current_stock_ -= packs;
        return true;
    }
    return false;
}

void Product::addStock(int packs) {
    if (packs > 0) {
        current_stock_ = std::min(current_stock_ + packs, max_stock_);
    }
}

bool Product::needsDiscount(const int now_date) const {
    int days_left = getDaysUntilExpiration(now_date);
    return days_left <= 3 && !isExpired(now_date) && !isDiscounted();
}

bool Product::isExpired(const int now_date) const {
    return getDaysUntilExpiration(now_date) > 0;
}

bool Product::isDiscounted() const {
    return is_discounted_;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    // Сохраняем оригинальные настройки потока
    
    os << "Товар #" << product.id_ << " \"" << product.name_ << "\"" << std::endl;
    os << "  Упаковка: " << product.pack_size_ << " ед." << std::endl;
    os << "  Запас: " << product.current_stock_ << "/" << product.max_stock_ << " уп." << std::endl;
    os << "  Цена: " << std::fixed << std::setprecision(2) << product.getPrice() 
       << " руб./уп. (базовая: " << product.start_price_ << " руб.)" << std::endl;
    
    if (product.is_discounted_) {
        os << "  УЦЕНКА: " << product.discount_ << "%" << std::endl;
    }
    
    os << "  Срок годности: " << product.expiration_date_ << " дней" << std::endl;
    os << "  Поступил: день " << product.arrival_day_ << std::endl;
    return os;
}