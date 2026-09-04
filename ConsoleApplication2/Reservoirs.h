#pragma once

#include <iostream>
#include <fstream>
#include "Reservoir.h"
using namespace std;


class Reservoirs {
private:
    int size;
    int capacity;
    Reservoir* arrayy;
public:
    Reservoirs(int _size, const Reservoir* _arrayy);

    void expon(double log);

    Reservoir get(int index) const;

    void add(Reservoir element);

    void madd(Reservoirs& elements);

    void pop(int index);

    void info() const;

    void to_file(const string file_name) const;

    ~Reservoirs();
};
