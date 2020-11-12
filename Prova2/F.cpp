#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

string int_to_string(int n) {
    string ans;

    while (n > 0) {
        ans.pb(n % 10 + '0');
        n /= 10;
    }

    int x = ans.size();
    for (int i = 0; i < x / 2; i++)
        swap(ans[i], ans[x - i - 1]);

    return ans;
}

string soma_digitos(string s) {

    int aux = 0;
    while (s.size() > 1) {
        aux = 0;
        for (unsigned i = 0; i < s.size(); i++) {
            aux += s[i] - '0';
        }

        s = int_to_string(aux);
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string b, e;
    cin >> b >> e;

    b = soma_digitos(b);
    e = soma_digitos(e);
    
    int x = e.front() - '0';
    
    int auxb = 1;
    int pot = b.front() - '0';
    for (int i = 1; i <= x; i++) {
        auxb *= pot;
        b = soma_digitos(int_to_string(auxb));
        auxb = b.front() - '0';
    }

    cout << auxb << endl;

    return 0;
}