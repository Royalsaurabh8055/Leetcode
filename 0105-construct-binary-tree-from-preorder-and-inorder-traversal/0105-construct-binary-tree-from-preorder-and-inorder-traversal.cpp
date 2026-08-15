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
        int search(int element,vector<int>& inorder)
    {
        
        for(int i =0; i<inorder.size();i++)
        {
            if(inorder[i] == element)
            return i;
        }
        return -1;
    }


    TreeNode*build(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inOrderStart, int inOrderEnd)
    {
        if(preOrderIndex == -1) return NULL;

        if(inOrderStart > inOrderEnd) return NULL;

        // main logic 
        int element = preorder[preOrderIndex];
        preOrderIndex++;

        int getElementIndex = search(element,inorder);

        // ab vo element mil gya to left and right part ko dekh ke construct kro

        TreeNode* root = new TreeNode(element);// root node created

        root->left = build(preorder,inorder,preOrderIndex,inOrderStart, getElementIndex-1);
        root->right = build(preorder,inorder,preOrderIndex,getElementIndex+1,inOrderEnd);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size()-1;

        TreeNode*root = build(preorder,inorder,preOrderIndex,inOrderStart,inOrderEnd);

        return root;
    }
};