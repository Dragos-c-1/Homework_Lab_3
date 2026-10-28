#pragma once
#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        return width * height;
    }

    double getPerimeter() const {
        return 2 * (width + height);
    }

    void compareArea(const Rectangle& other) const {
        double thisArea = this->getArea();
        double otherArea = other.getArea();

        if (thisArea > otherArea)
            std::cout << "Primul dreptunghi are aria mai mare (" << thisArea << " vs " << otherArea << ").\n";
        else if (thisArea < otherArea)
            std::cout << "Al doilea dreptunghi are aria mai mare (" << otherArea << " vs " << thisArea << ").\n";
        else
            std::cout << "Dreptunghiurile au arii egale.\n";
    }

    void comparePerimeter(const Rectangle& other) const {
        double thisPerim = this->getPerimeter();
        double otherPerim = other.getPerimeter();

        if (thisPerim > otherPerim)
            std::cout << "Primul are perimetrul mai mare (" << thisPerim << " vs " << otherPerim << ").\n";
        else if (thisPerim < otherPerim)
            std::cout << "Al doilea are perimetrul mai mare (" << otherPerim << " vs " << thisPerim << ").\n";
        else
            std::cout << "Dreptunghiurile au perimetre egale.\n";
    }
};
