/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent)
    {
        if(node == NULL)
            return;

        if(grandparent != NULL && grandparent->val % 2 == 0)
            ans += node->val;

        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {

        dfs(root, NULL, NULL);

        return ans;
    }
};