#include <iostream>
#include <string>

class Transport {
protected:
    std::string name;
    double maxSpeed;

public:
    Transport(const std::string& transportName, double speed)
        : name(transportName), maxSpeed(speed) {}

    virtual ~Transport() = default;

    void showGeneralInfo() const {
        std::cout << "Транспортний засіб: " << name << ", Макс. швидкість: " << maxSpeed << " км/год. ";
    }

    virtual void move() const {
        std::cout << name << " пересувається якимось чином." << std::endl;
    }
};

class Car : public Transport {
private:
    int fuelCapacity;

public:
    Car(const std::string& transportName, double speed, int fuel)
        : Transport(transportName, speed), fuelCapacity(fuel) {}

    void move() const override {
        std::cout << name << " їде дорогою на чотирьох колесах. (Об'єм бака: " << fuelCapacity << " л)" << std::endl;
    }
};

class Airplane : public Transport {
private:
    double maxAltitude;

public:
    Airplane(const std::string& transportName, double speed, double altitude)
        : Transport(transportName, speed), maxAltitude(altitude) {}

    void move() const override {
        std::cout << name << " летить у повітрі крізь хмари. (Макс. висота: " << maxAltitude << " м)" << std::endl;
    }
};

class Ship : public Transport {
private:
    double displacement;

public:
    Ship(const std::string& transportName, double speed, double disp)
        : Transport(transportName, speed), displacement(disp) {}

    void move() const override {
        std::cout << name << " пливе по воді, розсікаючи хвилі. (Водотоннажність: " << displacement << " т)" << std::endl;
    }
};

int main() {
    std::setlocale(LC_ALL, "uk_UA.UTF-8");

    Car myCar("Audi R8", 320, 73);
    Airplane myAirplane("Boeing 747", 920, 13000);
    Ship myShip("Titan Explorer", 45, 55000);

    Transport* transportPtr = nullptr;
    
    transportPtr = &myCar;
    transportPtr->showGeneralInfo();
    transportPtr->move();

    transportPtr = &myAirplane;
    transportPtr->showGeneralInfo();
    transportPtr->move();

    transportPtr = &myShip;
    transportPtr->showGeneralInfo();
    transportPtr->move();

    return 0;
}
