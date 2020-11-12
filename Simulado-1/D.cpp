#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int x, y, z;
    int m, n;
    
    cin >> x >> y >> z;
    
    map<char, int> cupim {
        {'F', x},
        {'A', y},
        {'R', z}
    };
    
    cin >> m >> n;

    vi tamandua(1, m);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        
        bool comeu = false;
        for (auto &t:tamandua) {
            if (t >= cupim[c]) {
                t -= cupim[c];
                comeu = true;
                break;
            }
        }
        if (!comeu) {
            tamandua.push_back(m - cupim[c]);
        }
    }

    cout << tamandua.size() << endl;
    return 0;
}