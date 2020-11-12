#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    map<int,int> error;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        error[aux]++;
    }

    for (int i = 1; i <= 2; i++) {
        map<int,int> previous = error;
        error.clear();
        
        for (int j = 0; j < n-i; j++) {
            int aux;
            cin >> aux;
            error[aux]++;
            
            if (previous.count(aux) > 0) {
                previous[aux]--;
            }
        }

        for (auto& e : previous) {
            if (e.second > 0) {
                cout << e.first << endl;
                break;
            }
        }
    }
    return 0;
}