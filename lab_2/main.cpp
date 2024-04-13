#include <iostream>
#include <cmath>


class Sphere
{
    float radius;
public:

    Sphere(float r);
    float V();
    float S();
private:
    
};

Sphere::Sphere(float r) : radius(r) {
}

float Sphere::S() {
    return 4 * 3.14 * pow(radius, 2);
}

float Sphere::V() {
    return 4/3 * 3.14 * pow(radius, 3);
}

int main() {
    float radius;

    std::cout << "Enter the radius of the sphere:";
    std::cin >> radius;

    Sphere Sphere(radius);

    std::cout << "The surface area of the sphere = " << Sphere.S() << std::endl;
    std::cout << "The volume of the sphere = " << Sphere.V() << std::endl;
    return 0;
}
