// URI 1062 - Rails
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    do {
        cin >> n;

        if (n == 0) break;

        bool insert_line = true;
        do {
            vector<int> v_in;
            queue<int> request;
            stack<int> station;
            
            for (int i = 0; i < n; i++) {
                v_in.push_back(n - i);
                int aux;
                cin >> aux;
                request.push(aux);

                if (aux == 0) {
                    insert_line = false;
                    break;
                }
            }

            if (insert_line) {
                while (!request.empty()) {
                    if (!v_in.empty()) {  // tem vagões chegando
                        if (v_in.back() == request.front()) {
                            request.pop();
                            v_in.erase(v_in.end() - 1);
                        } else {
                            if (!station.empty() && station.top() == request.front()) {
                                request.pop();
                                station.pop();
                                // station.push(v_in.back() - 1);
                            } else {
                                station.push(v_in.back());
                                v_in.erase(v_in.end() - 1);
                                /* if (!station.empty() && station.top() > request.front()) {
                                    break;
                                } */
                            }
                        }
                    } else {
                        // Não é para acontecer da station ficar vazia antes de completar
                        if (!station.empty() && station.top() == request.front()) {
                            station.pop();
                            request.pop();
                        } else {
                            break;
                        }
                    }
                }
                if (request.empty())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        } while (insert_line);
        cout << '\n';
    } while (true);

    return 0;
}