#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Rule {
public:
    vector<vector<bool> > pattern;
    int patternOnNr;

    vector<vector<bool> > result;

    Rule(string in) {
        patternOnNr = 0;
        int i = 0;
        vector<bool> line;
        while (i < in.size()) {
            if (in[i] == '#') {
                patternOnNr++;
                line.push_back(true);
            } else if (in[i] == '.') {
                line.push_back(false);
            } else if (in[i] == '/') {
                pattern.push_back(line);
                line.clear();
            } else if (in[i] == '=') {
                pattern.push_back(line);
                line.clear();
                break;
            }
            i++;
        }
        while (i < in.size()) {
            if (in[i] == '#') {
                line.push_back(true);
            } else if (in[i] == '.') {
                line.push_back(false);
            } else if (in[i] == '/') {
                result.push_back(line);
                line.clear();
            }
            i++;
        }
        result.push_back(line);
    }

    bool match(vector<vector<bool> > image, int x, int y, int size, int nrOn) {
        if (size != pattern.size() || nrOn != patternOnNr) return false;
        bool matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[i][j]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[j][size - i - 1]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[size - i - 1][size - j - 1]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[size - j - 1][i]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[j][i]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[i][size - j - 1]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[size - j - 1][size - i - 1]) {
                    matched = false;
                }
            }
        }
        if (matched) return true;
        matched = true;
        for (int i = 0; i < size && matched; i++) {
            for (int j = 0; j < size && matched; j++) {
                if (image[x + i][y + j] != pattern[size - i - 1][j]) {
                    matched = false;
                }
            }
        }
        return matched;
    }
};

int main() {
    ifstream in("in21.txt");

    vector<vector<bool> > pattern = {{false, true, false}, {false, false, true}, {true, true, true}};
    vector<Rule> rules;
    string inStr;
    while (getline(in, inStr)) rules.emplace_back(inStr);

    for (int k = 0; k < 18; k++) {
        cout << k << endl;
        int size;
        if (pattern.size() % 2 == 0) size = 2;
        else if (pattern.size() % 3 == 0) size = 3;

        vector<vector<bool> > newPattern;

        for (int i = 0; i < pattern.size(); i += size) {
            for (int j = 0; j < pattern.size(); j += size) {
                int nrOn = 0;
                for (int x = 0; x < size; ++x) {
                    for (int y = 0; y < size; ++y) {
                        if (pattern[i+x][j+y]) nrOn++;
                    }
                }
                for (auto& rule : rules) {
                    if (rule.match(pattern, i, j, size, nrOn)) {
                        if (j == 0) {
                            for (auto& line : rule.result) newPattern.push_back(line);
                        } else {
                            for (int l = 0; l < size + 1; ++l) {
                                newPattern[newPattern.size() - size - 1 + l].insert(newPattern[newPattern.size() - size - 1 + l].end(), rule.result[l].begin(), rule.result[l].end());
                            }
                        }
                        break;
                    }
                }
            }
        }

        pattern = newPattern;
    }

    int count = 0;
    for (auto& line : pattern) {
        for (auto&& x : line) {
            if (x) count++;
        }
    }
    cout << count;
}