#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string in;
    int sum = 0;
    while(getline(cin, in)) {
        stringstream sstrm(in);
        int a;
        sstrm >> a;
        int maxA = a, minA = a;
        while(sstrm >> a) {
            if(a > maxA) maxA = a;
            else if(a < minA) minA = a;
        }
        sum += maxA - minA;
        cout << sum << endl;
    }
    cout << sum;
}