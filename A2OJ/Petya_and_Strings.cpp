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

    string s1, s2;
    cin >> s1 >> s2;

    for (size_t i = 0; i < s1.size(); i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    
    if (s1 > s2) {
        cout << 1 << endl;
    } else if(s1 < s2) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}