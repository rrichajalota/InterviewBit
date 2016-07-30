/*	BST Successor Search
	Given a node n in a binary search tree, explain and code the most efficient way to find the successor of n.
	Analyze the runtime complexity of your solution.
*/

/*	SOLUTION APPROACH
	Since the root node is not given, we assume that each node has a parent pointer.
*/

int findSuccessor(TreeNode* node){
	
	if(node->right){					// if the node has a right child, successor is the leftmost node in the right subtree
		TreeNode* next= node->right;

		while(next->left)
			next= next->left;

		return next->val;
	}

	TreeNode* parent= node->parent;			// If it doesn't have a right child, then successor is the first node having node as left child

	while(parent && parent->right==node){
		node= parent;
		parent= parent->parent;
	}

	if (parent->left == node)
		return parent->val; 

	return -1;			// We have reached the root from the right subtree. Condition is reached when the given node is the last node
}
