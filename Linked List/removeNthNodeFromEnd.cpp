/*  Remove the Nth Node from the end
    Given a linked list, remove the nth node from the end of list and return its head.

    For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.

     Note:
    * If n is greater than the size of the list, remove the first node of the list. 
    Try doing it using constant additional space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    if (A== NULL)
        return A;
    
    ListNode* slow= A, *fast= A, *prev=NULL;
    
    while(B && fast != NULL){
        fast= fast->next;
        --B;
    }
    while(fast !=NULL){                 // find the Nth node first
        prev= slow;
        slow=slow->next;
        fast= fast->next;
    }
    if(prev)                            // Then remove it
        prev->next= slow->next;
    
    if(!prev)                           // if N is greater than or equal to the size of the list, remove the first node
        A= A->next;
    
    return A;
}
