class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            vector<TreeNode*> nodes;

            // Store all nodes of current level
            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                nodes.push_back(curr);

                if (curr->left != NULL) {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            // If level is odd, reverse values
            if (level % 2 == 1) {

                int left = 0;
                int right = nodes.size() - 1;

                while (left < right) {

                    swap(nodes[left]->val, nodes[right]->val);

                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
};