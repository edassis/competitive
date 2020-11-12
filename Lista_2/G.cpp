// G. Estoque
#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    int t, m;
    map<int, int> estoque;
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t >> m;

        if (t == 1) {
            estoque[m]++;
            // if (estoque.count(m)) estoque[m]++;
            // else estoque[m] = 1;
        } else if (t == 2) {
            int present = estoque.count(m);
            if (present) {
                cout << "Sim" << endl;
            } else {
                cout << "Nao" << endl;
            }
        }
    }
    return 0;
}