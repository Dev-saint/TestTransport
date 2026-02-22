#pragma once

#include <string>
#include <memory>

class Transport
{
    public:
        Transport(const std::string& name, int wheelsCount, int maxSpeed);
        virtual void print() const = 0;
        virtual ~Transport() = default;

    protected:
        const std::string& getName() const{
            return name_;
        };
        int getWheels() const{
            return wheelsCount_;
        };
        int getMaxSpeed() const{
            return maxSpeed_;
        };

    private:
        std::string name_;
        int wheelsCount_;
        int maxSpeed_;
};

class Motorcycle : public Transport
{
    public:
        Motorcycle();
        void print() const override;
        bool getHasSidecar() const{
            return hasSidecar_;
        };

    private:
        bool hasSidecar_;
};

class Scooter : public Transport
{
    public:
        Scooter();
        void print() const override;
        bool getHasElectricMotor() const{
            return hasElectricMotor_;
        };

    private:
        bool hasElectricMotor_;
}; 

class Car : public Transport
{
    public:
        Car();
        void print() const override;
        bool getHasAirConditioning() const{
            return hasAirConditioning_;
        };
        int getDoorCount() const{
            return doorCount_;
        };

    private:
        bool hasAirConditioning_;
        int doorCount_;
}; 

class Bus : public Transport
{   
    public:
        Bus();
        void print() const override;
        int getMaxPassengers() const{
            return maxPassengers_;
        };
        bool getHasAirConditioning() const{
            return hasAirConditioning_;
        };

    private:
        int maxPassengers_;
        bool hasAirConditioning_;
};