#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

#define MAX 10000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vi ehprimo(MAX+1, true);
    ehprimo[0] = false;
    ehprimo[1] = false;
    
    vi primos;
    primos.pb(2);
    for(int i = 3; i <= MAX; i+=2) {
        ehprimo[i+1] = false;
        if (ehprimo[i]) {
            primos.pb(i);
            for (int j = i + i; j <= MAX; j += i) {
                ehprimo[j] = false;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        string n;
        cin >> n;

        char res = 'S';
        for (size_t j = 0; j < n.size(); j++) {
            string s = n.substr(0, n.size() - j);
            int num = stoi(s);
            if (!ehprimo[num])  {
                res = 'N';
                break;
            } 
        }
        cout << res << endl;
    }
    return 0;
}