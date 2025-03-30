// RideSharingSystem.cpp
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// ---------------------- Base Class ----------------------
class Ride {
protected:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(string id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    virtual double fare() const {
        return 0.0; // To be overridden
    }

    virtual string rideDetails() const {
        return "Ride ID: " + rideID +
               " | From: " + pickupLocation +
               " To: " + dropoffLocation +
               " | Distance: " + to_string(distance);
    }

    virtual ~Ride() {}
};

// ---------------------- StandardRide ----------------------
class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 2.0;
    }
};

// ---------------------- PremiumRide ----------------------
class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 3.5;
    }
};

// ---------------------- Driver ----------------------
class Driver {
private:
    string driverID;
    string name;
    double rating;
    vector<shared_ptr<Ride>> assignedRides;

public:
    Driver(string id, string driverName, double rate)
        : driverID(id), name(driverName), rating(rate) {}

    void addRide(shared_ptr<Ride> ride) {
        assignedRides.push_back(ride);
    }

    string getDriverInfo() const {
        return "Driver ID: " + driverID +
               " | Name: " + name +
               " | Rating: " + to_string(rating) +
               " | Total Rides: " + to_string(assignedRides.size());
    }
};

// ---------------------- Rider ----------------------
class Rider {
private:
    string riderID;
    string name;
    vector<shared_ptr<Ride>> requestedRides;

public:
    Rider(string id, string riderName)
        : riderID(id), name(riderName) {}

    void requestRide(shared_ptr<Ride> ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        for (const auto& ride : requestedRides) {
            cout << ride->rideDetails() << endl;
        }
    }
};

// ---------------------- Main Demo ----------------------
int main() {
    shared_ptr<Ride> ride1 = make_shared<StandardRide>("R001", "Downtown", "Airport", 15);
    shared_ptr<Ride> ride2 = make_shared<PremiumRide>("R002", "Mall", "Hotel", 10);

    // Demonstrate polymorphism
    vector<shared_ptr<Ride>> rides = { ride1, ride2 };
    for (const auto& r : rides) {
        cout << r->rideDetails() << " | Fare: $" << r->fare() << endl;
    }

    // Driver
    Driver driver("D100", "Alice", 4.9);
    driver.addRide(ride1);
    driver.addRide(ride2);
    cout << driver.getDriverInfo() << endl;

    // Rider
    Rider rider("U001", "Bob");
    rider.requestRide(ride1);
    rider.requestRide(ride2);
    rider.viewRides();

    return 0;
}
