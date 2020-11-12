#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

#define MAX 10000

int main() {
    int t;
    cin >> t;
    vector<string> x(t);

    for (int i = 0; i < t; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < t; i++) {
        string aux = "1";
        int qtd = 1;
        while (aux != x[i]) {
            aux = aux + aux[aux.size() - 1];
            int num = stoi(aux);
            if (num > MAX) {
                aux = aux[0] + 1;
            }
            qtd += aux.size();
        }
        cout << qtd << endl;
    }
    return 0;
}