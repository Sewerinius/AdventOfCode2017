/*
#include <iostream>

using namespace std;

int main() {
    long long a = 1, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    b = 57;
    c = b;
    b *= 100;
    b -= -100000;
    c = b;
    c -= -17000;
    do {
        f = 1;
        d = 2;
        do {
            e = 2;
            do {
                g = d;
                g *= e;
                g -= b;
                if (g == 0) f = 0;
                e -= -1;
                g = e;
                g -= b;
            } while (g != 0);
            d -= -1;
            g = d;
            g -= b;
        } while (g != 0);
        if (f == 0) h -= -1;
        g = b;
        g -= c;
        if (g == 0) {
            cout << h;
            return;
        }
        b -= -17;
    } while (g != 0);
}
*/

/*
#include <iostream>

using namespace std;

int main() {
    long long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    b = 57;
    c = b;
    if (a == 1) {
        b *= 100;
        b -= -100000;
        c = b;
        c -= -17000;
    }

    do {
        f = 1;
        for (d = 2; d < b; d++)
            for (e = 2; e < b; e++)
                if (d * e == b) f = 0;
        if (f == 0) h++;
        if (b == c) {
            cout << h;
            return 0;
        }
        b += 17;
    } while (true);
}
*/

#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int a = 105700;
    int b = 122700;
    for (int i = a; i <= b; i += 17) {
        if (i % 2 == 0) {
            count++;
            continue;
        }
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
    }
    cout << count;
}