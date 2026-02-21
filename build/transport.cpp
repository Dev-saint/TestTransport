#include "transport.h"
#include <iostream>

Transport::Transport(std::string name, int wheelsCount, int maxSpeed) : name(std::move(name)), 
                                                                        wheelsCount(wheelsCount), maxSpeed(maxSpeed)
{}

const std::string& Transport::getName() const{
    return name;
}

int Transport::getWheels() const{
    return wheelsCount;
}

int Transport::getMaxSpeed() const{
    return maxSpeed;
}

Motorcycle::Motorcycle() : Transport("Мотоцикл", 2, 200), hasSidecar(false)
{}

bool Motorcycle::getHasSidecar() const{
    return hasSidecar;
}

void Motorcycle::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие люльки: " << (getHasSidecar() ? "Да" : "Нет") << std::endl;
}

Scooter::Scooter() : Transport("Скутер", 2, 80), hasElectricMotor(false)
{}

bool Scooter::getHasElectricMotor() const{
    return hasElectricMotor;
}

void Scooter::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие электродвигателя: " << (getHasElectricMotor() ? "Да" : "Нет") << std::endl;
}

Car::Car() : Transport("Автомобиль", 4, 240), hasAirConditioning(true), doorCount(4)
{}

bool Car::getHasAirConditioning() const{
    return hasAirConditioning;
}

int Car::getDoorCount() const{
    return doorCount;
}

void Car::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Наличие кондиционера: " << (getHasAirConditioning() ? "Да" : "Нет") << std::endl;
    std::cout << "Количество дверей: " << getDoorCount() << std::endl;
}

Bus::Bus() : Transport("Автобус", 6, 120), maxPassengers(50), hasAirConditioning(false)
{}

bool Bus::getHasAirConditioning() const{
    return hasAirConditioning;
}

int Bus::getMaxPassengers() const{
    return maxPassengers;
}

void Bus::print() const{
    std::cout << "Наименование транспорта: " << getName() << std::endl;
    std::cout << "Количество колес: " << getWheels() << std::endl;
    std::cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << std::endl;
    std::cout << "Максимальное количество пассажиров: " << getMaxPassengers() << std::endl;
    std::cout << "Наличие кондиционера: " << (getHasAirConditioning() ? "Да" : "Нет") << std::endl;
}

std::unique_ptr<Transport> TransportFactory::create(TransportType type){
    switch (type) {
        case TransportType::Motorcycle:
            return std::make_unique<Motorcycle>();
        case TransportType::Scooter:
            return std::make_unique<Scooter>();
        case TransportType::Car:
            return std::make_unique<Car>();
        case TransportType::Bus:
            return std::make_unique<Bus>();
        default:
            throw std::invalid_argument("НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА");
    }
}