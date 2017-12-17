#include <iostream>
#include <vector>

using namespace std;

const int stepSize = 394;

int main() {
    vector<int> buffer;
    buffer.push_back(0);
    int pos = 0;
    for (int i = 1; i <= 2017; i++) {
        pos += stepSize;
        pos %= buffer.size();
        buffer.insert(buffer.begin() + ++pos, i);
    }
    cout << buffer[pos+1];
}
