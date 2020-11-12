#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    string t, p;
    vector<pair<char, int>> palavra;
    queue<int> idx;
    int contador = 0;

    cin >> t >> p;

    for (unsigned i = 0; i < t.size(); i++) {
        int aux;
        cin >> aux;
        idx.push(aux - 1);

        // ----
        palavra.pb(mp(t[i], i));
    }

    while (!idx.empty()) {
        int l = 0, r = palavra.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (palavra[mid].second == idx.front()) {
                palavra.erase(palavra.begin() + mid);
                idx.pop();
                break;
            } else {
                if (palavra[mid].second > idx.front()) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        unsigned pos_p = 0;
        for (unsigned i = 0; i < palavra.size() && pos_p < p.size(); i++) {
            if (palavra[i].first == p[pos_p]) {
                pos_p++;
            }
        }

        if (pos_p == p.size()) {
            contador++;
        } else {
            break;
        }
    }

    cout << contador << endl;

    return 0;
}