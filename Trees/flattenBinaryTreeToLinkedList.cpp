/*  Flatten Binary Tree to Linked List

    Given a binary tree, flatten it to a linked list in-place.
    Example :
    Given
             1
            / \
           2   5
          / \   \
         3   4   6
    The flattened tree should look like:
       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
    Note that the left child of all nodes should be NULL.
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
/*  SOLUTION APPROACH
    1. If the root has a left child, find the rightmost node in the left subtree of the root. 
    2. cut the right child of the root and link it to the rightmost node of the left subtree.
    3. Now, make the left child of the root, right child.
    4. set the left child as NULL.
    5. Update root as the right child of the root.
    6. Iterate all the steps again, until the tree has no left child.
*/ 
TreeNode* Solution::flatten(TreeNode* A) {

    TreeNode* root= A;
    
    while(A){

        if(A->left){

        TreeNode *pre= A->left;

        while(pre->right)
            pre= pre->right;

        pre->right= A->right;
        A->right= A->left;
        A->left= NULL;

        }
        A= A->right;
    }

    return root;
}
