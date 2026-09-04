// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Reservoir.h"
using namespace std;
/*
class Reservoirs {
private:
    int size;
    int capacity;
    Reservoir* arrayy;
public:
    Reservoirs(int _size, const Reservoir* _arrayy) {
        capacity = (int)(_size * 1.5 + 1);
        size = _size;
        arrayy = new Reservoir[capacity];
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
            cout << "#" << i << ' ';
            arrayy[i].info();
        }
    }

    void to_file(const string file_name) const{
        ofstream file(file_name);
        if (file.is_open()) {
            for (int i = 0; i < size; i++) {
                const Reservoir temp = arrayy[i];
                file << "#" << i << " Reservoir: " << temp.get_name() << ", type: " << temp.get_type() << ", parameters hXwXd: " << temp.get_height() << "X" << temp.get_width() << "X" << temp.get_depth() << endl;
            }
            file.close();
        }
    }
   
    ~Reservoirs() {
        delete[] arrayy;
    }
};
*/

int main()
{
    Reservoir o1("Black Sea", "Sea", 100, 200, 10);
    cout << o1.volume() << endl;
    o1.info();
    cout << o1.perimeter() << endl << endl;

    Reservoir o2("Green Sea", "Sea", 400, 50, 20);
    cout << o2.volume() << endl;
    o2.info();
    cout << o2.perimeter() << endl << endl;

    Reservoir o3("Cinhai", "Lake", 100, 50, 5);
    cout << o3.volume() << endl;
    o3.info();
    cout << o3.perimeter() << endl << endl;



    cout << o1.is_equal(o2) << endl;
    cout << o1.is_equal_perimeter(o2) << endl;
    cout << o1.is_equal(o3) << endl;
    cout << o1.is_equal_perimeter(o3) << endl;
    cout << o2.is_equal(o3) << endl;
    cout << o2.is_equal_perimeter(o3) << endl << endl << endl;


    const Reservoir* arrayys = new Reservoir[2]{ o1, o2 };

    Reservoirs s1(2, arrayys);
    s1.info();
    cout << endl;
    s1.add(o3);
    s1.info();
    cout << endl;
    s1.pop(1);
    s1.info();
    cout << endl;
    string file_name = "File.txt";
    s1.to_file(file_name);


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
