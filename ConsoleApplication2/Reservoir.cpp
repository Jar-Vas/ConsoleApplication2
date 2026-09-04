

#include "Reservoir.h"
#include <iostream>
using namespace std;



Reservoir::Reservoir(string _name, string _type, double _height, double _width, double _depth) {
    name = _name;
    type = _type;
    height = _height;
    width = _width;
    depth = _depth;
}
Reservoir::Reservoir(const Reservoir& other) {
    name = other.name;
    type = other.type;
    height = other.height;
    width = other.width;
    depth = other.depth;
}
Reservoir::Reservoir() {
    name = "";
    type = "";
    height = 0.0;
    width = 0.0;
    depth = 0.0;
}

string Reservoir::get_name() const {
    return name;
}
string Reservoir::get_type() const {
    return type;
}
double Reservoir::get_height() const {
    return height;
}
double Reservoir::get_width() const {
    return width;
}
double Reservoir::get_depth() const {
    return depth;
}

void Reservoir::set_name(string _name) {
    name = _name;
}
void Reservoir::set_type(string _type) {
    type = _type;
}
void Reservoir::set_height(double _height) {
    height = _height;
}
void Reservoir::set_width(double _width) {
    width = _width;
}
void Reservoir::set_depth(double _depth) {
    depth = _depth;
}


double Reservoir::volume() const {
    return height * width * depth;
}
double Reservoir::perimeter() const {
    return height * width;
}
bool Reservoir::is_equal(const Reservoir& other) const {
    return (type == other.type);
}
void Reservoir::info() const {
    cout << "Reservoir: " << name << ", type: " << type << ", parameters hXwXd: " << height << "X" << width << "X" << depth << endl;
}

int Reservoir::is_equal_perimeter(const Reservoir& other) const {
    if (!is_equal(other)) return 0;
    if (perimeter() > other.perimeter()) return 1;
    if (perimeter() < other.perimeter()) return -1;
    return 0;
}