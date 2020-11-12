// Nastya and an Array
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    set<int> v;

    for (int i = 0; i < n; i++) {
        int aux = 0;
        cin >> aux;
        if (aux != 0) v.insert(aux);
    }

    cout << v.size() << endl;

    return 0;
}