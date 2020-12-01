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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;

        int jumps = 0;
        // set<int> visitado;
        queue<ii> q;
        q.emplace(0, 0);
        while(q.size()) {
            auto u = q.front(); q.pop();
            // visitado.emplace(u.second);
            
            if (u.second == x) {
                jumps = u.first;
                break;
            }
            
            if (u.second+u.first+1 <= x) {
                q.emplace(u.first+1, u.second+u.first+1);
            }
            if ()
            q.emplace(u.first+1, u.second-1);
            // if (!visitado.count(u.second+u.first+1)) {
            // }
            // if (!visitado.count(u.second-1)) {
            // }
        }

        cout << jumps << endl;
    }
    return 0;
}