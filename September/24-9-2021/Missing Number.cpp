class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int y = 0;
        for(int i=1;i<n;i++){
            x = x^nums[i];
        }
        for(int i =1; i<=n;i++){
            y = y^i;
        }
        return x^y;
    }
};
