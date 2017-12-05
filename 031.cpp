#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 1;
    int j = 1;
    while(true) {
        if(i*j >= n) break;
        i++;
        if(i*j >= n) break;
        j++;
    }
    cout << i/2 + abs((j-1)/2 - (i*j-n));

}