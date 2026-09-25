class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;

        // No node
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        // Try every value as root
        for (int root = start; root <= end; root++) {

            vector<TreeNode*> left = solve(start, root - 1);
            vector<TreeNode*> right = solve(root + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {

                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;

                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};