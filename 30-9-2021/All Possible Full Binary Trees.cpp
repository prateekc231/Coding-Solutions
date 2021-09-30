map<int,vector<TreeNode*> > dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1){
            vector<TreeNode*> ans;
            TreeNode* newNode = new TreeNode(0);
            ans.push_back(newNode);
            return ans;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        vector<TreeNode*> leftTrees, rightTrees;
        vector<TreeNode*> ans;
        for(int i = 1;i<n;i=i+2){
            leftTrees = allPossibleFBT(i);
            rightTrees = allPossibleFBT(n-i-1);

            for(int j = 0; j<leftTrees.size();j++){
                for(int k = 0; k<rightTrees.size();k++){
                    TreeNode* newNode = new TreeNode(0);
                    newNode->left = leftTrees[j];
                    newNode->right = rightTrees[k];
                    ans.push_back(newNode);
                }
            }

        }
         return dp[n] =ans;
    }
