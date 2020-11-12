#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n;
    
    cin >> n;
    vi pontos(n);
    ll soma = 0;
    vector<ll> psum(n);

    for (int i = 0; i < n; i++) {
        cin >> pontos[i];
        soma += pontos[i];
    }

    ll target = soma / 3;
    psum[0] = pontos[0]; 
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + pontos[i];
    }