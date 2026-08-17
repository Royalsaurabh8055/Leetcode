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
    // int level(TreeNode*root,vector<int>&data)
    // {
    //     if(root == NULL) return 0;
        
    //     data.push_back(root->val);

    //     level(root->left,data);
    //     level(root->right,data);

    //     return data.size();
        
    // }
    int leftH(TreeNode*root)
    {
        int h =0;

        while(root)
        {
            h++;
            root = (root->left);
        }
        return h;
    }
    int rightH(TreeNode*root)
    {
        int h =0;

        while(root)
        {
            h++;

             root = (root->right);
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;

        int left = leftH(root);
        int right = rightH(root);
    
        if(left == right)
        {
            return (1 << left)-1;
        }
        else

        return 1 + countNodes(root->left) + countNodes(root->right);

       
    }
};