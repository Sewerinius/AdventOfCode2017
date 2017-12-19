#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum direction {U, D, L, R};

int main() {
    ifstream in("in19.txt");

    vector<vector<char> > t;
    vector<char> line;
    char c;

    in >> noskipws;
    while (in >> c) {
        if (c == '\n') {
            t.push_back(line);
            line.clear();
        } else {
            line.push_back(c);
        }
    }

    int x = t[0].size() - 1, y = 0;
    direction dir = D;

    int steps = 0;

    while (t[y][x] != ' ') {
        steps++;
        if (t[y][x] == '+') {
            if (dir == U || dir == D) {
                if (x > 0 && t[y][x-1] == '-') dir = L;
                else if (x < t[y].size() - 1 && t[y][x+1] == '-') dir = R;
            } else if (dir == L || dir == R) {
                if (y > 0 && t[y-1][x] == '|') dir = U;
                else if (y < t.size()-1 && t[y+1][x] == '|') dir = D;
            }
        } else if (t[y][x] != '-' && t[y][x] != '|') {
            cout << t[y][x];
        }

        switch (dir) {
            case U:
                y -= 1;
                break;
            case D:
                y += 1;
                break;
            case L:
                x -= 1;
                break;
            case R:
                x += 1;
                break;
        }
    }

    cout << ' ' << steps;
}
