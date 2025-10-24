#include "core/DataManager.h"
#include "models/Store.h"
#include "models/Product.h"
#include "models/Supplier.h"
#include <iostream>

// Конструктор по умолчанию
DataManager::DataManager() :
    is_data_initialized_(false) {}

// Метод получения описания состояния данных
std::string DataManager::getDataStatus() const {
    if (!is_data_initialized_) {
        return "Данные не инициализированы";
    }
    
    std::string status = "Данные готовы: ";
    status += std::to_string(getStoresCount()) + " магазинов, ";
    status += std::to_string(getProductsCount()) + " товаров, ";
    status += std::to_string(getSuppliersCount()) + " поставщиков";
    
    return status;
}

// Метод инициализации тестовых данных
void DataManager::initializeTestData() {
    std::cout << "Инициализация тестовых данных..." << std::endl;
    
    clearAllData();
    
    // Генерируем данные
    generateStores();
    generateProducts();
    generateSuppliers();
    
    is_data_initialized_ = true;
    std::cout << "Тестовые данные успешно инициализированы" << std::endl;
}

// Метод очистки всех данных
void DataManager::clearAllData() {
    stores_.clear();
    products_.clear();
    suppliers_.clear();
    is_data_initialized_ = false;
    std::cout << "Все данные очищены" << std::endl;
}

// Метод генерации случайных магазинов
void DataManager::generateStores() {
    std::cout << "Генерация магазинов..." << std::endl;
    
    // Создаем тестовые магазины
    stores_.emplace_back(1, "Супермаркет 'Центральный'");
    stores_.emplace_back(2, "Магазин 'Северный'");
    stores_.emplace_back(3, "Торговая точка 'Восточная'");
    stores_.emplace_back(4, "Универмаг 'Западный'");
    stores_.emplace_back(5, "Мини-маркет 'Южный'");
    
    // Добавляем начальные запасы для тестирования
    for (auto& store : stores_) {
        store.setBaseOrderProbability(0.7);
        store.setDiscountedProductProbability(0.6);
        store.setMinOrderItems(1);
        store.setMaxOrderItems(5);
    }
    
    std::cout << "Создано магазинов: " << stores_.size() << std::endl;
}

// Метод генерации случайных товаров
void DataManager::generateProducts() {
    std::cout << "Генерация товаров..." << std::endl;
    
    // Создаем тестовые товары с начальными запасами
    std::string name1 = "Рис";
    products_.emplace_back(1, name1, 20, 200, 800.0, 180, 0);
    products_.back().addStock(50);
    
    std::string name2 = "Макароны";
    products_.emplace_back(2, name2, 10, 150, 450.0, 365, 0);
    products_.back().addStock(40);
    
    std::string name3 = "Мука";
    products_.emplace_back(3, name3, 25, 100, 600.0, 90, 0);
    products_.back().addStock(30);
    
    std::string name4 = "Сахар";
    products_.emplace_back(4, name4, 15, 180, 550.0, 730, 0);
    products_.back().addStock(60);
    
    std::string name5 = "Соль";
    products_.emplace_back(5, name5, 5, 300, 200.0, 1095, 0);
    products_.back().addStock(80);
    
    std::string name6 = "Чай";
    products_.emplace_back(6, name6, 8, 120, 1200.0, 540, 0);
    products_.back().addStock(25);
    
    std::string name7 = "Кофе";
    products_.emplace_back(7, name7, 12, 80, 2500.0, 365, 0);
    products_.back().addStock(20);
    
    std::string name8 = "Молоко";
    products_.emplace_back(8, name8, 6, 250, 400.0, 14, 0);
    products_.back().addStock(35);
    
    std::string name9 = "Хлеб";
    products_.emplace_back(9, name9, 4, 200, 300.0, 7, 0);
    products_.back().addStock(45);
    
    std::string name10 = "Масло";
    products_.emplace_back(10, name10, 8, 100, 900.0, 30, 0);
    products_.back().addStock(15);
    
    std::string name11 = "Сыр";
    products_.emplace_back(11, name11, 3, 120, 1500.0, 21, 0);
    products_.back().addStock(20);
    
    std::string name12 = "Колбаса";
    products_.emplace_back(12, name12, 2, 150, 1200.0, 14, 0);
    products_.back().addStock(25);
    
    std::string name13 = "Консервы";
    products_.emplace_back(13, name13, 30, 90, 700.0, 730, 0);
    products_.back().addStock(40);
    
    std::string name14 = "Печенье";
    products_.emplace_back(14, name14, 5, 180, 350.0, 60, 0);
    products_.back().addStock(55);
    
    std::string name15 = "Шоколад";
    products_.emplace_back(15, name15, 8, 160, 450.0, 180, 0);
    products_.back().addStock(30);
    
    std::cout << "Создано товаров: " << products_.size() << std::endl;
}

// Метод генерации случайных поставщиков
void DataManager::generateSuppliers() {
    std::cout << "Генерация поставщиков..." << std::endl;
    
    // Создаем тестовых поставщиков
    suppliers_.emplace_back(1, "ООО 'ПродуктСнаб'", "тел: 111-222");
    suppliers_.emplace_back(2, "ЗАО 'АгроТрейд'", "тел: 333-444");
    suppliers_.emplace_back(3, "ИП 'Смирнов'", "тел: 555-666");
    
    std::cout << "Создано поставщиков: " << suppliers_.size() << std::endl;
}

// Метод валидации всех данных
bool DataManager::validateData() const {
    if (!is_data_initialized_) {
        std::cout << "Ошибка: данные не инициализированы" << std::endl;
        return false;
    }
    
    if (getStoresCount() < 3) {
        std::cout << "Ошибка: недостаточно магазинов (" << getStoresCount() << ")" << std::endl;
        return false;
    }
    
    if (getProductsCount() < 12) {
        std::cout << "Ошибка: недостаточно товаров (" << getProductsCount() << ")" << std::endl;
        return false;
    }
    
    if (getSuppliersCount() < 2) {
        std::cout << "Ошибка: недостаточно поставщиков (" << getSuppliersCount() << ")" << std::endl;
        return false;
    }
    
    std::cout << "Данные прошли валидацию успешно" << std::endl;
    return true;
}

// Метод вывода сводки по данным
void DataManager::printDataSummary() const {
    std::cout << "=== СВОДКА ДАННЫХ ===" << std::endl;
    std::cout << "Магазины: " << getStoresCount() << std::endl;
    std::cout << "Товары: " << getProductsCount() << std::endl;
    std::cout << "Поставщики: " << getSuppliersCount() << std::endl;
    std::cout << "Всего объектов: " << getTotalObjectsCount() << std::endl;
    std::cout << "Статус: " << (is_data_initialized_ ? "ИНИЦИАЛИЗИРОВАНЫ" : "НЕ ИНИЦИАЛИЗИРОВАНЫ") << std::endl;
    std::cout << "Валидность: " << (isValid() ? "ДА" : "НЕТ") << std::endl;
    std::cout << "Достаточность: " << (hasEnoughData() ? "ДА" : "НЕТ") << std::endl;
}

// Метод поиска магазина по ID
Store* DataManager::getStoreById(int id) {
    for (auto& store : stores_) {
        if (store.getId() == id) {
            return &store;
        }
    }
    return nullptr;
}

// Метод поиска товара по ID
Product* DataManager::getProductById(int id) {
    for (auto& product : products_) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

// Метод поиска поставщика по ID
Supplier* DataManager::getSupplierById(int id) {
    for (auto& supplier : suppliers_) {
        if (supplier.getId() == id) {
            return &supplier;
        }
    }
    return nullptr;
}

// Метод добавления магазина
void DataManager::addStore(const Store& store) {
    stores_.push_back(store);
}

// Метод добавления товара
void DataManager::addProduct(const Product& product) {
    products_.push_back(product);
}

// Метод добавления поставщика
void DataManager::addSupplier(const Supplier& supplier) {
    suppliers_.push_back(supplier);
}