// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    Reservoir (string _name, string _type, double _height, double _width, double _depth) {
        name = _name;
        type = _type;
        height = _height;
        width = _width;
        depth = _depth;
    }
    Reservoir(Reservoir& other) {
        name = other.name;
        type = other.type;
        height = other.height;
        width = other.width;
        depth = other.depth;
    }
    Reservoir() {
        name = "";
        type = "";
        height = 0.0;
        width = 0.0;
        depth = 0.0;
    }

    string get_name() {
        return name;
    }
    string get_type() {
        return type;
    }
    double get_height() {
        return height;
    }
    double get_width() {
        return width;
    }
    double get_depth() {
        return depth;
    }

    void set_name(string _name) {
        name = _name;
    }
    void set_type(string _type) {
        name = _type;
    }
    void set_height(double _height) {

    }



    double volume() {
        return height * width * depth;
    }
    double perimeter() {
        return height * width;
    }



    


};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
