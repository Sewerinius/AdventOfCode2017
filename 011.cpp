#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;
    int sum = 0;
    for(int i = 0; i < in.size() - 1; i++) {
        if(in[i] == in[i+1]) sum += in[i] - '0';
    }
    if(in[0] == in.back()) sum += in[0] - '0';
    cout << sum;
    return 0;
}