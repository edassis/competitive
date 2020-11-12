// H. Papai Noel
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    char c;
    int x;
    stack<int> saco;
    stack<int> peso;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c >> x;

        if (c == 'A') {
            saco.push(x);

            if (!peso.empty()) {
                if (peso.top() < x) {
                    peso.push(x);
                }
            } else {
                peso.push(x);
            }
        } else if (c == 'V') {
            if (!peso.empty()) {
                cout << peso.top() << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (c == 'R') {
            int aux = saco.top();
            saco.pop();
            if (aux == peso.top()) {
                peso.pop();
            }
        }
    }

    return 0;
}