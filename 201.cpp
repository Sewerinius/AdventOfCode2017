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

    int getLengthA() {
        return abs(ax) + abs(ay) + abs(az);
    }

    int getLengthV() {
        return abs(vx) + abs(vy) + abs(vz);
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

    vector<Particle> particles2;
    int stepSize = 0;

    for (auto &particle : particles) {
        if (minimumA == particle.getLengthA()) {
            particles2.push_back(particle);
            if(particle.ax != 0) stepSize = max(stepSize, -(particle.vx / particle.ax));
            if(particle.ay != 0) stepSize = max(stepSize, -(particle.vy / particle.ay));
            if(particle.az != 0) stepSize = max(stepSize, -(particle.vz / particle.az));
        }
    }

    int minimumV = -1;

    for (auto &particle : particles2) {
        particle.step(stepSize + 1);
        if (minimumV == -1) minimumV = particle.getLengthV();
        else minimumV = min(minimumV, particle.getLengthV());
    }

    for (auto &particle : particles2) {
        if (minimumV == particle.getLengthV()) {
            cout << particle.index << endl;
        }
    }


}