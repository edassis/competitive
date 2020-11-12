#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int fast_exp(int base, int e) {
    if (e == 0)
        return 1;
    if (e % 2)
        return base * fast_exp(base * base, e / 2);
    else
        return fast_exp(base * base, e / 2);
}

int main() {
    int n, e;

    cin >> n >> e;

    cout << fast_exp(n, e) << endl;

    return 0;
}