#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int id;
    vector<int> conn;
};

int bfs(vector<Node>& t, int x) {
    priority_queue<int> queue;
    bool visited[t.size()];
    for(auto& a : visited) a = false;
    int visitedSize = 0;
    queue.push(x);
    do {
        queue.pop();
        if(visited[x]) {
            continue;
        }
        visited[x] = true;
        visitedSize++;
        for (int i : t[x].conn) {
            if(!visited[i])
                queue.push(i);
        }
        x = queue.top();

    } while (!queue.empty());
    return visitedSize;
}

int main() {
    vector<Node> t;

    ifstream in("in12.txt");
    string inString;
    while (getline(in, inString)) {
        istringstream in2(inString);
        Node tmp;
        int id;
        in2 >> id; in2.ignore(5);
        tmp.id = id;
        while (in2 >> id) {
            in2.ignore(2);
            tmp.conn.push_back(id);
        }
        t.push_back(tmp);
    }

    cout << bfs(t, 0);
}