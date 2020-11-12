#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    while (cin >> n, n != 0) {
        m = 2;

        vector<bool> city;
        int contador = m;
        // int false_qtd = 0;
        bool stop = false;

        while (!stop) {  // achar o m
            city = vector<bool>(n, true);
            contador = m;

            while (true) {
                for (int i = 0; i < n; i++) {
                    if (city[i] == true) {
                        if (contador == m) {
                            city[i] = false;
                            contador = 0;
                        }
                        contador++;
                    } /* else {
                        if (city[i] == false) {
                            contador++;
                        }
                    } */
                }

                int false_qtd = 0;
                for (int i = 0; i < n; i++) {
                    if (city[i] == false) {
                        false_qtd++;
                    }
                }

                if (false_qtd == n) {
                    cout << m << endl;
                    stop = true;
                    break;
                } else {  // tem true, e o 13 é false
                    if (city[13 - 1] == false) {
                        m++;
                        break;
                    }
                }
            }

        }
    }
    return 0;
}