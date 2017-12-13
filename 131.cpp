#include <iostream>
#include <fstream>

using namespace std;

int severity(int step, int range) {
    if(step % (2 * (range - 1)) == 0) return step * range;
    else return 0;
}

int main() {
    ifstream in("in13.txt");
    int step, range, sum = 0;
    while(in >> step) {
        in.ignore(2) >> range;
        sum += severity(step, range);
    }
    cout << sum;
}