/*  Postorder Traversal Using One stack

    Solution Approach- We use a prev variable to keep track of the previously-traversed node. 
    The pointer curr is the current node that’s on top of the stack. When prev is curr‘s parent, we are traversing down the tree. In this case, we try to traverse to curr‘s left child if available (ie, push left child to the stack). If it is not available, we look at curr‘s right child. If both left and right child do not exist (ie, curr is a leaf node), we print curr‘s value and pop it off the stack.

    If prev is curr‘s left child, we are traversing up the tree from the left. We look at curr‘s right child. If it is available, then traverse down the right child (ie, push right child to the stack), otherwise print curr‘s value and pop it off the stack.

    If prev is curr‘s right child, we are traversing up the tree from the right. In this case, we print curr‘s value and pop it off the stack.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(!A)
        return ans;
    stack<TreeNode*> s;
    TreeNode *prev= NULL, *current;
    s.push(A);
    
    while(!s.empty()){
        current= s.top();
        
        if(!prev || prev->left==current || prev->right==current){   //traversing down the tree
            if(current->left)
                s.push(current->left);
            else if(current->right)
                s.push(current->right);
        }
        
        else if(current->left==prev){       //traversing up the tree
            if(current->right)
                s.push(current->right);
        }
        
        else{
            ans.push_back(current->val);
            s.pop();
        }
        
        prev= current;
    }
    
    return ans;
}
