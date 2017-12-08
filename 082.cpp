#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("in08.txt");
    unordered_map<string, int> registers;

    string reg, operation, compReg;
    int value, compValue;
    int maximum = 0;
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
        if(exec) {
            registers[reg] += value;
            maximum = max(maximum, registers[reg]);
        }
    }
    cout << maximum;
}