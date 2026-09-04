#pragma once

#include <iostream>
using namespace std;


class Reservoir {
private:
    string name;
    string type;
    double height;
    double width;
    double depth;
public:
    // Нема сенсу вікористовавути explicit
    Reservoir(string _name, string _type, double _height, double _width, double _depth);
    Reservoir(const Reservoir& other);
    Reservoir();

    string get_name() const;
    string get_type() const;
    double get_height() const;
    double get_width() const;
    double get_depth() const;

    void set_name(string _name);
    void set_type(string _type);
    void set_height(double _height);
    void set_width(double _width);
    void set_depth(double _depth);


    double volume() const;
    double perimeter() const;
    bool is_equal(const Reservoir& other) const;
    void info() const;

    int is_equal_perimeter(const Reservoir& other) const;
};
