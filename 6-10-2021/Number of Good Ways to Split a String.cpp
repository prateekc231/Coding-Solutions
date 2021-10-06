class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int left[n],right[n];
        set<int> lse;
        set<int> rse;
        for(int i = 0; i<n;i++){
            lse.insert(s[i]);
            left[i] = lse.size();
        }
        for(int i = n-1; i>=0;i--){
            rse.insert(s[i]);
            right[i] = rse.size();
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(left[i] == right[i+1]){
                ans++;
            }
        }
        return ans;
    }
};
