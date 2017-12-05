#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class LetterList {
public:
    vector<int> t;

    LetterList(string a) {
        t.resize('z' - 'a' + 1, 0);
        for (char i : a) {
            t[i - 'a']++;
        }
    }

    bool operator== (const LetterList &x) {
        for(int i = 0; i < t.size(); i++) {
            if(t[i] != x.t[i]) return false;
        }
        return true;
    }
};

int main() {
    ifstream instrm("in04.txt");
    string in;
    int sum = 0;
    while(getline(instrm, in)) {
        istringstream sstrm(in);
        vector<LetterList> t;
        string tmp;
        while(sstrm >> tmp) {
            t.emplace_back(tmp);
        }
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