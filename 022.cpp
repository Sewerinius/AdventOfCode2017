#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string in;
    int sum = 0;
    while(getline(cin, in)) {
        stringstream sstrm(in);
        vector<int> t;
        int a;
        while(sstrm >> a) {
            t.push_back(a);
        }
        bool f = false;
        for(int i = 0; i < t.size() && !f; i++) {
            for(int j = i+1; j < t.size(); j++) {
                if(t[j] % t[i] == 0) {
                    sum += t[j] / t[i];
                    f = true;
                    break;
                } else if (t[i] % t[j] == 0) {
                    sum += t[i] / t[j];
                    f = true;
                    break;
                }
            }
        }
        cout << sum << endl;
    }
    cout << sum;
}