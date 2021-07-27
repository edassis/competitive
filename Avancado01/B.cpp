#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vl  vector<ll>
#define vll vector<lll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define mt  make_tuple
#define ii  pair<int, int>
#define lll pair<ll, ll>
#define ff  first
#define ss  second
#define sws                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl    '\n'
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x)  memset(x, 0, sizeof(x))

const ll prime = 1e9 + 7;
const ll oo    = 1e18 + 7;

int main() {
    sws;

    int t;
    cin >> t;
    char tab[] = {'a', 'b', 'c'};

    while (t--) {
        string s;
        char   c;
        int    pos = -1, len = 0;
        int    idx = 0;

        do {
            if (c == '?') {
                if (pos != -1) { // ++
                    len++;
                } else { // nova subst
                    pos = idx;
                    len = 1;
                }
            } else {
                if (pos != -1) { // tinha '?' e mudou char
                    char l1 = 'a', l2 = 'b';
                    
                    if (pos > 0) {
                        l1 = 'a' + ('a' - s[pos-1]+1) % 3;
                        if (s[pos-1] == 'a' && l1 == 'b') l2 = 'c';
                        else if (s[pos-1] == 'a' && l1 == 'c') l2 = 'b';
                        else if (s[pos-1] == 'b' && l1 == 'c') l2 = 'a';
                    } else if (pos+len <= s.size()) {
                        l1 = 'a' + ('a' - s[pos+len]+1) % 3;
                        l2 = 'a' + ('a' - l1+1) % 3;
                    }

                    for(unsigned j = pos; j < s.size(); j+=2) {
                        s[j] = l1;
                        if(j-pos+1 <= len) {
                            s[j+1] = l2;
                        } else {
                            break;
                        }
                    }
                }
                idx++;
                s.pb(c);
            }
        } while (c != '\n');
    }

    return 0;
}