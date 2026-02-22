#include "transport.hpp"
#include <iostream>

Transport::Transport(const std::string& name, int wheelsCount, int maxSpeed) : name_(name), 
                                                                        wheelsCount_(wheelsCount), maxSpeed_(maxSpeed)
{}

Motorcycle::Motorcycle() : Transport("Мотоцикл", 2, 200), hasSidecar_(false)
{}

void Motorcycle::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие люльки: " << (getHasSidecar() ? "Да" : "Нет") << std::endl;
}

Scooter::Scooter() : Transport("Скутер", 2, 80), hasElectricMotor_(false)
{}

void Scooter::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие электродвигателя: " << (getHasElectricMotor() ? "Да" : "Нет") << std::endl;
}

Car::Car() : Transport("Автомобиль", 4, 240), hasAirConditioning_(true), doorCount_(4)
{}

void Car::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие кондиционера: " << (getHasAirConditioning() ? "Да" : "Нет") << std::endl;
    std::cout << "Количество дверей: " << getDoorCount() << std::endl;
}

Bus::Bus() : Transport("Автобус", 6, 120), maxPassengers_(50), hasAirConditioning_(false)
{}

void Bus::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Максимальное количество пассажиров: " << getMaxPassengers() << std::endl;
    std::cout << "Наличие кондиционера: " << (getHasAirConditioning() ? "Да" : "Нет") << std::endl;
}