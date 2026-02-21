#include "transport.h"
#include <iostream>

Transport::Transport(std::string name, int wheelsCount, int maxSpeed) : name(std::move(name)), wheelsCount(wheelsCount)
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

void Transport::print() const{
    std::cout << "Наименование транспорта: " << name
            << "Количество колес: " << wheelsCount
            << "Максимальная скорость: " << maxSpeed << std::endl;
}