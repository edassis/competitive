#include <bits/stdc++.h>
using namespace std;

// uses Sieve of Eratosthenes algorithm
// permits to get all primes number from to 2 at n
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int first = 0, second = 0;
    int max = 50 + 1;   // maximum valor may not be prime

    cin >> first >> second;
    
    bool stop = false;
    vector<int> prime;
    
    for (int i = 2; i <= max; i++) {
        prime.push_back(i);
    }

    for (int i = 0; i < prime.size() && prime[i]*prime[i] < max; i++) {

        for (int j = prime[i]*prime[i]; j < max; j += prime[i]) {
            
            for (int k = 0; k < prime.size(); k++) {
                if (prime[k] == j) prime.erase(prime.begin()+k);
            }
        }
    }
    
    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] >= first) {
            prime.erase(prime.begin(), prime.begin()+i);
            break;
        }
    }

    if (*(prime.begin()+1) == second) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}