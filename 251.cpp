#include <iostream>
#include <unordered_map>

using namespace std;

enum State {A, B, C, D, E, F};

int main() {
    State state = A;
    unordered_map<int, bool> tape;
    int count = 0, i = 0;
    for (int k = 0; k < 12386363; k++) {
        if (state == A) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i++;
                state = B;
            } else {
                tape[i] = false; count--;
                i--;
                state = E;
            }
        } else if (state == B) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i--;
                state = C;
            } else {
                tape[i] = false; count--;
                i++;
                state = A;
            }
        } else if (state == C) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i--;
                state = D;
            } else {
                tape[i] = false; count--;
                i++;
                state = C;
            }
        } else if (state == D) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i--;
                state = E;
            } else {
                tape[i] = false; count--;
                i--;
                state = F;
            }
        } else if (state == E) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i--;
                state = A;
            } else {
                i--;
                state = C;
            }
        } else if (state == F) {
            if (!tape[i]) {
                tape[i] = true; count++;
                i--;
                state = E;
            } else {
                i++;
                state = A;
            }
        }
    }

    cout << count;
}