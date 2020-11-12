#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool ord(ii &a, ii &b) {
    return abs(a.second) > abs(b.second);
}

int main() {
    int t, n;
    vector<ii> numbers;
    vector<ii> resp;
    cin >> t;

    int neg = 0;
    int pos = 0;
    for (int i = 0; i < t; i++) {
        numbers.clear();
        resp.clear();
        neg = 0;
        pos = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int aux;
            cin >> aux;
            numbers.pb(mp(j, aux));

            if (aux > 0)
                pos++;
            else if (aux < 0)
                neg++;
        }

        sort(numbers.begin(), numbers.end(), ord);

        int qtd = 5;
        int number;
        while (qtd > 0) {
            for (unsigned j = 0; j < numbers.size(); j++) {
                if (qtd == 5) {
                    if (neg / 2 > 0 && numbers[j].second < 0) {
                        number = numbers[j].second;
                        resp.pb(numbers[i]);
                        numbers.erase(numbers.begin() + j);
                        neg--;
                        qtd--;
                        break;
                    } else {
                        if (numbers[j].second > 0) {
                            number = numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            pos--;
                            qtd--;
                            break;
                        } else if (pos == 0 && numbers[j].second == 0) {
                            number = numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            qtd--;
                            break;
                        }
                    }
                } else {
                    if (numbers[j].second < 0) {
                        if ((number >= 0 && neg / 2 >= 1) || numbers.size() == 1) {
                            number *= numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            neg--;
                            qtd--;
                            break;
                        } else if (number < 0) {
                            number *= numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            neg--;
                            qtd--;
                            break;
                        }
                    } else if (numbers[j].second > 0) {
                        if (number >= 0) {
                            number *= numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            pos--;
                            qtd--;
                            break;
                        } else if (pos == 0) {
                            number *= numbers[j].second;
                            resp.pb(numbers[i]);
                            numbers.erase(numbers.begin() + j);
                            qtd--;
                            break;
                        }
                    }
                }
            }
        }

        cout << number << endl;
    }

    return 0;
}

// -1 1 1 1 1
// -1 1 1 1 1 1
// -1 0 0 0 1
// -1 0 0 0 1 1 1 1