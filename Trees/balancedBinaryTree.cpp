/*  Balanced Binary Tree
    Given a binary tree, determine if it is height-balanced.
    Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem
    Example :
    Input : 
              1
             / \
            2   3

    Return : True or 1 
    Input 2 : 
             3
            /
           2
          /
         1

    Return : False or 0 
             Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
             Difference = 2 > 1. 
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
 
int height(TreeNode* root);
 
int Solution::isBalanced(TreeNode* A) {

    if(A==NULL || !A->left && !A->right)
        return 1;

    int hleft= height(A->left);
    int rleft= height(A->right);

    if(abs(hleft- rleft) < 2)
       return (isBalanced(A->left) && isBalanced(A->right));
    

    return 0;
}
int height(TreeNode* root){

    if(root==NULL)
        return 0;

    return max(height(root->left), height(root->right))+1;
}
