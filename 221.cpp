#include <iostream>
#include <fstream>
#include <map>

using namespace std;

enum direction {U, D, L, R};

int main() {
    ifstream in("in22.txt");
    in >> noskipws;

    map<int, map<int, bool> > t;
    char c;

    int x = 0, y = 0;
    while (in >> c) {
        if (c == '\n') {
            x++;
            y = -1;
        } else if (c == '#') {
            t[x][y] = true;
        }
        y++;
    }

    x /= 2;
    y /= 2;

    direction dir = U;
    int count = 0;

    for (int i = 0; i < 10000; i++) {
        if (t[x][y]) {
            t[x][y] = false;
            if (dir == U) dir = R;
            else if (dir == R) dir = D;
            else if (dir == D) dir = L;
            else dir = U;
        } else {
            t[x][y] = true;
            if (dir == U) dir = L;
            else if (dir == R) dir = U;
            else if (dir == D) dir = R;
            else dir = D;
            count++;
        }
        if (dir == U) x--;
        else if (dir == R) y++;
        else if (dir == D) x++;
        else y--;
    }

    cout << count;
}