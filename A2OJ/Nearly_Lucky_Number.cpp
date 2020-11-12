#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    long long n;
    
    cin >> n;

    string s;

    s = to_string(n);

    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4' || s[i] == '7') {
            counter++;
        }
    }

    if (counter == 4 || counter == 7) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}