int countFriendsPairings(int n)
    {
        // code here
        long long mod = 1000000007;
        int dp[n+1];
        for(int i=0;i<=n;i++){
            if(i<=2){
                dp[i]= i;
            }
            else{
            dp[i] = (dp[i-1] + (((i-1)%mod)*(dp[i-2]%mod)))%mod;
            }
        }
        return dp[n];

    }
