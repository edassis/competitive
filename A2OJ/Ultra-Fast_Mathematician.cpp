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

    string n1, n2;
    cin >> n1 >> n2;

    for (unsigned i = 0; i < n1.size(); i++) {
        if (n1[i] != n2[i]) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;
    
    return 0;
}