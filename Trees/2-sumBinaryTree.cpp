/*  2-Sum Binary 
    Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.
    Return 1 to denote that two such nodes exist. Return 0, otherwise.
    Notes 
    - Your solution should run in linear time and not take memory more than O(height of T).
    - Assume all values in BST are distinct.

    Example :
    Input 1: 

    T :       10
             / \
            9   20

    K = 19
    Return: 1

    Input 2: 
    T:        10
             / \
            9   20

    K = 40
    Return: 0
*/

/*  SOLUTION APPROACH
    How would we solve with O(N) memory? Let’s say you are given a sorted array and you need to find two indices i < j, such that A[i] + A[j]= k. Relate between a sorted array and a BST. Avoid O(N) memory and do with O(height) memory. <stack>

    If we do inorder traversal of BST we visit elements in increasing order. So, we use a two pointer approach, where we keep two pointers pt1 and pt2. Initially pt1 is at smallest value and pt2 at largest value.

    Then we compare sum = pt1.value + pt2.value. If sum < target, we increase pt2, else we decrease pt2 until we reach target.
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
int Solution::t2Sum(TreeNode* A, int B) {
    if(!A)
        return 0;
    TreeNode *current= A;
    stack<TreeNode*> r,l;
    
    while(current){                         // push all the nodes that lie on the rightmost branch of the tree
        r.push(current);
        current= current->right;
    }
    
    current= A;
    
    while(current){                     // push all the nodes that lie on the leftmost branch of the tree
        l.push(current);
        current= current->left;
    }
    
    while(!r.empty() && !l.empty() && r.top() != l.top()){      //if the stacks aren't empty and if they don't have the same top value

        int sum= r.top()->val + l.top()->val;
        
        if( sum > B){                                           // pop from the 'r' stack and push the rightmost node of it's left child onto stack
            TreeNode *pre= r.top();                             
            TreeNode *pl= pre->left;
            r.pop();
            while(pl){
                r.push(pl);
                pl= pl->right;
            }
        }
        
        else if(sum < B){                         // pop from the 'l' stack and push the leftmost node of it's right child onto stack
            TreeNode *pre= l.top();
            TreeNode *pr= pre->right;
            l.pop();
            while(pr){
                l.push(pr);
                pr= pr->left;
            }
        }
        
        else return 1;                          // the two nodes are found
        
    }
    return 0;
    
}
