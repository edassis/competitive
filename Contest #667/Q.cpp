#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    long long n,x,y;
    vector<int> v;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> x >> y;

        int d = 2;
        
        while(true) {
            if (x % d == 0 && y % d == 0) break;
            if (d > 50) {
                d = 1;
                break;
            }
            else d++;
        }

        v.push_back(x);
        v.push_back(y);
        
        int j = 1;
        
        while(v.size() < n) {
            if (j != x && j != y) {
                if (j < x) {
                    if ((x - j) % d == 0) {
                        v.push_back(j);
                    }
                } else if (j < y) {
                    if ((y - j) % d == 0) {
                        v.push_back(j);
                    }
                } else {
                    if ((50 - j) % d == 0) {
                        v.push_back(j);
                    }
                }
            }
            j += d;
        }
        for (int k = 0; k < n; k++) {
            cout << v[k] << ' ';
        }
        cout << endl;
    }

    return 0;
}