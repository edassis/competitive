#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vll = vector<pll>;
using ld = long double;
#define ff first
#define ss second
// const ld pi = acosl(-1);
const ll prime = 1000000000 + 7;
const ll INF = 1000000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<vll> listAdj(n+1);
    vector<map<ll, ll>> vet(n+1);
    for(int i = 0; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        listAdj[a].push_back({c, b});
        listAdj[b].push_back({c, a});
    }
    for(int i = 1; i <= n; ++i){
        ll k;
        cin >> k;
        vl vet3(k);
        for(int j = 0; j < k; ++j){
            cin >> vet3[j];
        }
        sort(vet3.begin(), vet3.end());
        ll aux = 0;
        for(int j = 0; j < k; ++j){
            if(aux < vet3[j]){
                vet[i][aux] = vet3[j]-1;
                aux = vet3[j] + 1;
            } else{
                aux = vet3[j] + 1;
            }      
        }
        vet[i][aux] = 0x3f3f3f3f3f3f3f3fLL;
        // for(auto&p:vet[i]){
        //     cout << p.ff << " " << p.ss << " | ";
        // }
        // cout << endl;
    }
    priority_queue<pll, vll, greater<pll>> fila;
    fila.push({0, 1});
    vl dist(n+1, -1);
    while(!fila.empty()){
        auto a = fila.top();
        fila.pop();
        if(dist[a.ss] == -1){
            if(a.ss == n){
                dist[a.ss] = a.ff;
                break;
            }
            auto it = vet[a.ss].upper_bound(a.ff);
            if(it != vet[a.ss].begin()){
                it--;
            }
            if(it->ff <= a.ff && a.ff <= it->ss){

            } else{
                if( a.ff > it->ss){
                    it++;
                }
                a.ff = it->ff;
            }
            dist[a.ss] = a.ff;
            for(auto&p: listAdj[a.ss]){
                if(dist[p.ss] == -1){
                    fila.push({a.ff + p.ff, p.ss});
                }
            }
        }
    }
    // for(int i = 1; i <= n; ++i){
    //     cout << dist[i] << " \n"[i == n];
    // }

    cout << dist[n] << "\n";

    return 0;
}