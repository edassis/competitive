#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

const int N = 1000000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n,m,r,c;
        cin >> n >> m >> r >> c;

        ll soma_final = 0;
        ll aux1 = m - c;
        ll aux2 = m - (aux1 + 1);
        soma_final += max(aux1, aux2);
        
        // movendo pela linha
        aux1 = n - r;
        aux2 = n - (aux1 + 1);
        soma_final += max(aux1, aux2);
        
        cout << soma_final << endl;
    }

    return 0;
}