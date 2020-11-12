#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = 0;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
    
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        
        if (s[i] == s[i+1]) counter++;
    }

    cout << counter << '\n';

    return 0;
}