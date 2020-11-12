#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int p, n;
    cin >> p >> n;

    stack<int> alt;
    for (int i = 0; i < n; i++) {
        int forma, qtd;
        cin >> forma >> qtd;
        
        if (forma == 1) {
            alt.push(qtd);
        } else if (forma == 2) {
            for (int j = 0; j < qtd; j++)
                alt.pop();
        }
    }

    while(!alt.empty()) {
        p += alt.top();
        alt.pop();
    }

    cout << p << endl;

    return 0;
}