/*  Kth smallest Element in Tree
    Given a binary search tree, write a function to find the kth smallest element in the tree.
    Example :
    Input : 
      2
     / \
    1   3
    and k = 2
    Return : 2
    As 2 is the second smallest element in the tree.
    NOTE : You may assume 1 <= k <= Total number of nodes in BST 

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void kthsmall(TreeNode* root, int k, int &node, int &val);
int Solution::kthsmallest(TreeNode* root, int k) {
    if(!root)
        return -1;
    int node= 0, val=-1;
    kthsmall(root,k,node,val);
    return val;
}

void kthsmall(TreeNode* root, int k, int &node, int &val){
    if(!root)
        return;
        
    kthsmall(root->left,k,node,val);
    if(val != -1)
        return;
    ++node;
    if(node==k){
        val= root->val;
        return;
    }
    kthsmall(root->right,k,node,val);
}
