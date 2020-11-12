// Parênteses
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s_in;
    int parenteses = 0;
    string resp = "sim";

    cin >> s_in;
    
    for(int i = 0; i < s_in.size(); i++) {
        if (s_in[i] == '(') {
            parenteses++;
        } else if (s_in[i] == ')') {
            if (parenteses)
                parenteses--;
            else {
                parenteses = 1;
                break;
            }
        }
    }

    if (parenteses) {
        cout << "nao" << endl;
    } else {
        cout << "sim" << endl;
    }

    return 0;
}