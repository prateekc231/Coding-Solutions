class Solution {
public:
    vector<string> transform(string word, set<string> &s){
        vector<string> ans;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            string temp = word;
            for(char j = 'a';j<='z';j++){
                if(j!=ch){
                    temp[i]=j;
                    if(s.find(temp)!=s.end()){
                        ans.push_back(temp);
                        s.erase(temp);
                    }
                }
            }
        }
        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int> > que;
        que.push(make_pair(beginWord,1));
        while(!que.empty()){
            pair<string,int> X = que.front();
            que.pop();
            vector<string> neigh = transform(X.first, s);
            for(string str : neigh){
                if(str == endWord){
                    return X.second + 1;
                }
                que.push(make_pair(str,X.second+1 ));
            }
        }
        return 0;
    }
};
