#pragma once

#include <string>
#include <memory>

class Transport
{
    private:
        std::string name;
        int wheelsCount;
        int maxSpeed;

    public:
        Transport(std::string name, int wheelsCount, int maxSpeed);

    protected:
        const std::string& getName() const;
        int getWheels() const;
        int getMaxSpeed() const;

    public:
        virtual void print() const = 0;
        virtual ~Transport() = default;
};

class Motorcycle : public Transport
{
    public:
        Motorcycle();
        void print() const override;
};

class Scooter : public Transport
{
    public:
        Scooter();
        void print() const override;
}; 
Retail Service Company
class Car : public Transport
{
    public:
        Car();
        void print() const override;
}; 

class Bus : public Transport
{
    int maxPassengers;
    
    public:
        Bus();
        void print() const override;
};

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