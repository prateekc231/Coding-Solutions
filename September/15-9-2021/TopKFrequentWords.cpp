vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<string, vector<string>, greater<string> > freq[words.size()];
        map<string,int> mp;
        for(int i = 0 ; i<words.size() ; i++){
            if(mp.find(words[i])==mp.end()){
                mp[words[i]]=1;
            }
            else{
                mp[words[i]]++;
            }
        }
        int maxfre = 0;
        for( auto itr : mp){
            freq[itr.second].push(itr.first);
            maxfre = max(maxfre,itr.second);
        }
        for(int i = maxfre; i>=0; i--){
            while(k> 0 && !freq[i].empty()){
                ans.push_back(freq[i].top());
                freq[i].pop();
                k--;
            }
        }
        return ans;
    }
