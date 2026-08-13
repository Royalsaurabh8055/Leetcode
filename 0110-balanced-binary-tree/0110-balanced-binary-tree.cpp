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
    int getHeight(TreeNode* root)
    {
        if(root == NULL) return 0;

       
            int l = getHeight(root->left);

            int r = getHeight(root->right);
        
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;

        // find the height diff for current node and check then give to recusrsion
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        if(abs(left-right)>1) return false;

        else
        {
            // it means current node is balanaced so go an check for the remaining one
            bool leftAns = isBalanced(root->left);
            bool rightAns = isBalanced(root->right);

            if(leftAns == true && rightAns == true) return true;

        }
        return false;
    }
};