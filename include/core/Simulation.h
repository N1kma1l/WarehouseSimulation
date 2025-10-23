#ifndef SIMULATION_H
#define SIMULATION_H

// Главный класс симуляции работы склада
class Simulation {
    public:
    Simulation();
    
    // Геттер текущего дня симуляции
    int getCurrentDay() const {
        return current_day_;
    }
    // Геттер общего количества дней симуляции
    int getTotalDays() const {
        return total_days_;
    }
    // Геттер статуса выполнения симуляции
    bool isRunning() const {
        return is_running_;
    }
    // Геттер статуса паузы симуляции
    bool isPaused() const {
        return is_paused_;
    }
    // Геттер количества выполненных итераций
    int getIterationsCompleted() const {
        return iterations_completed_;
    }
    // Геттер флага автоматического режима
    bool isAutoMode() const {
        return is_auto_mode_;
    }
    // Геттер скорости симуляции (итераций в секунду)
    int getSimulationSpeed() const {
        return simulation_speed_;
    }

    // Сеттер общего количества дней симуляции
    void setTotalDays(int days) {
        total_days_ = days;
    }
    // Сеттер статуса выполнения симуляции
    void setRunning(bool running) {
        is_running_ = running;
    }
    // Сеттер статуса паузы симуляции
    void setPaused(bool paused) {
        is_paused_ = paused;
    }
    // Сеттер количества выполненных итераций
    void setIterationsCompleted(int iterations) {
        iterations_completed_ = iterations;
    }
    // Сеттер флага автоматического режима
    void setAutoMode(bool auto_mode) {
        is_auto_mode_ = auto_mode;
    }
    // Сеттер скорости симуляции (итераций в секунду)
    void setSimulationSpeed(int speed) {
        simulation_speed_ = speed;
    }

    // Метод запуска симуляции
    void start() {
        is_running_ = true;
        is_paused_ = false;
    }
    // Метод остановки симуляции
    void stop() {
        is_running_ = false;
        is_paused_ = false;
    }
    // Метод паузы симуляции
    void pause() {
        is_paused_ = true;
    }
    // Метод возобновления симуляции
    void resume() {
        is_paused_ = false;
    }
    // Метод перехода к следующему дню
    void nextDay() {
        current_day_++;
        iterations_completed_++;
    }
    // Метод сброса симуляции
    void reset() {
        current_day_ = 0;
        iterations_completed_ = 0;
        is_running_ = false;
        is_paused_ = false;
    }
    // Метод проверки завершения симуляции
    bool isFinished() const {
        return current_day_ >= total_days_;
    }
    // Метод получения оставшихся дней симуляции
    int getRemainingDays() const {
        return total_days_ - current_day_;
    }
    // Метод получения прогресса симуляции в процентах
    double getProgress() const {
        if (total_days_ == 0) return 0.0;
        return (static_cast<double>(current_day_) / total_days_) * 100.0;
    }
    
    // Метод инициализации симуляции
    void initialize();
    // Метод выполнения одного дня симуляции
    void runDay();
    // Метод выполнения полной симуляции
    void runFullSimulation();
    // Метод генерации отчета по симуляции
    void generateReport() const;
    // Метод сохранения состояния симуляции
    void saveState() const;
    // Метод загрузки состояния симуляции
    void loadState();

    private:
    int current_day_; // Текущий день симуляции
    int total_days_; // Общее количество дней симуляции
    bool is_running_; // Флаг выполнения симуляции
    bool is_paused_; // Флаг паузы симуляции
    int iterations_completed_; // Количество выполненных итераций
    bool is_auto_mode_; // Флаг автоматического режима
    int simulation_speed_; // Скорость симуляции (итераций в секунду)
};

#endif