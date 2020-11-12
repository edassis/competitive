// Deivis e a igualdade
#include <bits/stdc++.h>

using namespace std;

bool decresc(int a, int b) {
    return a > b;
}

int main() {
    int n;

    cin >> n;

    vector<int> din;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        din.push_back(aux);
    }

    sort(din.begin(), din.end(), decresc);

    int biggest = din.front();
    int ac = 0;
    
    for (vector<int>::iterator it = din.begin()+1; it != din.end(); it++) {
        ac += biggest - *it;
    }

    cout << ac << endl;

    return 0;
}