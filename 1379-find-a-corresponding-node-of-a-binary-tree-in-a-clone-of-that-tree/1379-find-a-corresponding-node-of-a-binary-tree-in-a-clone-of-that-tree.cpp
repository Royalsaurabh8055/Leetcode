/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original,
                            TreeNode* cloned,
                            TreeNode* target) {

        queue<pair<TreeNode*, TreeNode*>> q;

        // Store corresponding nodes
        q.push({original, cloned});

        while (!q.empty()) {

            TreeNode* originalNode = q.front().first;
            TreeNode* clonedNode = q.front().second;

            q.pop();

            // Found target in original
            if (originalNode == target) {
                return clonedNode;
            }

            // Left children
            if (originalNode->left != NULL) {
                q.push({
                    originalNode->left,
                    clonedNode->left
                });
            }

            // Right children
            if (originalNode->right != NULL) {
                q.push({
                    originalNode->right,
                    clonedNode->right
                });
            }
        }

        return NULL;
    }
};