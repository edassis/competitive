#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t,n;
    long long a,b,x,y;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> x >> y >> n;


        long long aux1 = a - n;
        long long aux2 = b;
        long long sobra = 0;
        if (aux1 < x) {
            sobra = x - aux1;
            aux1 = x;

            aux2 -= sobra;
            if (aux2 < y) {
                aux2 = y;
            }
        }

        long long aux3 = a;
        long long aux4 = b - n;
        if (aux4 < y) {
            sobra = y - aux4;
            aux4 = y;

            aux3 -= sobra;
            if (aux3 < x) {
                aux3 = x;
            }
        }

        if (aux1*aux2 < aux3*aux4) {
            cout << aux1*aux2 << endl;
        } else {
            cout << aux3*aux4 << endl;
        }
    }
    return 0;
}