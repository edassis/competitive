#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vl vector<ll>
#define vll vector<lll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ii pair<int,int>
#define lll pair<ll, ll>
#define ff first
#define ss second
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll prime = 1e9+7;
const ll oo = 1e18+7;

int main() {
    sws;

    int t; cin >> t;
    vii s(4);

    while(t--) {
        for(int i = 0; i < 4; i++) {
            cin >> s[i].ss;
            s[i].ff = i+1;
        }
        
        sort(all(s), [](ii a, ii b) {
            return a.ss >= b.ss;
        });

        if((s[0].ff == 1 && s[1].ff == 2) || (s[0].ff == 2 && s[1].ff == 1)) {
            cout << "NO" << endl;
        } 
        else if((s[0].ff == 3 && s[1].ff == 4) || (s[0].ff == 4 && s[1].ff == 3)) {
            cout << "NO" << endl;
        } 
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}