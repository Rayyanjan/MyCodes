#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

double total_area(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

double circle_area(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        if (dynamic_cast<Circle*>(shape)) {
            total += shape->area();
        }
    }
    return total;
}

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(3.0));
    shapes.push_back(new Rectangle(2.0, 4.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Total area of all shapes: " << total_area(shapes) << std::endl;
    std::cout << "Total area of circles only: " << circle_area(shapes) << std::endl;

    // Clean up memory
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
