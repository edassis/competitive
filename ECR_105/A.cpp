#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

bool valid(string s) {
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.emplace(s[i]);
        }

        else if (s[i] == ')') {
            if (st.size()) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    if (st.size()) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        char c = s[0];
        for (size_t j = 0; j < s.size(); j++) {
            if (s[j] == c) {
               s[j] = '('; 
            } 
        }

        string s_copy = s;
        for (size_t j = 0; j < s.size(); j++) {
            if (s[j] != '(') {
                s[j] = ')';
            }
        }
        if (valid(s)) {
            cout << "YES" << endl;
            continue;
        } else {
            s = s_copy;
        }
        
        char aux = '\0';
        for (size_t j = 0; j < s.size(); j++) {
            if (aux == '\0' && s[j] != '(') {
                aux = s[j];
            }

            if (s[j] == aux) {
                s[j] = ')';
            } else if (s[j] !=  '(') {
                s[j] = '(';
            }
        }
        if (valid(s)) {
            cout << "YES" << endl;
            continue;
        } else {
            s = s_copy;
        }

        for (size_t j = 0; j < s.size(); j++) {
            if (aux == '\0' && s[j] != '(') {
                aux = s[j];
            }

            if (s[j] == aux) {
                s[j] = '(';
            } else if (s[j] != '(') {
                s[j] = ')';
            }
        }
        if (valid(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
