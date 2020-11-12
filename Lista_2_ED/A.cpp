#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int c, s;
    vector<int> estacionamento;
    bool can = true;
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> c >> s;

        while (!estacionamento.empty() && estacionamento.back() <= c) {
            estacionamento.pop_back();
        }

        if (!estacionamento.empty() && estacionamento.back() < s) {
            can = false;
            break;
        } else {
            estacionamento.push_back(s);
        }
    }

    if (can) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }

    return 0;
}