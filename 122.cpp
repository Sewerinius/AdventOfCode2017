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

void bfs(vector<Node>& t, bool visited[], int x) {
    priority_queue<int> queue;
    queue.push(x);
    do {
        queue.pop();
        visited[x] = true;
        for (int i : t[x].conn) {
            if(!visited[i])
                queue.push(i);
        }
        x = queue.top();

    } while (!queue.empty());
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

    int count;
    bool visited[t.size()];
    for(auto& a : visited) a = false;
    for(int i = 0; i < t.size(); i++) {
        if(!visited[i]) {
            count++;
            bfs(t, visited, i);
        }
    }
    cout << count;
}