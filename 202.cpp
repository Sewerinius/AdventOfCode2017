#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Particle {
public:
    int index;

    int px, py, pz;
    int vx, vy, vz;
    int ax, ay, az;

    bool toDestroy = 0;

    int getLengthA() {
        return abs(ax) + abs(ay) + abs(az);
    }

    int getLengthV() {
        return abs(vx) + abs(vy) + abs(vz);
    }

    bool operator==(Particle& x) {
        return (px == x.px && py == x.py && pz == x.pz);
    }

    void step(int t) {
        while (t--) {
            vx += ax;
            vy += ay;
            vz += az;
            px += vx;
            py += vy;
            pz += vz;
        }
    }
};

int main() {
    ifstream in("in20.txt");

    vector<Particle> particles;

    int minimumA = -1;
    int ind = 0;

    while (in.ignore(3)) {
        Particle tmp;
        tmp.index = ind++;
        in >> tmp.px; in.ignore(1); in >> tmp.py; in.ignore(1); in >> tmp.pz;
        in.ignore(6);
        in >> tmp.vx; in.ignore(1); in >> tmp.vy; in.ignore(1); in >> tmp.vz;
        in.ignore(6);
        in >> tmp.ax; in.ignore(1); in >> tmp.ay; in.ignore(1); in >> tmp.az;
        in.ignore(2);

        if (minimumA == -1) minimumA = tmp.getLengthA();
        else minimumA = min(minimumA, tmp.getLengthA());

        particles.push_back(tmp);
    }

    while (true) {
        for (int i = 0; i < particles.size(); i++) {
            for (int j = i + 1; j < particles.size(); j++) {
                if (particles[i] == particles[j]) {
                    particles[i].toDestroy = true;
                    particles[j].toDestroy = true;
                }
            }
        }

        auto it = particles.begin();
        while (it != particles.end()) {
            if (it->toDestroy) {
                it = particles.erase(it);
            } else {
                it->step(1);
                it++;
            }
        }

        cout << particles.size() << endl;
    }


}