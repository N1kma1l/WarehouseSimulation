#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "models/Store.h"
#include "models/Product.h"
#include "models/Supplier.h"

#include <vector>
#include <memory>
#include <string>

class Store;
class Product;
class Supplier;

// Класс для управления всеми данными системы
class DataManager {
    public:
    DataManager();
    
    // Геттер количества магазинов
    int getStoresCount() const {
        return stores_.size();
    }
    // Геттер количества товаров
    int getProductsCount() const {
        return products_.size();
    }
    // Геттер количества поставщиков
    int getSuppliersCount() const {
        return suppliers_.size();
    }
    // Геттер общего количества объектов
    int getTotalObjectsCount() const {
        return getStoresCount() + getProductsCount() + getSuppliersCount();
    }
    // Геттер флага инициализации данных
    bool isDataInitialized() const {
        return is_data_initialized_;
    }
    // Геттер ссылки на вектор магазинов
    const std::vector<Store>& getStores() const {
        return stores_;
    }
    // Геттер ссылки на вектор товаров
    const std::vector<Product>& getProducts() const {
        return products_;
    }
    // Геттер ссылки на вектор поставщиков
    const std::vector<Supplier>& getSuppliers() const {
        return suppliers_;
    }
    
    // Сеттер флага инициализации данных
    void setDataInitialized(bool initialized) {
        is_data_initialized_ = initialized;
    }
    
    // Метод проверки валидности данных
    bool isValid() const {
        return getStoresCount() > 0 && getProductsCount() > 0 && getSuppliersCount() > 0;
    }
    // Метод проверки достаточности данных для симуляции
    bool hasEnoughData() const {
        return getStoresCount() >= 3 && getProductsCount() >= 12 && getSuppliersCount() >= 2;
    }

    // Метод получения описания состояния данных
    std::string getDataStatus() const;
    // Метод инициализации тестовых данных
    void initializeTestData();
    // Метод очистки всех данных
    void clearAllData();
    // Метод генерации случайных магазинов
    void generateStores();
    // Метод генерации случайных товаров
    void generateProducts();
    // Метод генерации случайных поставщиков
    void generateSuppliers();
    // Метод валидации всех данных
    bool validateData() const;
    // Метод вывода сводки по данным
    void printDataSummary() const;
    // Метод поиска магазина по ID

    Store* getStoreById(int id);
    // Метод поиска товара по ID
    Product* getProductById(int id);
    // Метод поиска поставщика по ID
    Supplier* getSupplierById(int id);
    // Метод добавления магазина
    void addStore(const Store& store);
    // Метод добавления товара
    void addProduct(const Product& product);
    // Метод добавления поставщика
    void addSupplier(const Supplier& supplier);

    private:
    std::vector<Store> stores_; // Вектор магазинов
    std::vector<Product> products_; // Вектор товаров
    std::vector<Supplier> suppliers_; // Вектор поставщиков
    bool is_data_initialized_; // Флаг инициализации данных
};

#endif