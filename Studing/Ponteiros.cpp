#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int a = 10;
    int *b = &a;

    cout << a << endl;
    cout << *b << endl;
    cout << b << endl;
    cout << &a << endl;
    cout << &b << endl;

    return 0;
}