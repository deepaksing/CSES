    #include<bits/stdc++.h>
    #define endl "\n"
    #define deb(x) cout<<#x<<" "<<x 

    using namespace std;

    const int MOD = 1e9 + 7;


    //giving sigsev error (!)
    int rec(int s, int a[], int n, int i, vector<vector<int>> &dp) {
        if(s == 0) return 1;
        if(s < 0) return 0;
        if(i == n) return 0;
        if(dp[i][s] != -1) return dp[i][s];

        int first = rec(s, a, n, i+1, dp);
        int second = rec(s-a[i], a, n, i, dp);
        int ans = (first%MOD + second%MOD)%MOD;
        dp[i][s] = ans;

        return ans;
    }

    //iteration part 1 (CORRECT)
    int iter(int s, int a[], int n) {
        int dp[s+1];
        for(int i=0; i<=s; i++) dp[i] = 0;
        dp[0] = 1;

        for(int i=0; i<n; i++) {
            for(int j = 1; j<=s; j++) {
                if(j - a[i]>=0)
                dp[j] = dp[j-a[i]]%MOD + dp[j]%MOD;
                dp[j] = dp[j]%MOD;
            }
        }
        
        return dp[s]%MOD;
    }


    //iterative 2 code

    int iter2(int s, int a[], int n) {

        vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
        
        dp[0][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=s; j++) {
                dp[i][j] = dp[i-1][j];
                int l = j - a[i-1];
                if(l>=0) (dp[i][j] += dp[i][l])%=MOD;
            }
        }

        return dp[n][s];     
    }

    void solve() {
        int n, target;
        cin >> n >> target;

        int x[n];
        for(int i=0; i<n; i++)cin>>x[i];

    // <---------   Recursive Call   ------------------>
        // vector<vector<int>> dp(n+1,vector<int>(target+1, -1));
        // cout<<rec(target, x, n, 0, dp);


    // <---------   Iterative Call   ------------------>
       //cout<<iter(target, x, n)<<endl;


        cout<<iter2(target, x, n)<<endl;
        
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