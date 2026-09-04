// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Reservoir.h"
#include "Reservoirs.h"
using namespace std;

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
