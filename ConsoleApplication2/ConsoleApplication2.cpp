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
    Reservoir(string _name, string _type, double _height, double _width, double _depth) {
        name = _name;
        type = _type;
        height = _height;
        width = _width;
        depth = _depth;
    }
    Reservoir(const Reservoir& other) {
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

    string get_name() const{
        return name;
    }
    string get_type() const {
        return type;
    }
    double get_height() const {
        return height;
    }
    double get_width() const {
        return width;
    }
    double get_depth() const {
        return depth;
    }

    void set_name(string _name) {
        name = _name;
    }
    void set_type(string _type) {
        type = _type;
    }
    void set_height(double _height) {
        height = _height;
    }
    void set_width(double _width) {
        width = _width;
    }
    void set_depth(double _depth) {
        depth = _depth;
    }


    double volume() const {
        return height * width * depth;
    }
    double perimeter() const {
        return height * width;
    }
    bool is_equal(Reservoir& other) const {
        return (type == other.type);
    }
    void info() const {
        cout << "Reservoir: " << name << ", type: " << type << ", parameters hXwXd: " << height << "X" << width << "X" << depth << endl;
    }
    // 
    int is_equal_perimeter(Reservoir& other) const {
        if (is_equal(other)){
            return (1 - (perimeter() == other.perimeter())) * ((perimeter() > other.perimeter())*2-1); // True => 1 => 2-1 => 1; False => 0 => 0-1 => -1. (0, 1) -> (-1, 1)
        }
        return 0;
    }
};

class Reservoirs {
private:
    int size;
    int capacity;
    Reservoir* arrayy;
public:
    Reservoirs(int _size, const Reservoir* _arrayy) {
        capacity = (int)(_size * 1.5 + 1);
        size = _size;
        Reservoir* arrayy = new Reservoir[capacity];
        for (int i = 0; i < size; i++) {
            arrayy[i] = _arrayy[i];
        }
    }

    void expon(double log = 1.5) {
        capacity = (int)(capacity * log + 1);
        Reservoir* _arrayy = new Reservoir[capacity];
        for (int i = 0; i < size; i++) {
            _arrayy[i] = arrayy[i];
        }
        delete[] arrayy;
        arrayy = _arrayy;
    }

    Reservoir get(int index) const {
        if (0 <= index && index < size) {
            return arrayy[index];
        }
        // error
    }
    void add(Reservoir element) {
        if (size == capacity) {
            expon();
        }
        arrayy[size] = element;
        size++;
    }

    void madd(Reservoirs& elements) {
        for (int i = 0; i < elements.size; i++) {
            add(elements.arrayy[i]);
        }
    }

    void pop(int index) {
        if (0 <= index && index < size) {
            for (int i = index; i < size - 1; i++) {
                arrayy[i] = arrayy[i + 1];
            }
            size--;
        }
    }

    void info() const{
        for (int i = 0; i < size; i++) {
            cout << "#" << i;
            arrayy[i].info();
        }
    }
   
    ~Reservoirs() {
        delete[] arrayy;
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
