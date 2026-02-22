#include "transportFactory.hpp"
#include <iostream>

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