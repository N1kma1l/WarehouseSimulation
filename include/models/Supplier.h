#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

// Класс поставщика товаров
class Supplier {
    public:
    Supplier(int id, const std::string& name, const std::string& contact_info);
    
    // Геттер id поставщика
    int getId() const {
        return id_;
    }
    // Геттер названия поставщика
    const std::string& getName() const {
        return name_;
    }
    // Геттер контактной информации
    const std::string& getContactInfo() const {
        return contact_info_;
    }
    // Геттер минимального времени доставки
    int getMinDeliveryDays() const {
        return min_delivery_days_;
    }
    // Геттер максимального времени доставки
    int getMaxDeliveryDays() const {
        return max_delivery_days_;
    }    
    // Геттер надежности поставщика (0.0 - 1.0)
    double getReliability() const {
        return reliability_;
    }

    // Сеттер минимального времени доставки
    void setMinDeliveryDays(int days) {
        min_delivery_days_ = days;
    }
    // Сеттер максимального времени доставки
    void setMaxDeliveryDays(int days) {
        max_delivery_days_ = days;
    }
    // Сеттер надежности поставщика
    void setReliability(double reliability) {
        reliability_ = reliability;
    }

    // Метод для расчета времени доставки для конкретного заказа
    int calculateDeliveryTime() const;
    // Метод для проверки надежности поставщика
    bool isReliable() const {
        return reliability_ >= 0.7;
    }

    private:
    int id_; // id поставщика
    std::string name_; // Название поставщика
    std::string contact_info_; // Контактная информация
    
    int min_delivery_days_; // Минимальное время доставки
    int max_delivery_days_; // Максимальное время доставки
    double reliability_; // Надежность поставщика (0.0 - 1.0)
};

#endif