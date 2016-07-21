/*  Path Sum
    Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
    Example :
    Given the below binary tree and sum = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1
    return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
int pathsum(TreeNode* A, int B, int &sum);

int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
        return 0;
        
    int sum= 0;
    return pathsum(A,B,sum);
}
int pathsum(TreeNode* A, int B, int &sum){
    if(!A)
        return 0;
        
    sum += A->val
    
    if(sum==B && !A->right && !A->left) //it's a leaf and the pathsum equals B
        return 1;
        
    int val= pathsum(A->left,B, sum);
    
    if(val== 1)
        return 1;
        
    val= pathsum(A->right,B,sum);
    
    if(val==1)
        return 1;
        
    sum -= A->val;
    
    return 0;
}
