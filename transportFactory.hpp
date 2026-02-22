#pragma once

#include "transport.hpp"

enum class TransportType{
    Motorcycle = 1,
    Scooter,
    Car,
    Bus
};

class TransportFactory
{
    public:
        static std::unique_ptr<Transport> create(TransportType type);
};