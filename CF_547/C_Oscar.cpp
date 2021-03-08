#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
	#define W(x)
#endif


#define ll long long
#define pii pair<int, int >
#define piii pair<int, pii >
#define pll pair<ll, ll >
#define vi vector<int>
#define vii vector<pii>
#define viii vector<piii>
#define vl vector<ll >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acos(-1)

using namespace std;

#define prime 1000000007

int main(){
	ll n;
	scanf("%lld", &n);
	vl vet(n-1), res;
	vl pref(n+1, 0);
	set<ll> seti;
	ll menor = 1e6;
	ll maior = -1e6;
	for(ll i = 0; i < n-1; i++){
		ll&p = vet[i];
		scanf("%lld", &p);
		pref[i+1] = pref[i] + p;
		menor = min(menor, pref[i+1]);
		maior = max(maior, pref[i+1]);
	}
	res.pb(menor <= 0 ? -menor + 1 : menor);
	seti.insert(menor <= 0 ? -menor + 1 : menor);
	for(ll i = 1; i < n; i++){
		ll aux = +pref[i] + (menor <= 0 ? -menor + 1 : menor);
		res.pb(aux);
		seti.insert(aux);
	}
	W(maior-menor)
	W(maior)
	W(menor)
	W(seti.size())
	W( maior + (menor <= 0 ? -menor + 1 : menor))
	W((menor <= 0 ? -menor + 1 : menor))
	if(seti.size() < n || maior + (menor <= 0 ? -menor + 1 : menor) > n || (menor <= 0 ? -menor + 1 : menor) > n)
		printf("-1\n");
	else {
		for(ll&p: res){
			printf("%lld ", p);
		}
	}
	return 0;
}