#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("in05.txt");
    vector<int> t;
    int tmp;
    while (in >> tmp) t.push_back(tmp);
    int i = 0;
    int steps = 0;
    while(i>=0 && i < t.size()) {
        i += t[i] >= 3 ? t[i]-- : t[i]++;
        steps++;
    }
    cout << steps;

}