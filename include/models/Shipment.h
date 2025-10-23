#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include <vector>

// Структура позиции в перевозке
struct ShipmentItem {
    int product_id;             // id товара
    std::string product_name;   // Название товара
    int packs_count;            // Количество упаковок
    double total_quantity;      // Общее количество товара
    double total_cost;          // Общая стоимость позиции
    
    ShipmentItem(int id, const std::string& name, int packs, double quantity, double cost);
};

// Класс перевозки товаров в торговую точку
class Shipment {
    public:
    Shipment(int id, int store_id, int day);
    
    // Геттер id перевозки
    int getId() const {
        return shipment_id_;
    }
    // Геттер id магазина-получателя
    int getStoreId() const {
        return store_id_;
    }
    // Геттер дня перевозки
    int getShipmentDay() const {
        return shipment_day_;
    }
    // Геттер общего количества упаковок в перевозке
    int getTotalPacks() const {
        return total_packs_;
    }
    // Геттер общей стоимости перевозки
    double getTotalCost() const {
        return total_cost_;
    }
    // Геттер статуса выполнения перевозки
    bool isCompleted() const {
        return is_completed_;
    }
    
    // Метод добавления товара в перевозку
    void addItem(int product_id, const std::string& product_name, int packs, double quantity, double cost);
    // Метод отметки перевозки как выполненной
    void markAsCompleted() {
        is_completed_ = true;
    }
    // Метод получения количества позиций в перевозке
    int getItemsCount() const {
        return items_.size();
    }
    // Метод проверки пуста ли перевозка
    bool isEmpty() const {
        return items_.empty();
    }

    private:
    int shipment_id_; // id перевозки
    int store_id_; // id магазина-получателя
    int shipment_day_; // День выполнения перевозки
    std::vector<ShipmentItem> items_; // Список товаров в перевозке
    int total_packs_; // Общее количество упаковок
    double total_cost_; // Общая стоимость перевозки
    bool is_completed_; // Выполнена ли перевозка
};

#endif