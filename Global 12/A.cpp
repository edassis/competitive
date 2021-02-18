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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l;
        string s;
        cin >> l >> s;
        string s2;
        int qtd = 0;
        char cond[] = "      ";
        for (int j = 0; j < l; j++) {
            if (s[j] == 'b') qtd++;
            
            if (s[j] == 't' && cond[0] == ' ') cond[0] = 't';
            if (s[j] == 'r' && cond[1] == ' ') cond[1] = 'r';
            if (s[j] == 'y' && cond[2] == ' ') cond[2] = 'y';
            if (s[j] == 'g' && cond[3] == ' ') cond[3] = 'g';
            if (s[j] == 'u' && cond[4] == ' ') cond[4] = 'u';
            if (s[j] == 'b' && cond[5] == ' ') cond[5] = 'b';

        }

        if (strcmp("trygub", cond) == 0) {
            while (qtd) {
                s2.pb('b');
                qtd--;
            }
            for (int j = 0; j < l; j++) {
                if (s[j] != 'b') s2.pb(s[j]);
            }
        } else s2 = s;

        cout << s2 << endl;
    }
    return 0;
}