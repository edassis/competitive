// E. Papai Noel
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    char c;
    
    stack<int> s;
    stack<int> maior;
    maior.emplace(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c >> x;

        if (c == 'A') {
            s.emplace(x);
            if (x > maior.top()) maior.emplace(x);
            else maior.emplace(maior.top());
        } else if (c == 'V') {
            cout << maior.top() << '\n';
        } else if (c == 'R') {
            s.pop();
            maior.pop();
        }
    }

    return 0;
}