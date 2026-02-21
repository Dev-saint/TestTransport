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
    private:
        bool hasSidecar;
    public:
        Motorcycle();
        void print() const override;
        bool getHasSidecar() const;
};

class Scooter : public Transport
{
    private:
        bool hasElectricMotor;
    public:
        Scooter();
        void print() const override;
        bool getHasElectricMotor() const;
}; 

class Car : public Transport
{
    private:
        bool hasAirConditioning;
        int doorCount;
    public:
        Car();
        void print() const override;
        bool getHasAirConditioning() const;
        int getDoorCount() const;
}; 

class Bus : public Transport
{
    private:
        int maxPassengers;
        bool hasAirConditioning;
    
    public:
        Bus();
        void print() const override;
        int getMaxPassengers() const;
        bool getHasAirConditioning() const;
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