#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

string query(int x) {
    cout << x << '\n';
    cout.flush();

    string ret;
    cin >> ret;
    return ret;
}

int main() {
    int l = 1, r = 1000000;
    int res = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        string aux = query(mid);
        if (aux == "<") {
            r = mid - 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }

    cout << "! " << res << endl;
    cout.flush();
    return 0;
}