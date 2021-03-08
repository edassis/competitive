#include <bits/stdc++.h>

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

#define PRIME 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {      
        int x;
        cin >> x;

        int step = 1;
        while (step*(step+1) < 2*x) step++;

        if ( step*(step+1)/2 == x+1) step++;

        cout << step << '\n';
    }

    return 0;
}