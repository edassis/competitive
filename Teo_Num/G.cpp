#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int conv_bin(string s) {
    int num = 0;
    for (size_t i = 0; i < s.size(); i++) {
        num = (num * 2 + (s[i] - '0')) % 131071;
    }
    return num;
}

int main() {
    //1010101
    // 64+16+4+1
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
    int num = conv_bin(s);
    string res = "Sim";
    if (num)
        res = "Nao";
    
    cout << res << endl;
 
    return 0;
}