// C. Formigas
#include <bits/stdc++.h>

using namespace std;

int main() {
    int ra = false;
    int contador = 0;
    int total = 0;
    string s;
    
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'r') {
            if (ra) {
                total += contador;
                contador = 0;
            } else {
                ra = true;
            }
        } else if (s[i] == 's') {
            if (ra) {
                ra = false;
                contador = 0;
            }
        } else if (s[i] == '.') {
            if (ra) {
                contador++;
            }
        }
    }

    if (contador) total += contador;

    cout << total << endl;

    return 0;
}