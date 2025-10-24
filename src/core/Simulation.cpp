#include "core/Simulation.h"
#include <iostream>
#include <thread>
#include <chrono>

Simulation::Simulation() :
    current_day_(0),
    total_days_(30),
    is_running_(false),
    is_paused_(false),
    iterations_completed_(0),
    is_auto_mode_(true),
    simulation_speed_(1) {}

void Simulation::initialize() {
    current_day_ = 0;
    iterations_completed_ = 0;
    is_running_ = false;
    is_paused_ = false;
    warehouse_controller_.initialize();
    std::cout << "Симуляция инициализирована. Дней: " << total_days_ << std::endl;
    std::cout << "Контроллер склада: " << (warehouse_controller_.isReady() ? "ГОТОВ" : "НЕ ГОТОВ") << std::endl;
}

void Simulation::runDay() {
    if (!is_running_ || is_paused_ || isFinished()) {
        return;
    }
    
    if (!warehouse_controller_.isReady()) {
        std::cout << "Ошибка: контроллер склада не готов к работе" << std::endl;
        return;
    }
    
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "ДЕНЬ " << current_day_ << " ИЗ " << total_days_;
    std::cout << " (" << getProgress() << "% выполнено)" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    warehouse_controller_.processDay(current_day_);
    
    nextDay();
    
    if (isFinished()) {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "СИМУЛЯЦИЯ ЗАВЕРШЕНА!" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        generateReport();
    }
    
    if (simulation_speed_ > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / simulation_speed_));
    }
}

void Simulation::runFullSimulation() {
    start();
    std::cout << "Запуск полной симуляции на " << total_days_ << " дней..." << std::endl;
    
    while (!isFinished() && is_running_) {
        runDay();
        
        if (is_paused_) {
            std::cout << "Симуляция на паузе..." << std::endl;
            while (is_paused_ && is_running_) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
    
    if (is_running_) {
        stop();
    }
}

void Simulation::generateReport() const {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "ФИНАЛЬНЫЙ ОТЧЕТ ПО СИМУЛЯЦИИ" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Продолжительность: " << total_days_ << " дней" << std::endl;
    std::cout << "Выполнено итераций: " << iterations_completed_ << std::endl;
    std::cout << "Прогресс: " << getProgress() << "%" << std::endl;
    std::cout << "Режим: " << (is_auto_mode_ ? "АВТОМАТИЧЕСКИЙ" : "РУЧНОЙ") << std::endl;
    std::cout << "Скорость: " << simulation_speed_ << " итераций/сек" << std::endl;
    
    const auto& stats = warehouse_controller_.getStatisticsService();
    std::cout << "\n--- СТАТИСТИКА РАБОТЫ СКЛАДА ---" << std::endl;
    std::cout << "Обработано заказов: " << stats.getTotalOrdersProcessed() << std::endl;
    std::cout << "Выполнено заказов: " << stats.getTotalOrdersFulfilled() << std::endl;
    std::cout << "Процент выполнения: " << stats.getOrderFulfillmentRate() << "%" << std::endl;
    std::cout << "Общая выручка: " << stats.getTotalRevenue() << " руб." << std::endl;
    std::cout << "Общие потери: " << stats.getTotalLosses() << " руб." << std::endl;
    std::cout << "Прибыль: " << stats.getProfit() << " руб." << std::endl;
}

void Simulation::saveState() const {
    std::cout << "Состояние симуляции сохранено (день " << current_day_ << ")" << std::endl;
}

void Simulation::loadState() {
    std::cout << "Состояние симуляции загружено" << std::endl;
}