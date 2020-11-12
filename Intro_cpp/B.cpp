// Deivis e o menor retângulo
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    string value_input;
    cin >> n >> m;

    int minor_x = 10;
    int major_x = -1;
    int minor_y = 10;
    int major_y = -1;

    for (int i = 0; i < n; i++) {  // linhas
        cin >> value_input;

        for (int j = 0; j < m; j++) {  // colunas
            int value = value_input[j] - '0';
            // cout << "Value: " << value << endl;

            if (value == 1) {
                if (minor_y > i) {
                    minor_y = i;
                }
                if (major_y < i) {
                    major_y = i;
                }
                if (minor_x > j) {
                    minor_x = j;
                }
                if (major_x < j) {
                    major_x = j;
                }
            }
        }
    }

    if (minor_x <= major_x) {
        cout << major_x - minor_x + 1 << "x" << major_y - minor_y + 1 << endl;
    } else {
        cout << "0x0" << endl;
    }

    return 0;
}