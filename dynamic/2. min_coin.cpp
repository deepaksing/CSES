    #include<bits/stdc++.h>
    #define int long long 
    #define endl "\n"
    #define deb(x) cout<<#x<<" "<<x 

    using namespace std;

    
    vector<int> dp(1000001, -1);

    //dp recursive optimized

    int rec(int s, int a[], int n) {
        
        if(s == 0) return 0;
        if (s<0) return INT_MAX;
        if(dp[s]!= -1) return dp[s];
        
        int val = INT_MAX;
        for(int i=0; i<n; i++) {
            if(s>=a[i]) {
                val = min(val, rec(s-a[i], a, n));
            }
        }

        return dp[s] = val + 1;
    }
    

    //iterative
    int rec2(int s, int a[], int n) {
        vector<int> dp(s+1, INT_MAX);
        dp[0] = 0;
        for(int j = 1; j<=s; j++) {
            for(int i=0; i<n; i++) {
                if(a[i]<=j) {
                    dp[j] = min(dp[j], dp[j-a[i]] + 1);
                }
            }
        }

        return dp[s];
    }
    
    void solve() {
        int n, s;
        cin>>n>>s;

        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        int ans = rec2(s, a, n);
        if(ans >= INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
        
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