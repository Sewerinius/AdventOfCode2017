#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("in11.txt");
    int p = 0, q = 0, dist = 0;
    string dir;
    while (getline(in, dir, ',')) {
        if (dir == "n") {
            p--;
        } else if (dir == "s") {
            p++;
        } else if (dir == "ne") {
            p--;
            q++;
        } else if (dir == "nw") {
            q--;
        } else if (dir == "se") {
            q++;
        } else if (dir == "sw") {
            p++;
            q--;
        }
    }
    dist = (abs(p) + abs(q) + abs(p + q)) / 2;
    cout << dist;
}