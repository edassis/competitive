#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int fast_exp(ll b, ll e) {
    if (e == 0)
        return 1;

    if (e % 2) {
        return b * fast_exp(b*b, e/2);
    }
    return fast_exp(b*b, e/2);
}

int conv_int(string s) {
    int n = 0;
    size_t pos = s.find('.');
    s.erase(s.begin()+pos, s.begin()+pos+1);

    for(size_t i = 0; i < s.size(); i++) {
        n += (s[i] - '0') * fast_exp(10, s.size() - i - 1);
    }

    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;
    
    int x = conv_int(in);
    // cout << x << endl;
    int divisor = gcd(36000, x);
    int res = 36000 / divisor;
    
    cout << res << endl;
    return 0;
}