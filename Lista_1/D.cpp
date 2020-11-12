// Deivis e o ano bonito
#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    bool stop = true;

    cin >> x;
    x++;

    do {
        stop = true;
        string number = to_string(x);
        
        if (number.length() == 1) {
            break;
        }

        else {
            bool igual = false;
            
            for (int i = 0; i < (int)number.length() - 1 && !igual; i++) {
                for (int j = i + 1; j < (int)number.length() && !igual; j++) {
                    if (number[i] == number[j]) {
                        x++;    
                        stop = false;
                        igual = true;
                    }
                }
            }
        }
    } while (!stop);

    cout << x << endl;

    return 0;
}