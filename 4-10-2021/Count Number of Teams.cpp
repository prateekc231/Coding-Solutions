class Solution {
public:
    int numTeams(vector<int>& arr) {
        int t = arr.size();
        int ans = 0;
        for(int i = 0;i<t ;i++){
            int left_less= 0, left_gre = 0;
            int right_less= 0, right_gre = 0;
            for(int j = 0; j<t;j++){
                if(arr[i] < arr[j]){
                    if(i > j){
                        left_gre++;
                    }
                    if(i< j){
                        right_gre++;
                    }
                }
                if(arr[i]>arr[j]){
                    if(i > j){
                        left_less++;
                    }
                    if(i< j){
                        right_less++;
                    }
                }
            }
            ans  += left_less*right_gre + left_gre*right_less;
        }
        return ans;
    }
};
