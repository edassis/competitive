#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1e9+7

const int N = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    ii A; cin >> A.ff;
    A.ss = 0;

    map<int, int> cor;
    
    for (int i = 0; i < N; i++) {
        cor.emplace(i+1, 0);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == A.ff) A.ss++;
        else if (cor[x] >= 0) {      // cor valida
            if (cor[x] >= A.ss) {
                cor[x]++;            // candidata
            } else {   
                cor[x] = -1;     // remove cor candidata
            }
        } 
    }
    
    for (auto& each : cor) {
        if (each.ss >= A.ss && each.ff != A.ff) {
            cout << each.ff << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}