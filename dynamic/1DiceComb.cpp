    #include<bits/stdc++.h>
    #define int long long 
    #define endl "\n"

    using namespace std;

    //identical combination possible problem

    //recursive
    int rec(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        return rec(n-1) + rec(n-2) + rec(n-3) + rec(n-4) + rec(n-5) + rec(n-6);
    }


    //dp optimized 
    const int MOD = 1e9+7;
    vector<int> dp;
    int rec2(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n]%MOD;
        
        int out = rec2(n-1)%MOD + rec2(n-2)%MOD + rec2(n-3)%MOD + rec2(n-4)%MOD + rec2(n-5)%MOD + rec2(n-6)%MOD;
        dp[n] = out%MOD;
        return dp[n]%MOD;
    }


    //iterative

    int rec3(int n) {
        vector<int> a(n+1, 0);
        a[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j = 1; j<=6 && i-j>=0; j++) {
                (a[i] += a[i-j])%=MOD;
            }
        }
        return a[n];

    }
  

    void solve() {
        int n;
        cin>>n;

        //cout<<rec(n)<<endl;

        dp.resize(n+1, -1);

        cout<<rec2(n);
        
        //cout<<rec3(n)<<endl;      
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