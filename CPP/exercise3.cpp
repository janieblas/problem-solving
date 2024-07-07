#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*

*/

class Vehicle{
    private:

    public:
        Vehicle(const string& make, const string& model)
        : make(make), model(model) {}
        virtual void displayInfo() const = 0;
        virtual double calculateRange() const = 0;
        virtual ~Vehicle(void){};

    protected:
    string make;
    string model;
};


class Car: public Vehicle{

    public:
    Car(const string& make, const string& model, double fuelEfficiency, double fuelCapacity)
        : Vehicle(make, model), fuelEfficiency(fuelEfficiency), fuelCapacity(fuelCapacity) {}


        void displayInfo() const override {
            cout << "Car Make: " << make << ", Model: " << model 
                << ", Fuel Efficiency: " << fuelEfficiency << " km/l"
                << ", Fuel Capacity: " << fuelCapacity << " liters"
                << ", Range: " << calculateRange() << " km" << endl;
        }

        double calculateRange() const override {
            return fuelEfficiency * fuelCapacity;
        }

    private:
        double fuelEfficiency;
        double fuelCapacity;
};

class Motorcycle: public Vehicle{
public:
    Motorcycle(const std::string& make, const std::string& model, double fuelEfficiency, double fuelCapacity)
        : Vehicle(make, model), fuelEfficiency(fuelEfficiency), fuelCapacity(fuelCapacity) {}

    void displayInfo() const override {
        std::cout << "Motorcycle Make: " << make << ", Model: " << model 
                  << ", Fuel Efficiency: " << fuelEfficiency << " km/l"
                  << ", Fuel Capacity: " << fuelCapacity << " liters"
                  << ", Range: " << calculateRange() << " km" << std::endl;
    }

    double calculateRange() const override {
        return fuelEfficiency * fuelCapacity;
    }

private:
    double fuelEfficiency;
    double fuelCapacity;
};

class VehicleManager {
public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAllVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();
        }
    }

    double calculateTotalRange() const {
        double totalRange = 0;
        for (const auto& vehicle : vehicles) {
            totalRange += vehicle->calculateRange();
        }
        return totalRange;
    }

    ~VehicleManager() {
        for (auto& vehicle : vehicles) {
            delete vehicle;
        }
    }

private:
    std::vector<Vehicle*> vehicles;
};

int main(void){
    VehicleManager manager;

    manager.addVehicle(new Car("Toyota", "Corolla", 15.0, 50.0));
    manager.addVehicle(new Motorcycle("Honda", "CBR", 20.0, 15.0));

    std::cout << "All Vehicles:" << std::endl;
    manager.displayAllVehicles();

    std::cout << "\nTotal Range: " << manager.calculateTotalRange() << " km" << std::endl;

    return 0;
}