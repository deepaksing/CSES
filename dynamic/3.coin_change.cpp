    #include<bits/stdc++.h>
    #define int long long 
    #define endl "\n"
    #define deb(x) cout<<#x<<" "<<x 

    using namespace std;

    const int MOD = 1e9 + 7;
    vector<int> dp(1000001, -1);
    
    //recursive dp optimized

    int rec(int s, int a[], int n) {
        if(s == 0) return 1;
        if(s < 0) return 0;
        if(dp[s]!=-1) return dp[s];
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += rec(s-a[i], a, n)%MOD;
        }
        dp[s] = ans%MOD;
        return ans%MOD;
    }


    //iterative
    int itr(int target, int a[], int n) {
        vector<int> dps(target+1, 0);
        dps[0] = 1;

        for(int i=1; i<=target; i++) {
            int val = 0;
            for(int j=0; j<n; j++) {
                if(i - a[j] >= 0) {
                    val += dps[i - a[j]]%MOD;  
                    val = val%MOD; 
                }
            }
            dps[i] = val%MOD;
        }

        return dps[target]%MOD;

    }


    void solve() {
        
        int n, x;
        cin>>n>>x;

        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        //cout<<rec(x, a, n);
        cout<<itr(x, a, n);
        
    }

    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t = 1;
        //cin>>t;

        while(t--) {
            solve();
        }  
        return 0;
    }