#include <iostream>

using namespace std;


class Engine
{
private:
    string engineType;

public:
    Engine(string type)
    {
        engineType = type;
    }

    void start()
    {
        cout << "Engine Type: " << engineType << " started." << "\n";
    }
};


// Parent Class
// Encapsulation

class Vehicle
{
private:
    string brand;

public:
    Vehicle(string b)
    {
        brand = b;
    }

    void setBrand(string b)
    {
        brand = b;
    }

    string getBrand()
    {
        return brand;
    }

    virtual void move()
    {
        cout << brand << " vehicle is moving." << "\n";
    }
};

\
// Child Class
// Inheritance

class Car : public Vehicle
{
private:
    int doors;
    Engine engine;     // Aggregation (Has-A relationship)

public:
    Car(string brand, int d, string engineType)
        : Vehicle(brand), engine(engineType)
    {
        doors = d;
    }

    void move() override     // Polymorphism
    {
        engine.start();
        cout << getBrand() << " car with "
             << doors << " doors is driving." << "\n";
    }
};


// Another Child Class
// Inheritance + Polymorphism

class Bike : public Vehicle
{
public:
    Bike(string brand)
        : Vehicle(brand)
    {
    }

    void move() override
    {
        cout << getBrand()
             << " bike is riding." << "\n";
    }
};

// =======================
// Main Function
// =======================
int main()
{
    // Object Instantiation
    Car car1("Toyota", 4, "Petrol");
    Bike bike1("Yamaha");

    // Polymorphism
    Vehicle* vehicles[2];

    vehicles[0] = &car1;
    vehicles[1] = &bike1;

    for (int i = 0; i < 2; i++)
    {
        vehicles[i]->move();
        cout << "\n";
    }

    return 0;
}
