#include <iostream>
#include "PlacementArray.h"
using namespace std;

int main(int argc, char *argv[])
{
    Array<int> a(5, 30);
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << '\n';
    }

    cout << "-----------------" << endl;
    Array<int> b = a;
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << '\n';
    }

    cout << "assigment" << endl;
    Array<int> c(5, 10);
    a = b;
    for (int i = 0; i < b.size(); ++i) {
        cout << i+1 << "------------------\n";
        cout << a[i] << '\n';
        cout << b[i] << '\n';
    }
    return 0;
}
