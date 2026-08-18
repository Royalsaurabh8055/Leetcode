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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,unsigned long long>>q;

        q.push({root,1}); // basically we are doing mapping here
        int maxWidth = 0;

        while(!q.empty())
        {
            int size = q.size();

            unsigned long long leftMost = q.front().second;// we are fetching index

            unsigned long long rightMost = q.back().second;

             maxWidth = max(maxWidth, (int)(rightMost - leftMost + 1));
             //now give indexing to all of them here 
             for(int i =0; i<size; i++)
             {
                auto front = q.front(); // it will give me pair
                q.pop();

                auto current = front.first;
                auto idx = front.second;

                if(current->left) q.push({current->left, 2*idx});
                if(current->right)q.push({current->right, 2*idx+1});
             }
        }
        return maxWidth;
    }
};