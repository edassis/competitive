#include <bits/stdc++.h>

using namespace std;

int main() {
    string cont;
    int pilhas_qtd = 0;
    vector<vector<int>> pilhas;
    vector<char> cont_ord;

    cin >> cont;
    
    pilhas.push_back(vector<int>());
    for (int i = 0; i < cont.size(); i++) {
        pilhas.back().push_back(cont[i]);
        cont_ord.push_back(cont[i]);
    }

    sort(cont_ord.begin(), cont_ord.end());

    // vector<int> pilha = pilhas.back();
    while(!pilhas.empty()) {
        for (int i = 0; i < pilhas.size(); i++) {
            if (pilhas[i].back() == cont_ord.front()) {
                pilhas[i].pop_back();
                cont_ord.erase(cont_ord.begin());
            } else {
                pilhas.push_back(vector<int>());
                vector<int> &nova_pilha = pilhas.back();
                pilhas_qtd++;
                
                char ele = cont_ord.front();
                while(ele == cont_ord.front()) {
                    // cout << it->back() << endl;
                    if (pilhas[i].back() != cont_ord.front()) {
                        nova_pilha.push_back(pilhas[i].back());
                        pilhas[i].pop_back();
                    } else {
                        pilhas[i].pop_back();
                        cont_ord.erase(cont_ord.begin());
                    }
                }
                break;
            }

            if (pilhas[i].empty()) {
                pilhas.erase(pilhas.begin()+i);
                break;
            }
        }
    }

    cout << pilhas_qtd + 1 << endl;

    return 0;
}