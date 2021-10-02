class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i = 0;i<N;i++){
            pq.push(arr[i]);
        }
        int res=0;
        while(K>0 && !pq.empty()){
            if(pq.top() > K){
                break;
            }
            else{
                K= K-pq.top();
                res++;
                pq.pop();
            }
        }
        return res;
    }
};
