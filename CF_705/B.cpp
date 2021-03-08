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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        string h, m;
        cin >> h >> m;

        string s, aux;
        cin >> s;
        
        char &h1 = aux[0], &h2 = aux[1], &m1 = aux[3], &m2 = aux[4];
        
        while(true) {
            aux = s;
            int counter = 0;

            for (int i = 0; i < 5; i++) {
                if (s[i] == '0') {
                    aux[i] = '0';
                    counter++;
                }
                else if (s[i] == '1') {
                    aux[i] = '1';
                    counter++;
                }
                else if (s[i] == '2') {
                    aux[i]= '5';
                    counter++;
                }
                else if (s[i] == '5') {
                    aux[i] = '2';
                    counter++;
                }
                else if (s[i] == '8') {
                    aux[i] = '8';
                    counter++;
                }
            }

            aux = {m2, m1, ':', h2, h1};

            if(counter == 4 && aux.substr(0, 2) < h && aux.substr(3, 2) < m) {
                W(s);
                cout << s << '\n';
                break;
            }

            int hour = stoi(s.substr(0,2));
            int min = stoi(s.substr(3,2));
            min++;

            if (min == stoi(m)) {
                hour++;

                if (hour == stoi(h)) {
                    hour = 0;
                    min = 0;
                }
            }
            
            if (hour < 10) {
                s = '0' + to_string(hour);
            } else {
                s = to_string(hour);
            }

            if (min < 10) {
                s += ":0" + to_string(min);
            } else {
                s += ':' + to_string(min);
            }
        }
    }
    
    return 0;
}