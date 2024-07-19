#include <iostream>
#include <vector>
#include <string>
#include <random>

enum class EClass { A, B, C, D, E, F };

struct Property {
    std::string name;
    int price;
    int area;
    int rooms;
    float bfactor;
    EClass eclass;
    bool garage;
};

class Database {
public:
    void insert(const Property& property) {
        Property.push_back(Property);
    }

    void print() const {
        for (const auto& property : Property) {
            std::cout << "Name: " << property.name << ", ";
            std::cout << "Price: " << property.price << " PKR, ";
            std::cout << "Area: " << property.area << " m2, ";
            std::cout << "Rooms: " << property.rooms << ", ";
            std::cout << "Brightness Factor: " << property.bfactor << ", ";
            std::cout << "Energy Class: " << static_cast<char>('A' + static_cast<int>(property.eclass)) << ", ";
            std::cout << "Garage: " << (property.garage ? "Yes" : "No") << std::endl;
        }
    }
}