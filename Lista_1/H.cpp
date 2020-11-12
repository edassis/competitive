// Algumas somas
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    int ac = 0;

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        string s_i = to_string(i);
        
        int soma = 0;
        
        for (char &c:s_i) {
            soma += c - '0';
        }

        if (soma >= a && soma <= b) ac += i;
    }
    
    cout << ac << '\n';

    return 0;
}