#include <iostream>
#include <fstream>
#include <map>

using namespace std;

enum direction {U, D, L, R};
enum state {C = 0, F, W, I};

int main() {
    ifstream in("in22.txt");
    in >> noskipws;

    map<int, map<int, state> > t;
    char c;

    int x = 0, y = 0;
    while (in >> c) {
        if (c == '\n') {
            x++;
            y = -1;
        } else if (c == '#') {
            t[x][y] = I;
        } else if (c == '.') {
            t[x][y] = C;
        }
        y++;
    }

    x /= 2;
    y /= 2;

    direction dir = U;
    int count = 0;

    for (int i = 0; i < 10000000; i++) {
        if (t[x][y] == I) {
            t[x][y] = F;
            if (dir == U) dir = R;
            else if (dir == R) dir = D;
            else if (dir == D) dir = L;
            else dir = U;
        } else if (t[x][y] == C) {
            t[x][y] = W;
            if (dir == U) dir = L;
            else if (dir == R) dir = U;
            else if (dir == D) dir = R;
            else dir = D;
        } else if (t[x][y] == F) {
            t[x][y] = C;
            if (dir == U) dir = D;
            else if (dir == R) dir = L;
            else if (dir == D) dir = U;
            else dir = R;
        } else if (t[x][y] == W) {
            t[x][y] = I;
            count++;
        }
        if (dir == U) x--;
        else if (dir == R) y++;
        else if (dir == D) x++;
        else y--;
    }

    cout << count;
}
