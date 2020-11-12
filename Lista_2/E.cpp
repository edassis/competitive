// E. Encontre a diferença
#include <bits/stdc++.h>

using namespace std;

bool ordena(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n, k;
    vector<pair<int, int>> num;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        num.push_back(make_pair(i, aux));
    }

    sort(num.begin(), num.end(), ordena);

    bool founded = false;
    for (int i = 0; i < n && !founded; i++) {
        int target = num[i].second - k;
        int begin = 0;
        int end = n - 1;

        int found_idx = -1;

        while (begin <= end) {
            int middle = (end + begin) / 2;

            if (num[middle].second == target && num[middle].first != num[i].first) {
                found_idx = num[middle].first;
                break;
            } else {
                if (target > num[middle].second) {
                    begin = middle + 1;
                } else {
                    end = middle - 1;
                }
            }
        }

        if (found_idx != -1) {
            cout << "Sim" << endl;
            cout << num[i].first + 1 << ' ' << found_idx + 1 << endl;
            founded = true;
        }
    }

    if (!founded) {
        cout << "Nao" << endl;
    }

    return 0;
}