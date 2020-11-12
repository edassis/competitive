#include <bits/stdc++.h>

using namespace std;

int main() {
    string cont;
    int menor_pos = 0;
    int perm = 0;

    cin >> cont;

    for (int i = cont.size() - 1; i >= 0; i--) {
        for (int j = 0; j < cont.size(); j++) {
            if (cont[menor_pos] > cont[j] || j == 0) {
                menor_pos = j;
            }
        }
        if (cont[menor_pos] < cont[i]) {
            char aux = cont[i];
            cont[i] = cont[menor_pos];
            cont[menor_pos] = aux;
            perm++;
        }

    }

    cout << perm + 1 << endl;

    return 0;
}