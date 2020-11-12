#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;
    string cores;
    int contador = 0;

    cin >> n >> cores;

    char previous = cores[0];
    for (int i = 1; i < n; i++) {
        if (cores[i] == previous) contador++;
        previous = cores[i];
    }

    cout << contador << endl;

    return 0;
}