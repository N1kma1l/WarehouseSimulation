#include "core/Simulation.h"
#include <iostream>

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
    std::cout << "Симуляция инициализирована. Дней: " << total_days_ << std::endl;
}

void Simulation::runDay() {
    if (!is_running_ || is_paused_ || isFinished()) {
        return;
    }
    
    std::cout << "=== День " << current_day_ << " ===" << std::endl;
    
    nextDay();
    
    if (isFinished()) {
        std::cout << "Симуляция завершена!" << std::endl;
        generateReport();
    }
}

void Simulation::runFullSimulation() {
    start();
    std::cout << "Запуск полной симуляции на " << total_days_ << " дней..." << std::endl;
    
    while (!isFinished() && is_running_) {
        runDay();
        
        if (simulation_speed_ > 0) {
        }
    }
    
    stop();
}

void Simulation::generateReport() const {
    std::cout << "\n=== ОТЧЕТ ПО СИМУЛЯЦИИ ===" << std::endl;
    std::cout << "Продолжительность: " << total_days_ << " дней" << std::endl;
    std::cout << "Выполнено итераций: " << iterations_completed_ << std::endl;
    std::cout << "Прогресс: " << getProgress() << "%" << std::endl;
    std::cout << "Режим: " << (is_auto_mode_ ? "АВТОМАТИЧЕСКИЙ" : "РУЧНОЙ") << std::endl;
}

void Simulation::saveState() const {
    std::cout << "Состояние симуляции сохранено (день " << current_day_ << ")" << std::endl;
}

void Simulation::loadState() {
    std::cout << "Состояние симуляции загружено" << std::endl;
}