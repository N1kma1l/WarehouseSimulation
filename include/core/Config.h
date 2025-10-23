#ifndef CONFIG_H
#define CONFIG_H

#include <string>

// Класс конфигурации системы склада
class Config {
    public:
    Config();
    
    // Геттер количества дней моделирования
    int getSimulationDays() const {
        return simulation_days_;
    }
    // Геттер количества торговых точек
    int getStoreCount() const {
        return store_count_;
    }    
    // Геттер количества видов товаров
    int getProductTypesCount() const {
        return product_types_count_;
    }    
    // Геттер текущего дня симуляции
    int getCurrentDay() const {
        return current_day_;
    }    
    // Геттер минимального времени поставки
    int getMinDeliveryDays() const {
        return min_delivery_days_;
    }
    // Геттер максимального времени поставки
    int getMaxDeliveryDays() const {
        return max_delivery_days_;
    }
    // Геттер порога для создания заявки поставщику
    int getRestockThreshold() const {
        return restock_threshold_;
    }    
    // Геттер дней до уценки
    int getDiscountDaysBeforeExpiration() const {
        return discount_days_before_expiration_;
    }
    
    // Сеттер количества дней моделирования
    void setSimulationDays(int days) {
        simulation_days_ = days;
    }
    // Сеттер количества торговых точек
    void setStoreCount(int count) {
        store_count_ = count;
    }
    // Сеттер количества видов товаров
    void setProductTypesCount(int count) {
        product_types_count_ = count;
    }
    // Сеттер текущего дня симуляции
    void setCurrentDay(int day) {
        current_day_ = day;
    }
    // Сеттер порога для создания заявки поставщику
    void setRestockThreshold(int threshold) {
        restock_threshold_ = threshold;
    }
    // Сеттер дней до уценки
    void setDiscountDaysBeforeExpiration(int days) {
        discount_days_before_expiration_ = days;
    }

    // Метод перехода к следующему дню
    void nextDay() {
        current_day_++;
    }
    // Метод проверки завершения симуляции
    bool isSimulationFinished() const {
        return current_day_ >= simulation_days_;
    }

    private:
    int simulation_days_; // Количество дней моделирования
    int store_count_; // Количество торговых точек
    int product_types_count_; // Количество видов товаров
    int current_day_; // Текущий день симуляции
    
    int min_delivery_days_ = 1; // Минимальное время поставки
    int max_delivery_days_ = 5; // Максимальное время поставки
    int restock_threshold_ = 3; // Порог для заказа у поставщика
    int discount_days_before_expiration_ = 3; // За сколько дней до истечения срока делать уценку
};

#endif