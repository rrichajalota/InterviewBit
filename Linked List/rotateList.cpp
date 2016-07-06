/*  ROTATE LIST
    
    Given a list, rotate the list to the right by k places, where k is non-negative.
    For example:

    Given 1->2->3->4->5->NULL and k = 2,
    return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(!A || B==0)
        return A;
        
    ListNode *fast= A, *prev= NULL, *slow= A;
    
    int len= 0;
    
    while(fast){
        prev= fast;
        fast= fast->next;
        ++len;
    }
        
    int rotatePosition= len - B%len;
    
    for(int i=1; i < rotatePosition; i++){
        slow= slow->next;
    }
    
    prev->next= A;
    A= slow->next;
    slow->next= NULL;
    
    return A;
}
