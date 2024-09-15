#pragma once
#include <string>
#include <ctime>

class Object {
public:
    std::string name;
    double x;
    double y;
    std::string type;
    std::time_t creation_time;

    Object(const std::string& name, double x, double y, const std::string& type, std::time_t creation_time);
    
    double distance() const; // Для вычисления расстояния
};
