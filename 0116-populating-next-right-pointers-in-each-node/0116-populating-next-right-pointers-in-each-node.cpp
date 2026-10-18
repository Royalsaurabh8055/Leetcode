class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        Node* leftmost = root;

        while (leftmost->left != NULL) {
            Node* curr = leftmost;

            while (curr != NULL) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect across neighboring parents
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};