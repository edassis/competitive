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

    for (int i = 0; i < n; i++) {
        cin >> pontos[i];
        soma += pontos[i];
    }

    bool stop = false;
    vector<bool> mask(n, false);        // ponto inicial de cada segmento

    ll comp = 0;
    ll target = soma / 3;
    int retas = 0;
    int qtd = 0;

    if (soma % 3) stop = true;

    for (int i = 0; i < n && !stop; i++) {
        if (mask[i] == true) {
            stop = true;
            continue;
        }

        comp = pontos[i];
        int idx = i + 1;
        vector<bool> mask_aux(mask);
        mask_aux[i] = true;

        while (true) {
            int cor_idx;
            if (idx >= n) cor_idx = idx - n;
            else cor_idx = idx;

            if (comp > target)
                break;
            else if (comp < target) {
                if (cor_idx != i) {  // ainda n deu uma volta
                    if (comp == 0)
                        mask_aux[cor_idx] = true;
                    
                    comp += pontos[cor_idx];
                    idx++;
                } else
                    break;  // deu uma volta

            } else {    // comp == target
                retas++;
                comp = 0;
            }
        }
        if (retas == 3) {
            mask = mask_aux;
            qtd++;
        } 
        retas = 0;
    }

    cout << qtd << endl;

    return 0;
}