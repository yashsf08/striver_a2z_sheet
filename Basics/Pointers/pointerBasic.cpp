#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int d = 10;
    int* dptr = &d;

    cout << "Value of Integer: " << d << endl;
    cout << "Value of Integer Pointer: " << dptr << endl;
    cout << "size of Integer : " << sizeof(d) << endl;
    cout << "size of Integer Pointer: " << sizeof(*dptr) << endl;

    // second test
    int firstValue = 10, secondValue = 20;
    char thirdVal = 'a';

    // defining pointers
    int *p1, *p2;
    char *p3;

    p1 = &firstValue;
    p2 = &secondValue;
    p3 = &thirdVal;

    cout << "Value of pointer 1: " << *p1 << endl;
    cout << "Value of pointer 2: " << *p2 << endl;
    cout << "Value of pointer 3: " << *p3 << endl;

    int *temp = p1;
    p1 = p2;
    *p1 = 40;
    *p3 = 'd';
    
    cout << "Value of pointer 1: " << *p1 << endl;
    cout << "Value of pointer 2: " << *p2 << endl;
    cout << "Value of pointer 3: " << *p3 << endl;

    cout << "Restoring the lost dangling pointer: " << *temp << endl;

    return 0;
}