#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;

        bool saca = true;
        int vez = 0;
        int p_a = 0, p_b = 0;
        while (a || b) {
            if (saca) {
                if (vez == 0) {
                    a--;
                    vez = 1;
                } else {
                    b--;
                    vez = 0;
                }
                saca = false;
            } else {
                if (vez == 0) {
                    if (a) {
                        if (a <= b) {
                            p_b++;
                            saca = true;
                            vez = 1;
                        } else {  // rebate
                            a--;
                            vez = 1;
                        }
                    } else {  // sem stamina
                        p_b++;
                        saca = true;
                        vez = 1;
                    }
                } else {    // vez == 1
                    if (b) {
                        if (b <= a) {
                            p_a++;
                            saca = true;
                            vez = 0;
                        } else {  // rebate
                            b--;
                            vez = 0;
                        }
                    } else {  // sem stamina
                        p_a++;
                        saca = true;
                        vez = 0;
                    }
                }
            }
        }
        if (vez) p_a++;     // vez do b
        else p_b++;

        cout << p_a << ' ' << p_b << endl;
    }
    return 0;
}