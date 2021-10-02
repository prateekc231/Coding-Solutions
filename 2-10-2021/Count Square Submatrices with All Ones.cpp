class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m,0);
        int topleft = 0;
        int res = 0;
        for(int i =0 ;i<n;i++){
            for(int  j = 0;j<m;j++){
                if(matrix[i][j]==1){
                    int top = (i==0)? 0 : arr[j];
                    int left  = (j==0) ? 0 : arr[j-1];
                    arr[j] = 1 + min({top,left,topleft});
                    res = res + arr[j];
                    topleft = (j==m-1) ? 0 : top;
                }
                else{
                    arr[j]=0;
                }
            }
        }
        return res;
    }
};
