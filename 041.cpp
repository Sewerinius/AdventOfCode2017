#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream instrm("in04.txt");
    string in;
    int sum = 0;
    while(getline(instrm, in)) {
        istringstream sstrm(in);
        vector<string> t;
        string tmp;
        while(sstrm >> tmp) t.push_back(tmp);
        bool f = false;
        for(int i = 0; i < t.size() && !f; i++) {
            for(int j = i + 1; j < t.size() && !f; j++) {
                if(t[i] == t[j]) {
                    f = true;
                }
            }
        }
        if(!f) sum++;
    }
    cout << sum;
}