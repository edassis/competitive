// B. Parênteses
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f, p;

    queue<int> carros;

    cin >> n >> f >> p;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        carros.push(aux);
    }

    int time = 0;
    int i = 0;

    while (!carros.empty()) {
        int carro = carros.front();
        carros.pop();
        
        if (i % f == 0) {
            if (carro > p) {
                carro -= 2;
                carros.push(carro);
                time += 10;
            } else {
                time += 5;
            }
        } else {
            time++;
        }
        i++;
    }

    cout << time << endl;

    return 0;
}