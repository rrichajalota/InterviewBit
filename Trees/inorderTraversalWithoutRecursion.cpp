/*  Inorder Traversal without Recursion
    (solution using morris traversal)
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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(!A)
        return ans;
        
    while(A){
        
        if(!A->left){
            ans.push_back(A->val);
            A= A->right;
        }
        
        else if(A->left!=NULL){
            TreeNode *pre= A->left;
            
            while(pre->right && pre->right!= A)
                pre= pre->right;
                
            if(pre->right!= A){
                pre->right= A;
                A= A->left;
            }
            
            else{
                pre->right= NULL;
                ans.push_back(A->val);
                A= A->right;
            }
            
        }
    }
    return ans;
}
