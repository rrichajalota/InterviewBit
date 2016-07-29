/*  BST Iterator
    Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the 
    root node of a BST.
    The first call to next() will return the smallest number in BST. Calling next() again will return the next 
    smallest number in the BST, and so on.
    Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of 
    the tree.
    Try to optimize the additional space complexity apart from the amortized time complexity. 
*/

/*  SOLUTION APPROACH
     When we are on node N and are asked for next element, we obviously won’t go to the left subtree as all the 
     elements there are smaller than N. We would go to the smallest number in the right subtree if the right subtree 
     is not null. If the right subtree is null, that means that we need to move up, and keep moving up till 
     we are coming from the right subtree. 
     keep track of the path from root to the current node, so we can move to the parent when needed. 
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
TreeNode* small=NULL;
stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(root){                //place the smallest element on top of stack
        s.push(root);
        root= root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    
    if(!s.empty()){
        
        small= s.top();                 //retrieve the smallest element from the stack
        s.pop();
        
        int smallest= small->val;
        
        if(small->right){               //if it has a right child push it onto stack
            
            small= small->right;
            s.push(small);
            small= small->left;
            
            while(small){               
                s.push(small);
                small= small->left;
            }
            
        }
        
        return smallest;   
    }
    return 0;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
