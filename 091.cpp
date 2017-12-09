#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in("in09.txt");

    int sum = 0;
    int value = 1;

    bool garbage = false;

    char c;
    while(in >> c) {
        if(garbage) {
            if(c == '!') in.ignore(1);
            else if(c == '>') garbage = false;
        } else {
            if(c == '{') {
                sum += value;
                value++;
            } else if(c == '}') {
                value--;
            } else if(c == '<') {
                garbage = true;
            } else if(c == '!') cout << '!';
        }
    }
    cout << sum;
}