#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

//void printMap(map<vector<int>, bool> x) {
//    for(auto &i : x) {
//        for(auto &j : i.first) {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//}

int main() {
    ifstream in("in06.txt");
    vector<int> status;
    int tmp, maxI, maxValue = -1;
    while(in >> tmp) {
        status.push_back(tmp);
        if(tmp > maxValue) {
            maxValue = tmp;
            maxI = status.size()-1;
        }
    }

    int steps = 0;

    map<vector<int>, bool> history;

    do {
        history.emplace(status, true);
        int split = status[maxI];
        status[maxI] = 0;
        int between = status.size();
        int i = maxI;

        maxValue = -1;
        steps++;
        while (between > 0) {
            status[i] += split / between;
            split -= split / between;
            between--;
            if (status[i] > maxValue || (status[i] == maxValue && i < maxI)) {
                maxValue = status[i];
                maxI = i;
            }
            i = (--i < 0) ? i + status.size() : i;
        }
    } while (history.count(status) == 0);
    cout << steps;
    return 1;
}