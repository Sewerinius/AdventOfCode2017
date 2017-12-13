#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int severity(int step, int range) {
    if(step % (2 * (range - 1)) == 0) return step * range;
    else return 0;
}

int main() {
    ifstream in("in13.txt");
    vector<pair<int, int> > firewall;
    int step, range;
    while(in >> step) {
        in.ignore(2) >> range;
        firewall.emplace_back(step, range);
    }
    int sum, i = -1;
    do {
        i++;
        sum = 0;
        for(auto& a : firewall) sum += severity(a.first + i, a.second);
    } while (sum != 0);

    cout << i;
}