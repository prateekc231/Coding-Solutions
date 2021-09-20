bool canReach(vector<int>& arr, int start) {
        vector<int> zeros;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zeros.push_back(i);
            }
        }
        map<int,vector<int> > mp;
        for(int i =0;i<arr.size();i++){
            if(arr[i]!=0){
                if( i+arr[i]<arr.size()){
                    mp[i].push_back(i+arr[i]);
                }
                if(i-arr[i]>=0){
                    mp[i].push_back(i-arr[i]);
                }
            }
        }
        vector<bool> visited(arr.size(),false);
        queue<int> q;
        q.push(start);
        visited[start]= true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int u : mp[temp]){
                if(visited[u] == false){
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
        for(int i = 0;i<zeros.size();i++){
            if(visited[zeros[i]]==true){
                return true;
            }
        }
        return false;

    }
