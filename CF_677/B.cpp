#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vi books(50);
        int l = -1, r = -1;
        int moves = 0;
        for (int j = 0; j < n; j++) {
            int aux = -1;
            cin >> aux;
            if (aux) {
                if (l == -1) l = j;
                else r = j;
            }
            books[j] = aux;
        }

        for (int j = l; j <= r; j++) {
            if (books[j] == 1) {
                int l_block = j, r_block = j;
                while (books[r_block+1] == 1) r_block++;
                int k = j;
                while (true) {
                    if (j < (l+r)/2) {
                        k++;
                        if (k <= r && books[k] == 0) {
                            books[k - 1] = 0;
                            books[k] = 1;
                            moves++;
                        }
                        else break;
                    }
                    else {
                        k--;
                        if (k >= l && books[k] == 0) {
                            books[k + 1] = 0;
                            books[k] = 1;
                            moves++;
                        }
                        else break;
                    }
                }
            }
        }

        cout << moves << endl;
    }
    return 0;
}