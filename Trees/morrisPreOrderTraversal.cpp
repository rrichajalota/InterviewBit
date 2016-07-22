// Morris PreOrder Traversal of a Binary Tree (without recursion without stack)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /* SOLUTION APPROACH
    1) Initialize current pointer as A.
    2) while current != NULL
        if current->left == NULL, print current's value. Move to current->right.
        else 
            a) find the rightmost node of the leftsubtree of current and make the right child of the rightmost node point to current.
            Two cases might arise. Rightmost child already points to current or it doesn't. (This is the case if it doesn't point)
            b) print the current's value
            c) update current to current->left 
           if the rightmost child of the left subtree of current already points current
            a) set the right child of the rightmost node = NULL
            b) current = current->right
*/
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    TreeNode* current= A;
    
    while(current){
        
        if(!current->left){
            ans.push_back(current->val);
            current= current->right;
        }

        else{
            TreeNode* pre= current->left;
            
            while(pre->right && pre->right!= current)
                pre= pre->right;
                
            if(!pre->right){
                ans.push_back(current->val);
                pre->right= current;
                current= current->left;
            }
            
            else{
                pre->right=NULL;
                current= current->right;
            }
        }
    }
    return ans;
}
