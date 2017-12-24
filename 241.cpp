#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int x, y;
    bool visited;
};

int strongestBridge(int x, vector<Node>& t) {
    int maximum = 0;
    for (auto& node : t) {
        if (!node.visited) {
            if (node.x == x) {
                node.visited = true;
                maximum = max(maximum, strongestBridge(node.y, t) + node.x + node.y);
                node.visited = false;
            } else if (node.y == x) {
                node.visited = true;
                maximum = max(maximum, strongestBridge(node.x, t) + node.x + node.y);
                node.visited = false;
            }
        }
    }
    return maximum;
}

int main () {
    ifstream in("in24.txt");
    vector<Node> t;
    int tmpInt;
    while (in >> tmpInt) {
        Node tmpNode;
        tmpNode.x = tmpInt;
        in.ignore(1);
        in >> tmpInt;
        tmpNode.y = tmpInt;
        tmpNode.visited = false;
        t.push_back(tmpNode);
    }

    cout << strongestBridge(0, t);
}