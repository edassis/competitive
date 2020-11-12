#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;
    int vet_x = 0, vet_y = 0, vet_z = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        vet_x += x;
        vet_y += y;
        vet_z += z;
    }

    if (!vet_x && !vet_y && !vet_z) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}