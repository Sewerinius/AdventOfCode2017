#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector <char> programs;
    for(char c = 'a'; c <= 'p'; c++) programs.push_back(c);

    char c;

    for (int k = 0; k < 2; k++) {
        ifstream in("in16.txt");
        while (in >> c) {
            if (c == 's') {
                int i;
                in >> i;
                rotate(programs.begin(), programs.end() - i, programs.end());
            } else if (c == 'x') {
                int a, b;
                in >> a; in.ignore(1);
                in >> b;
                char tmp = programs[a];
                programs[a] = programs[b];
                programs[b] = tmp;
            } else if (c == 'p') {
                char a, b;
                in >> a; in.ignore(1);
                in >> b;
                for(auto& x : programs) {
                    if(x == a) x = b;
                    else if(x == b) x = a;
                }
            }
            in.ignore(1);
        }
    }

    for(auto& x : programs) cout << x;
}