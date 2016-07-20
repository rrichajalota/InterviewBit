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
bool compare(TreeNode* root1, TreeNode* root2);

int Solution::isSymmetric(TreeNode* root) {
    if (root==NULL)
          return true;
    if(root && !root->left && !root->right)
         return 1;
    if(!root->right && root->left || !root->left && root->right)
         return 0;
    TreeNode* root1= root->left, *root2= root->right;
         return compare(root1,root2);

}

bool compare(TreeNode* root1, TreeNode* root2){
    bool cmp;
        if(!root1 && !root2)
          return true;
        if(!root1 && root2 || root1 && !root2)
          return false;
        else{
            if(root1->val==root2->val){
                cmp=compare(root1->left,root2->right);
                if(cmp==true)
                 compare(root1->right,root2->left);
                else return false;
            }
           else return false; 
        }
}
