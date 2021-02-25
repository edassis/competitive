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

    int n;
    int maior, menor;
    int amazing = 0;
    cin >> n;
    
    int x;
    cin >> x;
    maior = x;
    menor = x;
    for (int i = 1; i < n; i++) {
        cin >> x;

        if (x > maior) { 
            amazing++;
            maior = x;
        }
        if (x < menor) {
            amazing++;
            menor = x;
        }
    }
    
    cout << amazing << endl;
    
    return 0;
}