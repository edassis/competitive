#include <bits/stdc++.h>

using namespace std;

int main() {
    string cont;
    vector<vector<char>> pilhas;
    vector<char> cont_ord;

    cin >> cont;

    pilhas.push_back(vector<char>());
    for (unsigned i = 0; i < cont.size(); i++) {
        pilhas.back().push_back(cont[i]);
        cont_ord.push_back(cont[i]);
    }

    sort(cont_ord.begin(), cont_ord.end(), greater<char>());

    while (!cont_ord.empty()) {
        for (unsigned i = 0; i < pilhas.size(); i++) {
            int qtd = 0;
            for (unsigned j = 0; j < pilhas[i].size(); j++) {
                if (pilhas[i][j] == cont_ord.back()) {
                    qtd++;
                }
            }

            vector<char> nova_pilha;
            while (qtd) {
                if (pilhas[i].back() == cont_ord.back()) {
                    pilhas[i].pop_back();
                    cont_ord.pop_back();
                    qtd--;
                } else {  // Olhar pilhas e ver se pode inserir
                    int insert = -1;
                    for (unsigned j = 0; j < pilhas.size(); j++) {
                        if (j != i) {
                            if (pilhas[j].back() > pilhas[i].back()) {   // pode empilhar
                                insert = j;
                                break;
                            }
                        }
                    }

                    if (insert >= 0) {
                        pilhas[insert].push_back(pilhas[i].back());
                        pilhas[i].pop_back();
                    } else {        // usar nova pilha
                        nova_pilha.push_back(pilhas[i].back());
                        pilhas[i].pop_back();
                    }
                }
            }
            if (!nova_pilha.empty()) {
                pilhas.push_back(nova_pilha);
            }
        }
    }

    cout << pilhas.size() << endl;

    return 0;
}
// Elementos em "nova_pilha" não são checados.