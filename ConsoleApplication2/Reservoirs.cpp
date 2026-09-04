#include "Reservoirs.h"

#include <iostream>
#include <fstream>
#include "Reservoir.h"
using namespace std;



Reservoirs::Reservoirs(int _size, const Reservoir* _arrayy) {
    capacity = (int)(_size * 1.5 + 1);
    size = _size;
    arrayy = new Reservoir[capacity];
    for (int i = 0; i < size; i++) {
        arrayy[i] = _arrayy[i];
    }
}

void Reservoirs::expon(double log = 1.5) {
    capacity = (int)(capacity * log + 1);
    Reservoir* _arrayy = new Reservoir[capacity];
    for (int i = 0; i < size; i++) {
        _arrayy[i] = arrayy[i];
    }
    delete[] arrayy;
    arrayy = _arrayy;
}

Reservoir Reservoirs::get(int index) const {
    if (0 <= index && index < size) {
        return arrayy[index];
    }
    // error
}
void Reservoirs::add(Reservoir element) {
    if (size == capacity) {
        expon();
    }
    arrayy[size] = element;
    size++;
}

void Reservoirs::madd(Reservoirs& elements) {
    for (int i = 0; i < elements.size; i++) {
        add(elements.arrayy[i]);
    }
}

void Reservoirs::pop(int index) {
    if (0 <= index && index < size) {
        for (int i = index; i < size - 1; i++) {
            arrayy[i] = arrayy[i + 1];
        }
        size--;
    }
}

void Reservoirs::info() const {
    for (int i = 0; i < size; i++) {
        cout << "#" << i << ' ';
        arrayy[i].info();
    }
}

void Reservoirs::to_file(const string file_name) const {
    ofstream file(file_name);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            const Reservoir temp = arrayy[i];
            file << "#" << i << " Reservoir: " << temp.get_name() << ", type: " << temp.get_type() << ", parameters hXwXd: " << temp.get_height() << "X" << temp.get_width() << "X" << temp.get_depth() << endl;
        }
        file.close();
    }
}

Reservoirs::~Reservoirs() {
    delete[] arrayy;
}