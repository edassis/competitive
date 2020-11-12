// Deivis e as matrículas
#include <bits/stdc++.h>

using namespace std;

bool change(string s1, string s2) {
    int size = 0;
    if (s1.length() < s2.length())
        size = s1.length();
    else
        size = s2.length();

    for (int i = 0; i < size; i++) {
        if (s1[i] - 'a' < s2[i] - 'a') {
            return false;
        } else if (s1[i] - 'a' > s2[i] - 'a') {
            return true;
        }
    }

    return false;
}

int main() {
    int n;

    cin >> n;
    vector<string> names;

    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;

        for (auto& a : aux) {
            a = tolower(a);
        }

        names.push_back(aux);
    }

    vector<string> names_copy(names);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (change(names_copy[i], names_copy[j])) {
                string aux = names_copy[i];
                names_copy[i] = names_copy[j];
                names_copy[j] = aux;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (names[i] == names_copy[j]) {
                cout << j << ' ';
            }
        }
    }

    cout << '\n';

    return 0;
}