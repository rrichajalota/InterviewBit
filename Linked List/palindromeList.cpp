/*  Palindrome List 
    Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

    Notes: 
    - Expected solution is linear in time and constant in space.

    For example,

    List 1-->2-->1 is a palindrome.
    List 1-->2-->3 is not a palindrome
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(!A)
        return 1;
        
    ListNode* fast= A, *slow= A, *prev= NULL, *next;
    
    while(fast && fast->next){          // reverse the list from the middle
        fast= fast->next->next;
        next= slow->next;
        slow->next= prev;
        prev= slow;
        slow= next;
        
    }
    if(fast)  //list is odd
        slow= slow->next;
        
    while(prev && slow && prev->val==slow->val){
        prev= prev->next;
        slow= slow->next;
    }
    if(prev && slow && prev->val!= slow->val)
        return 0;
        
    
    return 1;
}
