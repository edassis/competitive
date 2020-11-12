// D. Atendimento
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;  // func, clientes
    int tempo = 0;
    vector<int> func;           // vel./item
    vector<vector<int>> caixa;  // historico
    queue<int> cliente;         // items

    cin >> n >> m;

    caixa = vector<vector<int>>(n);

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        func.push_back(aux);
    }

    for (int i = 0; i < m; i++) {
        int aux;
        cin >> aux;
        cliente.push(aux);
    }

    for (int i = 0; i < n && !cliente.empty(); i++) {
        caixa[i].push_back(cliente.front() * func[i]);
        cliente.pop();
    }

    while (!cliente.empty()) {
        int idx = 0;
        int menor_tempo = 0;

        for (int i = 0; i < n; i++) {  // olhando funcionario.ativo
            int sum = 0;

            for (int j = 0; j < caixa[i].size(); j++) {
                sum += caixa[i][j];
            }

            if (i == 0 || sum < menor_tempo) {
                menor_tempo = sum;
                idx = i;
            }
        }

        caixa[idx].push_back(cliente.front() * func[idx]);
        cliente.pop();
    }

    for (int i = 0; i < n; i++) {
        int soma = 0;

        for (int j = 0; j < caixa[i].size(); j++) {
            soma += caixa[i][j];
        }

        if (soma > tempo) tempo = soma;
    }

    cout << tempo << endl;

    return 0;
}