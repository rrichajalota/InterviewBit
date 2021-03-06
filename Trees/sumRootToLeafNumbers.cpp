/* SUM ROOT-TO-LEAF NUMBERS

    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
    An example is the root-to-leaf path 1->2->3 which represents the number 123.
    Find the total sum of all root-to-leaf numbers % 1003.
    Example :

        1
       / \
      2   3
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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

long long int findsum(TreeNode *A, long long int sum);

int Solution::sumNumbers(TreeNode* A) {
    if(!A)
        return 0;
        
    long long int sum=0;
    
    return (int)findsum(A,sum);
}

long long int findsum(TreeNode *A, long long int sum){
    
    if(!A)
        return 0;

    sum = (sum * 10 + A->val)%1003;
    
    if(A->left==NULL && A->right==NULL)     //it's a leaf, return the sum calculated so far.
        return sum;
    
    return (findsum(A->left,sum)+findsum(A->right,sum))%1003;
}
