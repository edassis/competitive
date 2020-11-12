#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;

    cin >> n;
    
    vector<ii> atletas;
    vector<ii> poss;

    for (int i = 0; i < n; i++) {
        ii atleta;
        cin >> atleta.first;
        atleta.second = i;
        atletas.push_back(atleta);
    }

    sort(atletas.begin(), atletas.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return a.first < b.first;
    });

    int contador = 1;
    poss.push_back({contador, atletas[0].second});

    for (int i = 1; i < n; i++) {
        if (atletas[i].first != atletas[i-1].first)
            contador = i + 1;
        
        poss.push_back({contador, atletas[i].second});
    }

    sort(poss.begin(), poss.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << poss[i].first << ' ';
    }
    cout << endl;

    return 0;
}