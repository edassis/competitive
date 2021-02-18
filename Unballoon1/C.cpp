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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, f, p, t;
    cin >> b >> f >> p >> t;
    
    int total = b + f + (p * t);
    
    if (total >= 50) cout << "Cara, desiste" << '\n';
    else cout << "CORRE ALBERTO!" << '\n';

    return 0;
}