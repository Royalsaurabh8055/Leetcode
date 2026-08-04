class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {

        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->child[bit] == nullptr)
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {

        TrieNode* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // Prefer opposite bit
            if (node->child[1 - bit]) {

                ans |= (1 << i);
                node = node->child[1 - bit];

            } else {

                node = node->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for (int num : nums)
            trie.insert(num);

        int ans = 0;

        for (int num : nums) {
            ans = max(ans, trie.getMaxXor(num));
        }

        return ans;
    }
};