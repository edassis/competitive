#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

// Types
using ll = long long;
using pii = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;

// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define endl '\n'
#define forn(i, n) for(int i=0; i<(int)n; i++)
#define forni(i, k, n) for(int i=k; i<(int)n; i++)
#define forne(i, k, n) for(int i=k; i<=(int)n; i++)
#define fora(e, a) for(auto e:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// Functions
template<typename T>
inline void clr(T& x) { memset(x, 0, sizeof(x)); }
inline void sws() { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }

// Constants
const ll MOD = 1e9+7;
const ll oo = 1e18+7;

class DSU {
    vi p;
    vi size;
public:
    DSU(int n) : p(n+1), size(n+1, 1) {
        iota(all(p), 0);
    }

    void insert(int a, int b) {
        // vai para o pai
        a = query(a);
        b = query(b);

        // Mesmo pai
        if(a == b) return;

        // balancamento
        if(size[a] > size[b]) {
            swap(a, b);
        }

        // b maior
        size[b] += size[a];
        p[a] = b;
    }

    int query(int e) {
        // Compressão
        return (e == p[e]) ? (e) : ( p[e] = query(p[e]) );
        // return (e == p[e]) ? (e) : ( query(p[e]) );
    }

    bool same_set(int a, int b) {
        return query(a) == query(b);
    }
};

const int MAXR = 1e4+5;
int r, c, q;
vi adj[MAXR];
int visited[MAXR];
void dfs(int s, int &t, set<int> &inCycle) {
    
    visited[s]++;
    W(s);
    W(visited[s]);
    for(auto v : adj[s]) {
        if(!visited[v] && !inCycle.count(v)) {
            dfs(v, t, inCycle);
        } 
    }
}

int main() {
    sws();
 
    clr(visited);
    while(cin >> r >> c >> q, r != 0) {
        clr(adj);
        DSU dsu(r);
        set<int> inCycle;

        forn(i, c) {
            int a, b; cin >> a >> b;

            if(dsu.same_set(a, b)) {
                inCycle.insert(a);
                inCycle.insert(b);
            }

            adj[a].pb(b);
            adj[b].pb(a);
            dsu.insert(a, b);
        }

        forn(i, q) {
            int s,t; cin >> s >> t;

            clr(visited);
            dfs(s, t, inCycle);

            cout << (visited[t] ? 'Y':'N') << endl;
        }

        cout << '-' << endl;
    }

    return 0;
}

// Usando dfs, eu consigo pegar caminhos que passam
// por diferentes nodes ate o alvo mas n consigo
// pegar caminhos diferentes que utilizam os mesmos nodes.

// Ideia: Uso a dfs para calcular se algum no é visitado mais de 
// 1 vez, guardo num vetor, uso segtree para consultar a
// soma rapidamente. Se soma > 0, ciclos.

// Usando um vetor auxiliar para contar nodes v já visitados
// na dfs faz com que ela conte tanto o node que comeca
// quanto o que termina.

// Como avaliar somente 1 caminho por vez entre s e t
// e não o grafo inteiro?

// O caminho desejado tem r-1 arestas obrigatoriamente. Ou seja,
// todo subgrupo rs do caminho tem rs-1 arestas.

// Para cada node s
    // Se o prox n for o alvo e for uma folha, desconsidera
    // Se formar um ciclo, desconsidera
    // Caso contrario, v faz parte do caminho

// fazer dsu para saber conexoes
// a cada insert conferir se nodes ja pertenciam
// se sim, os nodes pertencem a um ciclo
// nas queries, fazer uma dfs somente nas arestas
// que n fazem parte do ciclo
// se t for visitado, entao eh pq existe um caminho
// formado por pontes