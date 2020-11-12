// Deivis e as velas
#include <bits/stdc++.h>

using namespace std;

bool decresc(int a, int b) {
    return a > b;
}

int main() {
    int n, k;
    int time = 0;
    int used = 0;

    cin >> n >> k;

    while (n > 0) {
        n--;
        used++;
        time++;


        if (used == k) {
            n++;
            used -= k;
        }
    }

    cout << time << endl;

    return 0;
}