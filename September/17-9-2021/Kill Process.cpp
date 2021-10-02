vector<int> killProcess(vector<int>& pid,vector<int>& ppid,int kill){
        map<int,vector<int> > mp;
        for(int i=0;i<ppid.size();i++){
            mp[ppid[i]].push_back(pid[i]);
        }
        queue< int > q;
        vector<int > ans;
        ans.push_back(kill);
        q.push(kill);
        while(q.size()>0){
            int temp = q.front();
            q.pop();
            for(int i=0; i< mp[temp].size();i++){
                ans.push_back(mp[temp][i]);
                q.push(mp[temp][i]);
            }
        }
        return ans;
}
