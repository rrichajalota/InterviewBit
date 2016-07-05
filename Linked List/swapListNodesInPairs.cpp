/*  Swap List Nodes in pairs
    
    Given a linked list, swap every two adjacent nodes and return its head.
    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(!A)
        return A;
        
    ListNode *temp= A, *next= temp->next, *prev= NULL;
    
    while(temp && next){
        
        temp->next= next->next;
        next->next= temp;
        
        if(temp==A)
            A= next;
            
        else if(prev)
            prev->next= next;
            
        prev= temp;
        temp= temp->next;
        
        if(temp){
            next= temp->next;
        }
    }
    return A;
    
}
