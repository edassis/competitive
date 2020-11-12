#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        if (n == 1) {
            int num;
            scanf("%d", &num);
            printf("%d\n", num*2);
            
            continue;
        }

        vll nums(n);
        for (int j = 0; j < n; j++) scanf("%lld", &nums[j]);
        
        sort(nums.begin(), nums.end());

        ll a = nums.back();
        ll res = -1;
        for (ll x = nums.front(); x <= nums[nums.size()-2]; x++) {
            res = a * x;
            for (auto &e : nums) {
                if (res % e != 0) {
                    res = -1;
                    break;
                }
                
            }
            if (res > 0) break;
        }

        printf("%lld\n", res);
    }
    
    return 0;
}