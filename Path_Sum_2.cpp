/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

void dfs(TreeNode* node , long long rem , vector<int>& path , vector<vector<int>>& ans){

    if(!node) return ;

    path.push_back(node->val);
    rem -= node->val;

    if(!node->left && !node->right){
        if(rem == 0 ) ans.push_back(path);
    }
    else{
        if(node ->left ) dfs(node-> left , rem , path , ans);
        if(node ->right ) dfs(node-> right , rem , path , ans);

    }

    path.pop_back();
}

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector <int> path;
        dfs(root , (long long)targetSum , path , ans);
        return ans;
    }
};
