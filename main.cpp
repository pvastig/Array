#include <iostream>
#include "Array.h"

using namespace std;

int main(int argc, char *argv[])
{
    Array<int> a(5, 30);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << '\n';
    }

    cout << "-----------------" << endl;
    Array<int> b = a;
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << '\n';
    }

    Array<int> c(5, 10);
    a = b=c;
    for (int i = 0; i < b.size(); ++i) {
        cout << a[i] << '\n';
        cout << "------------------\n";
        cout << b[i] << '\n';
    }
    return 0;
}
