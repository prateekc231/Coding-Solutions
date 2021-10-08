class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mn = INT_MIN,best=0;
            for(int j = 1;j<=k && i-j>=0;j++){
                mn=max(arr[i-j],mn);
                best = max(best,mn*j + dp[i-j]);
            }
            dp[i]=best;
        }
        return dp[n];
    }
};
