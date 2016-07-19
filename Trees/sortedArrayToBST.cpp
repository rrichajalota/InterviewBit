/*  Sorted Array To BST

    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
    Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every 
    node never differ by more than 1. 
    
    Example :
    Given A : [1, 2, 3]
    A height balanced BST  : 

          2
        /   \
       1     3
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
TreeNode* buildtree(const vector<int> &A, int low, int high, TreeNode* root);

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode* root= NULL;
    
    if(A.size() == 0)
        return root;
        
    return buildtree(A,0,A.size()-1,root);
}
TreeNode* buildtree(const vector<int> &A, int low, int high, TreeNode* root){
    
    if(low <= high){
        
        int mid= low+ (high-low)/2;
        TreeNode* temp= new TreeNode(A[mid]);
        
        if(root==NULL)
            root= temp;
            
        root->left= buildtree(A,low,mid-1,root->left);
        root->right= buildtree(A,mid+1,high,root->right);
    }
    return root;
}
