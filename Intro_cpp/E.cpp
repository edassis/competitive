// Deivis e fibonacci
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m = 0, n = 0;
    int counter = 0;
    
    cin >> m >> n;
    
    int square[m][n] = {};
    
    for (int i = 0; i < m; i++) {       // linhas
        for (int j = 0; j < n; j++) {       // colunas 
            if (square[i][j] == 0) { // empty
                if ( (j+1 < n) && (square[i][j+1] == 0) ) {
                    // put a horizontal domino
                    square[i][j] = 1;
                    square[i][j+1] = 1;
                    counter++;
                }
                else if ( (i+1 < m) && (square[i+1][j] == 0) ) {
                    // put a vertical domino
                    square[i][j] = 1;
                    square[i+1][j] = 1;
                    counter++;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}