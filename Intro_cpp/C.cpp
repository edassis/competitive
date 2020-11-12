// Deivis e a soma do vetor
#include <bits/stdc++.h>

using namespace std;

void soma_vetor(int &ac, vector<int> &v) {
    if (!v.empty()) {
        ac += v.back();
        v.pop_back();
        soma_vetor(ac, v);
    }

    return;
}

int main() {
    int n;
    int resp = 0;

    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    soma_vetor(resp, v);

    cout << resp << endl;

    return 0;
}