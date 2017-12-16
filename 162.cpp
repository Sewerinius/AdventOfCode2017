#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream in("in16.txt");

    vector <char> permutation1, permutation2;
    for(char c = 'a'; c <= 'p'; c++) {
        permutation1.push_back(c);
        permutation2.push_back(c);
    }

    char c;
    while (in >> c) {
        if (c == 's') {
            int i;
            in >> i;
            rotate(permutation1.begin(), permutation1.end() - i, permutation1.end());
        } else if (c == 'x') {
            int a, b;
            in >> a; in.ignore(1);
            in >> b;
            char tmp = permutation1[a];
            permutation1[a] = permutation1[b];
            permutation1[b] = tmp;
        } else if (c == 'p') {
            char a, b;
            in >> a; in.ignore(1);
            in >> b;
            for(auto& x : permutation2) {
                if(x == a) x = b;
                else if(x == b) x = a;
            }
        }
        in.ignore(1);
    }

    vector<vector<char> > cycles1, cycles2;
    vector<bool> used(16, false);
    for (int i = 0; i < 16; i++) {
        if (used[i]) continue;
        vector<char> cycle;
        char j = 'a' + i;
        do {
            used[j - 'a'] = true;
            cycle.push_back(j);
            j = permutation1[j - 'a'];
        } while ('a' + i != j);

        cycles1.push_back(cycle);
    }
    for (auto &&i : used) i = false;
    for (int i = 0; i < 16; i++) {
        if(used[i]) continue;
        vector<char> cycle;
        char j = 'a' + i;
        do {
            used[j - 'a'] = true;
            cycle.push_back(j);
            j = permutation2[j - 'a'];
        } while ('a' + i != j);

        cycles2.push_back(cycle);
    }

    vector<char> programs1, programs2;
    for (c = 'a'; c <= 'p'; c++) {
        for(int i = 0; i < cycles1.size(); i++) {
            for(int j = 0; j < cycles1[i].size(); j++) {
                if(cycles1[i][j] == c) {
                    programs1.push_back(cycles1[i][(1000000000 + j) % cycles1[i].size()]);
                    break;
                }
            }
        }
    }
    for (c = 'a'; c <= 'p'; c++) {
        for(int i = 0; i < cycles2.size(); i++) {
            for(int j = 0; j < cycles2[i].size(); j++) {
                if(cycles2[i][j] == c) {
                    programs2.push_back(cycles2[i][(1000000000 + j) % cycles2[i].size()]);
                    break;
                }
            }
        }
    }


    for(auto& x : programs1) cout << programs2[x - 'a'];
}