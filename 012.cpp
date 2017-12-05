#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;
    int sum = 0;
    for(int i = 0; i < in.size(); i++) {
        int j = (i + in.size()/2) % in.size();
        if(in[i] == in[j]) sum += in[i] - '0';
    }
    cout << sum;
    return 0;
}