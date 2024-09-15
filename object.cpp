#include "object.h"
#include <cmath>

Object::Object(const std::string& name, double x, double y, const std::string& type, std::time_t creation_time)
    : name(name), x(x), y(y), type(type), creation_time(creation_time) {}

double Object::distance() const {
    return std::sqrt(x * x + y * y);
}
