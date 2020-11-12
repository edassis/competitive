#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, c;
    int grav;
    vector<int> pr;
    int contador = 0;
    int maneiras = 0;
    cin >> n >> t >> c;

    for (int i = 0; i < n; i++) {
        cin >> grav;
        pr.push_back(grav);
    }

    for (int i = 0; i < n; i++) {
        if (pr[i] <= t) {
            contador++;
            for (int j = 1; j < c; j++) {
                if (i+j < n && pr[i+j] <= t) contador++;
                else break;
            }

            if (contador == c) maneiras++;
            contador = 0;
        }
    }

    cout << maneiras << endl;

    return 0;
}