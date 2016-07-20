/*  Symmetric Binary Tree
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
    Example :

        1
       / \
      2   2
     / \ / \
    3  4 4  3
    The above binary tree is symmetric. 
    But the following is not:

        1
       / \
      2   2
       \   \
       3    3
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem. 
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
bool issym(TreeNode* left, TreeNode* right);

int Solution::isSymmetric(TreeNode* A) {
    if(!A || !A->left && !A->right)
        return 1;
    if(!A->left || !A->right)
        return 0;
    
    TreeNode* left= A->left;
    TreeNode* right= A->right;
    
    return issym(left, right);
}

bool issym(TreeNode* left, TreeNode* right){
    if(!left && !right)
        return 1;
        
    if(!left && right || !right && left)
        return 0;
        
    if(left->val == right->val){
        
        if(issym(left->left, right->right))
            return issym(left->right, right->left);
    }
    
    return 0;
}
