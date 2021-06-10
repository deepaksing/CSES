    #include<bits/stdc++.h>
    #define ll long long
    #define endl "\n"
    #define deb(x) cout<<#x<<" "<<x 

    using namespace std;

    //find digits in the number
    vector<int> find_digs(int n) {
        vector<int> vals;
        while(n>0) {
            int rem = n%10;
            vals.push_back(rem);
            n = n/10;
        }

        return vals;
    }

    //recursive + dp
    vector<int> dp(1000001, -1);

    int rec(int n) {
        if(n == 0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n] != -1) return dp[n];

        vector<int> digs;
        digs = find_digs(n);

        int ans = INT_MAX;
        for(auto x: digs) {
            if(x != 0)
            ans = min(ans, rec(n - x) + 1);
        }

        dp[n] = ans;

        return ans;
    }

    //iterative code
    int iter(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            vector<int> digs = find_digs(i);
            int ans = INT_MAX;
            for(auto x: digs) {
                if(x!=0)  //important to put
                ans = min(ans, dp[i-x]+1);
            }
            dp[i] = ans;
        }

        return dp[n];
    }

    void solve() {
        
        int n;
        cin>>n;

        //cout<<rec(n)<<endl;

        cout<<iter(n)<<endl;
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
