class Solution {
public:
    int dp[3002];
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        memset(dp,-1,sizeof dp);
        for(int i=lo;i<=hi;i++){
            v.push_back({power(i),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
    int power(int num){
        int cnt=0;
        int num_org=num;
        while(num!=1){

            if(num<3001 && dp[num]!=-1)
                return dp[num_org]=cnt+dp[num];
            if(num%2==0)
                num=num/2;
            else
                num=3*num+1;
            cnt++;
        }
        return dp[num_org]=cnt;
    }
};
