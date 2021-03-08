#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1000000007

ll toInt(string s) {
    ll ans = 0;
    
    for (size_t i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0') ;
    }

    return ans;
}

string toString(ll x) {
    string s;

    do {
        s.push_back((x % 10) + '0');;
    } while(x /= 10);

    reverse(s.begin(), s.end());

    return s;
}

int next_valid(int x, vi &v) {
    unsigned ans;

    for (ans = 0; ans < v.size(); ans++) if (v[ans] >= x) break;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int h, m; cin >> h >> m;
        string s; cin >> s;

        int ih = toInt(s.substr(0, 2));
        int im = toInt(s.substr(3, 2));
        
        vi validos = {0,1,2,5,8};

        int aux = ih % 10;
        unsigned i;
        i = next_valid(aux, validos);

        if(i == validos.size()) {
            ih = ih/10 + 10;
        }
        else ih = ih/10 + validos[i];

        aux = ih / 10;
    
        i = next_valid(aux, validos);

        if(i == validos.size()) {  
            ih = ih % 10;
        }
        else ih = validos[i]*10 + ih%10;
        
        //
        aux = im % 10;
        
        i = next_valid(aux, validos);

        if(i == validos.size()) {
            im = im/10 + 10;
        }
        else im = im/10 + validos[i];

        aux = im / 10;

        i = next_valid(aux, validos);

        if(i == validos.size()) {
            im = im % 10;
        }
        else im = im%10 + validos[i]*10;

        ih = ih % h;
        im = im % m;

        cout << setw(2) << setfill('0') << ih << ':' << setw(2) << setfill('0') << im << '\n';
    }

    return 0;
}