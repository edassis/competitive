#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

#define MAX 1000000007

ll fat_mod(ll a) {
    if(a == 1)
        return a;
    
    return (a * fat_mod(a - 1)) % MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << (fat_mod(a) + fat_mod(b)) % MAX << endl;

    return 0;
}