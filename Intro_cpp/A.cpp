#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, G, F, C;

    cin >> N >> G >> F >> C;

    int pares = G;
    if (pares > F) pares = F;
    
    pares += C;

    if (pares > N) {
        printf("%d\n", N);
    }
    else {
        printf("%d\n", pares);
    }

    return 0;
}