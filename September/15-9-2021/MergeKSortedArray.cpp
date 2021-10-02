
typedef pair< int, pair<int, int> > pi;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{

        vector<int> ans;
        priority_queue <pi , vector<pi> , greater<pi> > pq;
        for(int i=0;i<K;i++){
            pq.push(make_pair(arr[i][0], make_pair(i,0)));
        }
        while(!pq.empty()){
            pi temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            if(temp.second.second < K-1){
                temp.first = arr[temp.second.first][++temp.second.second];
                pq.push(temp);
            }
        }
        return ans;
}
