#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    // vector<bool> ehprimo(n+1, true);
    // ehprimo[0] = false;
    // ehprimo[1] = false;

    // vi primos;
    // primos.pb(2);

    // for (int i = 3; i*i*i <= n; i+=2) {
    //     ehprimo[i + 1] = false;
    //     if (ehprimo[i]) {
    //         primos.pb(i);
    //         for (int j = i+i; j <= n; j += i) {
    //             ehprimo[j] = false;
    //         }
    //     }
    // }
    
    // int res = -1;
    // for (auto& e:primos) {
    //     if (e*e*e == n) {
    //         res = e;
    //         break;
    //     }
    // }
    int res = -1;
    for (int i = 1; i*i*i <= n; i++) {
        if (i*i*i == n) {
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}