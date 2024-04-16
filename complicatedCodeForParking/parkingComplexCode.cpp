#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Car {
private:
    string licensePlate;

public:
    Car(const string& plate) : licensePlate(plate) {}

    const string& getLicensePlate() const {
        return licensePlate;
    }
};

class ParkingSpace {
private:
    bool occupied;
    Car* car;
    string type;

public:
    ParkingSpace(const string& t) : occupied(false), car(nullptr), type(t) {}

    bool isOccupied() const {
        return occupied;
    }

    void parkCar(Car* c) {
        car = c;
        occupied = true;
    }

    void removeCar() {
        car = nullptr;
        occupied = false;
    }

    Car* getCar() const {
        return car;
    }

    const string& getType() const {
        return type;
    }
};

class ParkingLot {
private:
    vector<ParkingSpace> spaces;
    double hourlyRate;

public:
    ParkingLot(int numSpaces, double rate) : spaces(numSpaces, ParkingSpace("Regular")), hourlyRate(rate) {}

    int getTotalSpaces() const {
        return spaces.size();
    }

    int getOccupiedSpaces() const {
        int count = 0;
        for (const auto& space : spaces) {
            if (space.isOccupied()) {
                count++;
            }
        }
        return count;
    }

    void parkCar(Car* car, const string& type) {
        auto it = find_if(spaces.begin(), spaces.end(), [](const ParkingSpace& space) {
            return !space.isOccupied() && space.getType() == "Regular";
        });
        if (it != spaces.end()) {
            it->parkCar(car);
            cout << "Car parked successfully in regular space" << endl;
        } else {
            cout << "No regular space available" << endl;
        }
    }

    void removeCar(const string& licensePlate) {
        auto it = find_if(spaces.begin(), spaces.end(), [&](const ParkingSpace& space) {
            return space.isOccupied() && space.getCar()->getLicensePlate() == licensePlate;
        });
        if (it != spaces.end()) {
            it->removeCar();
            cout << "Car with license plate " << licensePlate << " removed from parking lot" << endl;
        } else {
            cout << "Car with license plate " << licensePlate << " not found in parking lot" << endl;
        }
    }

    double calculateFee(int hours) const {
        return hours * hourlyRate;
    }

    void searchCar(const string& licensePlate) const {
        auto it = find_if(spaces.begin(), spaces.end(), [&](const ParkingSpace& space) {
            return space.isOccupied() && space.getCar()->getLicensePlate() == licensePlate;
        });
        if (it != spaces.end()) {
            cout << "Car with license plate " << licensePlate << " found in parking lot" << endl;
        } else {
            cout << "Car with license plate " << licensePlate << " not found in parking lot" << endl;
        }
    }
};

int main() {
    ParkingLot lot(10, 5.0); // Create a parking lot with 10 regular spaces and hourly rate $5

    Car car1("ABC123");
    Car car2("XYZ789");
    Car car3("DEF456");

    lot.parkCar(&car1, "Regular");
    lot.parkCar(&car2, "Regular");
    lot.parkCar(&car3, "Regular");

    cout << "Occupied spaces: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    lot.removeCar("XYZ789");

    cout << "Occupied spaces after removing car: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    cout << "Search for car by license plate:" << endl;
    lot.searchCar("ABC123");
    lot.searchCar("XYZ789");

    return 0;
}
