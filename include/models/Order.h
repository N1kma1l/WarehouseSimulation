#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

// Структура, объекты которой являются одной из позиций в заказе
struct OrderItem {
    int product_id;             // ID товара
    std::string product_name;    // Название товара (для удобства вывода)
    int requested_quantity;      // Запрошенное количество
    int allocated_packs;         // Выделенное количество упаковок
    double actual_quantity;      // Фактическое количество
    double item_cost;            // Стоимость позиции
    
    OrderItem(int id, const std::string& name, int quantity);
};

// Класс заказов
class Order {
    public:
    Order(int id, int store_id);
    Order(int id, int store_d, const std::vector<OrderItem>& initial_items);
    
    // Метод добавления позиции в заказ
    void addItem(int product_id, const std::string& product_name, int quantity);
    // Метод обновления информации о товаре на складе
    void updateItemAllocation(int product_id, int allocated_packs, double actual_quantity, double cost);
    // Метод для подсчета общей стоимости заказа
    void calculateTotalCost();
    
    // Метод для получения списка заказанных товаров
    const std::vector<OrderItem>& getItems() const { 
        return items_;
    }
    // Метод для получения id торговой точки, оформившей заказ
    int getStoreId() const {
        return store_id_;
    }
    // Метод для получения id заказа
    int getId() const {
        return order_id_;
    }
    // Метод для проверки обработан ли заказ
    bool getIsProcessed() const {
        return is_processed_;
    }
    // Метод для получения общей стоимости заказа
    double getTotalCost() const {
        return total_cost_;
    }
    // Метод для получения количества позиций в заказе
    int getItemCount() const {
        return items_.size();
    }
    
    
    // Метод для проверки пустой ли заказ
    bool isEmpty() const {
        return items_.empty();
    }
    // Метод для проверки хотя бы частичного выделения товаров на каждую позицию заказа
    bool isFullyAllocated() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Order& order);

    private:
    int order_id_;                        // Уникальный номер заказа
    int store_id_;                        // id торговой точки
    std::vector<OrderItem> items_;        // Список товаров в заказе
    bool is_processed_;                   // Обработан ли заказ
    double total_cost_;                   // Общая стоимость заказа

};

#endif