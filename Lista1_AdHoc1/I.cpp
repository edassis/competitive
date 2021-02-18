// I. Quebra-Cabeça
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

    map<char, int> letra;
    string s_in;
    cin >> s_in;

    for (unsigned i = 0; i < s_in.size(); i++) letra[s_in[i]]++;

    int qtd_impar = 0;

    for (auto &e : letra) if (e.ss % 2) qtd_impar++;

    if (qtd_impar > 1) cout << "Nao" << endl;
    else cout << "Sim" << endl;

    return 0;
}