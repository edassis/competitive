#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    int a,b;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        int moves = 0;
        int dif = b - a;
        int aux = 10;
        
        if (dif < 0) aux *= -1;

        while(dif != 0) {   
            int q = dif / aux;

            if (dif > 0) {
                if (dif > 10) {
                    dif -= q * 10;
                    moves += q;
                } else if (aux <= dif) {
                    dif -= aux;
                    moves++;
                } else {
                    aux = dif;
                }
            } else {
                if (dif < -10) {
                    dif -= -(q * 10);
                    moves += q;
                } else if (aux >= dif) {
                    dif -= aux;
                    moves++;
                } else {
                    aux = dif;
                }
            }
        }

        cout << moves << endl;
    }
    return 0;
}