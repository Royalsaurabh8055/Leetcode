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
    int get(int ele, vector<int>inorder)
    {
        for(int i =0; i<inorder.size();i++)
        {
            if(inorder[i] == ele)
            return i;
        }
        return -1;
    }

    TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int &PostOrderIndex, int InorderStart, int InorderEnd)
    {
       // if(root == NULL) return NULL;

        if(InorderStart>InorderEnd) return NULL;

        if(PostOrderIndex < 0 ) return NULL; // we reached invalid index

        int ele = postorder[PostOrderIndex];
        PostOrderIndex--;

        int eleIndex = get(ele,inorder); // seraching that index in inorder

        TreeNode* root = new TreeNode(ele);// create a root node with element found 

        //LRN (after creating node then right then left)

         root->right = Build(inorder, postorder, PostOrderIndex, eleIndex+1, InorderEnd);

        root->left = Build(inorder, postorder, PostOrderIndex, InorderStart, eleIndex-1);

       

        return root;
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int InorderStart =0;
        int InorderEnd = inorder.size()-1;
        int PostOrderIndex = postorder.size()-1;

        TreeNode* ans = Build(inorder,postorder,PostOrderIndex, InorderStart,InorderEnd);

        return ans;

    }
};