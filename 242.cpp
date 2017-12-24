#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int x, y;
    bool visited;
};

class Bridge {
public:
    int strength = 0, length = 0;
};

Bridge strongestBridge(int x, vector<Node>& t) {
    Bridge maximum;
    for (auto& node : t) {
        if (!node.visited) {
            if (node.x == x) {
                node.visited = true;
                Bridge bridge = strongestBridge(node.y, t);
                bridge.strength += node.x + node.y;
                bridge.length++;
                if (bridge.length > maximum.length) maximum = bridge;
                else if (bridge.length == maximum.length && bridge.strength > maximum.strength) maximum = bridge;
                node.visited = false;
            } else if (node.y == x) {
                node.visited = true;
                Bridge bridge = strongestBridge(node.x, t);
                bridge.strength += node.x + node.y;
                bridge.length++;
                if (bridge.length > maximum.length) maximum = bridge;
                else if (bridge.length == maximum.length && bridge.strength > maximum.strength) maximum = bridge;
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

    Bridge bridge = strongestBridge(0, t);
    cout << bridge.strength;
}