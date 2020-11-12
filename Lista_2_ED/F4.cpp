// F. Containers II
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int can_insert(char &c, vector<string> &pilhas) {
    for (unsigned i = 0; i < pilhas.size(); i++) {
        if (c <= pilhas[i].back()) {
            return i;
        }
    }

    return -1;
}

void add_cont(char &c, vector<string> &pilhas) {
    if (!pilhas.empty()) {
        int pos = can_insert(c, pilhas);
        if (pos != -1) {
            pilhas[pos].pb(c);
        } else {
            pilhas.pb(string(1, c));
        }
    } else {
        pilhas.pb(string(1, c));
    }
}

int main() {
    string cont;
    vector<string> pilhas;

    cin >> cont;

    while (!cont.empty()) {
        char menor = 'Z';
        unsigned menor_idx = -1;
        for (unsigned i = 0; i < cont.size(); i++) {
            if (menor > cont[i] || i == 0) {
                menor = cont[i];
                menor_idx = i;
            }
        }
        int menor_qtd = 0;
        for (unsigned i = menor_idx; i < cont.size(); i++) {
            if (menor == cont[i]) {
                menor_qtd++;
            }
        }
        while (menor_qtd) {
            for (unsigned i = 0; i < cont.size();) {
                if (i < menor_idx && cont[i] > menor) {
                    add_cont(cont[i], pilhas);
                    cont.erase(cont.begin() + i);
                } else if (cont[i] == menor) {
                    add_cont(cont[i], pilhas);
                    cont.erase(cont.begin() + i);
                    menor_qtd--;
                } else {
                    i++;
                }
            }
        }
    }

    cout << pilhas.size() << endl;

    return 0;
}