#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("in08.txt");
    unordered_map<string, int> registers;

    string reg, operation, compReg;
    int value, compValue;
    while(in >> reg >> operation >> value) {
        if(operation == "dec") value *= -1;
        in.ignore(4) >> compReg >> operation >> compValue;
        bool exec = false;
        if(operation == "<") {
            exec = registers[compReg] < compValue;
        } else if(operation == "<=") {
            exec = registers[compReg] <= compValue;
        } else if(operation == ">") {
            exec = registers[compReg] > compValue;
        } else if(operation == ">=") {
            exec = registers[compReg] >= compValue;
        } else if(operation == "==") {
            exec = registers[compReg] == compValue;
        } else if(operation == "!=") {
            exec = registers[compReg] != compValue;
        }
        if(exec) registers[reg] += value;
    }

    int maximum = 0;
    for(auto& a : registers) maximum = max(maximum, a.second);
    cout << maximum;
}