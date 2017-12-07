#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Function {
public:
    string name;
    int weight;
    string parent;
    vector<string> children;

    Function(string name, int weight) {
        this->name = name;
        this->weight = weight;
        parent = "";
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    unordered_map<string, Function> t;

    unordered_map<string, string> unresolvedParents;

    ifstream in("in07.txt");
    string inStr;
    while(getline(in, inStr)) {
        istringstream inStream(inStr);
        string name;
        int weight;

        inStream >> name; inStream.ignore(2);
        inStream >> weight; inStream.ignore(5);

        t.emplace(name, Function(name, weight));

        if(unresolvedParents.count(name) != 0) {
            t.at(name).parent = unresolvedParents[name];
            unresolvedParents.erase(name);
        }

        string child;
        while(getline(inStream, child, ',')) {
            inStream.ignore();
            t.at(name).children.emplace_back(child);
            if(t.count(child) != 0) {
                t.at(child).parent = name;
            } else {
                unresolvedParents[child] = name;
            }
        }
    }

    string rootName = t.begin()->first;
    while (t.at(rootName).parent != "") {
        rootName = t.at(rootName).parent;
    }
    cout << rootName;

}