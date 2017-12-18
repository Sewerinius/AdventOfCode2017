#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Value {
    char adress;
    long long value;
    bool isAdres;
public:
//    Value(char adress) : adress(adress), isAdres(true) {}
//
//    Value(int value) : value(value), isAdres(false) {}

    void init(ifstream& in, map<char, long long>& regs) {
        char c = in.peek();
        if ((c >= '0' && c <= '9') || c == '-') {
            in >> value;
            isAdres = false;
        } else {
            in >> adress;
            regs[adress] = 0;
            isAdres = true;
        }
    }

    long long getValue(map<char, long long>& regs) {
        if (isAdres) return regs[adress];
        else return value;
    }

    void setValue(map<char, long long>& regs, long long v) {
        if (isAdres) regs[adress] = v;
    }
};

class Instruction {
public:
    string name;
    Value reg1, reg2;
};

int runProgram(map<char, long long>& regs, const vector<Instruction>& code, int& i, queue<long long>& send, queue<long long>& recive) {
    while (i >= 0 && i < code.size()) {
        Instruction inst = code[i];
        if (inst.name == "jgz") {
            if (inst.reg1.getValue(regs) > 0) {
                i += inst.reg2.getValue(regs) - 1;
            }
        } else if (inst.name == "set") {
            inst.reg1.setValue(regs, inst.reg2.getValue(regs));
        } else if (inst.name == "add") {
            inst.reg1.setValue(regs, inst.reg1.getValue(regs) + inst.reg2.getValue(regs));
        } else if (inst.name == "mul") {
            inst.reg1.setValue(regs, inst.reg1.getValue(regs) * inst.reg2.getValue(regs));
        } else if (inst.name == "mod") {
            inst.reg1.setValue(regs, inst.reg1.getValue(regs) % inst.reg2.getValue(regs));
        } else if (inst.name == "snd") {
            send.push(inst.reg1.getValue(regs));
        } else if (inst.name == "rcv") {
            if (recive.size() > 0) {
                inst.reg1.setValue(regs, recive.front());
                recive.pop();
            } else {
                return 1; //waiting for data
            }
        }
        i++;
    }
    return 0; //program ended
}

int main() {
    ifstream in("in18.txt");
    vector<Instruction> code;
    map<char, long long> regs1;

    string instName;
    while (in >> instName) {
        Instruction tmp;
        tmp.name = instName;
        in.ignore(1);
        tmp.reg1.init(in, regs1);

        if (instName == "set" || instName == "add" || instName == "mul" || instName == "mod" || instName == "jgz") {
            in.ignore(1);
            tmp.reg2.init(in, regs1);
        }
        code.push_back(tmp);
    }
    map<char, long long> regs2(regs1);
    regs2['p'] = 1;

    int i1 = 0, i2 = 0;
    queue<long long> bridge1, bridge2;

    int return1 = runProgram(regs1, code, i1, bridge1, bridge2);
    int return2 = runProgram(regs2, code, i2, bridge2, bridge1);

    int totalSend = bridge2.size();
    while (true) {
        return1 = runProgram(regs1, code, i1, bridge1, bridge2);
        if (bridge1.size() == 0) break;
        totalSend -= bridge2.size();
        return2 = runProgram(regs2, code, i2, bridge2, bridge1);
        totalSend += bridge2.size();
        if (bridge2.size() == 0) break;
    }

    cout << totalSend;
}