class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum = sum+digits[i];
        }
        sort(digits.begin(),digits.end());
        if(sum%3 == 0){
            string s="";
            if(digits[n-1]==0) return "0";
            for(int i =n-1;i>=0;i--){
                s += to_string(digits[i]);
            }
            return s;
        }
        else if(sum%3 == 1){
            bool found = false;
            for(int i=0;i<n;i++){
                if(digits[i]%3 == 1){
                    digits[i] =-1;
                    found=true;
                    break;
                }
            }
            if(!found){
                int arr[2] ={-1,-1};
                for(int i=0;i<n;i++){
                    if(digits[i]%3 == 2){
                        if(arr[0]==-1) arr[0]= i;
                        else{
                            arr[1] = i;
                            break;
                        }
                    }
                }
                if(arr[1] == -1){
                    return "";
                }
                else{
                    digits[arr[0]] = -1;
                    digits[arr[1]] = -1;
                }
            }
        }
        else if(sum%3 == 2){
            bool found = false;
            for(int i=0;i<n;i++){
                if(digits[i]%3 == 2){
                    digits[i] =-1;
                    found=true;
                    break;
                }
            }
            if(!found){
                int arr[2] ={-1,-1};
                for(int i=0;i<n;i++){
                    if(digits[i]%3 == 1){
                        if(arr[0]==-1) arr[0]= i;
                        else{
                            arr[1] = i;
                            break;
                        }
                    }
                }
                if(arr[1] == -1){
                    return "";
                }
                else{
                    digits[arr[0]] = -1;
                    digits[arr[1]] = -1;
                }
            }
        }
            string s="";

            for(int i =n-1;i>=0;i--){
                if(digits[i]!=-1){
                s += to_string(digits[i]);
                }
            }
            return s;
    }
};
