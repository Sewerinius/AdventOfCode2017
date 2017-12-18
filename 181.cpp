#include <fstream>
#include <iostream>
#include <map>
#include <vector>

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

int main() {
    ifstream in("in18.txt");
    vector<Instruction> code;
    map<char, long long> regs;

    string instName;
    while (in >> instName) {
        Instruction tmp;
        tmp.name = instName;
        in.ignore(1);
        tmp.reg1.init(in, regs);

        if (instName == "set" || instName == "add" || instName == "mul" || instName == "mod" || instName == "jgz") {
            in.ignore(1);
            tmp.reg2.init(in, regs);
        }
        code.push_back(tmp);
    }

    int i = 0;

    long long soundFrequency = 0;

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
            soundFrequency = inst.reg1.getValue(regs);
        } else if (inst.name == "rcv") {
            if (inst.reg1.getValue(regs) != 0) {
                cout << soundFrequency;
                return 0;
            }
        }
        i++;
    }
    cout << soundFrequency;

}