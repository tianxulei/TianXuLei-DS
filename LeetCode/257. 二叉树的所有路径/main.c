/*给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。*/

vector<string>ans;
    vector<int>table;
    void dfs(TreeNode* root){
        if(!root->left && !root->right){
            table.push_back(root->val);
            string tmp=to_string(table[0]);
            for(auto it=table.begin()+1;it!=table.end();++it)
                tmp=tmp+"->"+to_string(*it);
            ans.push_back(tmp);
            return;            
        }
        table.push_back(root->val);
        if(root->left){
            dfs(root->left);
            table.pop_back();            
        }
        if(root->right){
            dfs(root->right);   
            table.pop_back();         
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
