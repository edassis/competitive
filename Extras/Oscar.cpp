#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
    #define W(x, y)
#endif
 
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
// #define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acosl(-1)
#define ld long double
#define prime (1000000000 + 7)
#define INF 1000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    ll n;
    while(cin >> n, n != 0){
        vl vet(n);
        while(cin >> vet[0], vet[0] != 0){
            for(int i = 1; i < n; ++i){
                cin >> vet[i];
                if(vet[0] == 0){
                    break;
                }
            }
            ll ind = 0;
            stack<ll> pilha;
            pilha.push(0);
            for(int i = 1; i <= n; ++i){
                while(pilha.top() == vet[ind] && ind < n){
                    ind++;
                    pilha.pop();
                }
                pilha.push(i);
            }
            while(pilha.top() == vet[ind] && ind < n){
                ind++;
                pilha.pop();
            }
            if(pilha.size() == 1){
                cout << "Yes" << "\n";
            } else{
                cout << "No" << "\n";
            }
        }
        cout << endl;
    }
 
    return 0;
}
