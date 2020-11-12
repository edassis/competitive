// F. Teclados
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> t1 >> t2;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string conv;
        cin >> conv;

        for (int j = 0; j < conv.size(); j++) {
            char letter = conv[j];
            bool upper = false;

            if (conv[j] < 'a') {    // Upper case
                letter = (conv[j] - 'A') + 'a';
                upper = true;
            } if (conv[j] < 'A') {  // number
                cout << conv[j];
                continue;
            }

            int idx = -1;
            for (int k = 0; k < 26; k++) {
                if (t1[k] == letter) {
                    idx = k;
                }
            }

            if (upper) {
                cout << (char)((t2[idx] - 'a') + 'A');
            } else {
                cout << t2[idx];
            }

        }
        cout << endl;
    }
    return 0;
}