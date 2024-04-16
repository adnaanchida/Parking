#include <iostream>
#include <vector>
#include <string>

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

public:
    ParkingSpace() : occupied(false), car(nullptr) {}

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
};

class ParkingLot {
private:
    vector<ParkingSpace> spaces;

public:
    ParkingLot(int numSpaces) : spaces(numSpaces) {}

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

    void parkCar(Car* car) {
        for (auto& space : spaces) {
            if (!space.isOccupied()) {
                space.parkCar(car);
                cout << "Car parked successfully in space " << (&space - &spaces[0]) + 1 << endl;
                return;
            }
        }
        cout << "Parking lot is full" << endl;
    }

    void removeCar(const string& licensePlate) {
        for (auto& space : spaces) {
            if (space.isOccupied() && space.getCar()->getLicensePlate() == licensePlate) {
                space.removeCar();
                cout << "Car with license plate " << licensePlate << " removed from parking lot" << endl;
                return;
            }
        }
        cout << "Car with license plate " << licensePlate << " not found in parking lot" << endl;
    }
};

int main() {
    ParkingLot lot(5); // Create a parking lot with 5 spaces

    Car car1("ABC123");
    Car car2("XYZ789");
    Car car3("DEF456");

    lot.parkCar(&car1);
    lot.parkCar(&car2);
    lot.parkCar(&car3);

    cout << "Occupied spaces: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    lot.removeCar("XYZ789");

    cout << "Occupied spaces after removing car: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    return 0;
}


/*
OUTPUT:
#include <iostream>
#include <vector>
#include <string>

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

public:
    ParkingSpace() : occupied(false), car(nullptr) {}

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
};

class ParkingLot {
private:
    vector<ParkingSpace> spaces;

public:
    ParkingLot(int numSpaces) : spaces(numSpaces) {}

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

    void parkCar(Car* car) {
        for (auto& space : spaces) {
            if (!space.isOccupied()) {
                space.parkCar(car);
                cout << "Car parked successfully in space " << (&space - &spaces[0]) + 1 << endl;
                return;
            }
        }
        cout << "Parking lot is full" << endl;
    }

    void removeCar(const string& licensePlate) {
        for (auto& space : spaces) {
            if (space.isOccupied() && space.getCar()->getLicensePlate() == licensePlate) {
                space.removeCar();
                cout << "Car with license plate " << licensePlate << " removed from parking lot" << endl;
                return;
            }
        }
        cout << "Car with license plate " << licensePlate << " not found in parking lot" << endl;
    }
};

int main() {
    ParkingLot lot(5); // Create a parking lot with 5 spaces

    Car car1("ABC123");
    Car car2("XYZ789");
    Car car3("DEF456");

    lot.parkCar(&car1);
    lot.parkCar(&car2);
    lot.parkCar(&car3);

    cout << "Occupied spaces: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    lot.removeCar("XYZ789");

    cout << "Occupied spaces after removing car: " << lot.getOccupiedSpaces() << "/" << lot.getTotalSpaces() << endl;

    return 0;
}




*/