#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

bool order(ii a, ii b) {
    return a.ss < b.ss;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ii> pres(n, {0, 0});

    for (int i = 0; i < n; i++) {
        pres[i].ff = i;
        cin >> pres[i].ss;
    }

    sort(pres.begin(), pres.end(), order);

    for (int i = 0; i < n; i++)
    {
        cout << pres[i].ff+1 << ' ';
    }

    cout << endl;
    
    return 0;
}