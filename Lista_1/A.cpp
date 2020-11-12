// Deivis e os vetores
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int vec_1[n], vec_2[n];

    for (int i = 0; i < n; i++) {
        cin >> vec_1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vec_2[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x == vec_1[i] + vec_2[j]) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    
    return 0;
}