#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

string query(int x) {
    cout << x << '\n';
    cout.flush();

    string ret;
    cin >> ret;
    return ret;
}

int main() {
    int n;

    cin >> n;
    
    ll l = 1, r = n;
    ll res;
    while(l <= r) {
        ll mid = (l+r)/2;
    
        string ret = query(mid);

        if (ret == "<") {
            r = mid - 1;
        } else if (ret == ">"){
            l = mid + 1;
        } else if (ret == "-") {
            res = mid;
            break;
        }
    }

    cout << "! " << to_string(res) << endl;
    cout.flush();
    
    return 0;
}