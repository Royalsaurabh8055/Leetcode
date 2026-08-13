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
public:
    void solve(TreeNode*root, int targetSum,vector<int>temp, vector<vector<int>>&ans,int sum)
    {
        if(root == NULL) return; // no sum possible

        // now valid root is found

        sum = sum+root->val;
        temp.push_back(root->val);

        // now check is it leaf node ? 
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == sum)
            {
                ans.push_back(temp);
                return;
            }
        }
        
        solve(root->left,targetSum,temp,ans,sum);
        solve(root->right,targetSum,temp,ans,sum);
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>ans;

        int sum =0;

        solve(root,targetSum,temp,ans,sum);
        return ans;
    }
};