// Team Olympiad
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    // id, vector of idx
    map<int, vector<int>> students;

    for (int i = 1; i <= n; i++) {
        int aux = 0;
        cin >> aux;
       
        students[aux].push_back(i);
    }

    unsigned int max_categ = 5000;
    
    for (int i = 1; i <= 3; i++) {
        if (students[i].size() < max_categ) max_categ = students[i].size();
    }
    
    cout << max_categ << endl;

    for (unsigned int i = 0; i < max_categ; i++) {
        cout << students[1][i] << " " << students[2][i] << " " << students[3][i] << endl;
    }
    
    return 0;
}