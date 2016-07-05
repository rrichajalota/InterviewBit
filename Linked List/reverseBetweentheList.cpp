/*  ReverseBetweenTheList
    Reverse a linked list from position m to n. Do it in-place and in one-pass.

    For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list. Note 2:
    Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if(!A || m==n )                     //if A= NULL or m=n return the list as it is
        return A;
        
    ListNode *slow= A, *pslow= NULL;    //pslow is previous pointer for slow pointer.
    int i= 1;
    
    while(i < m){                       //first move the slow pointer to mth position
        pslow= slow;
        slow= slow->next;
        ++i;
    }
    
    ListNode *fast= slow->next, *pfast= slow; //place the fast pointer after the slow pointer
    
    while(i<n){                             //move the fast pointer until it reaches the nth position
        ListNode *next= fast->next;         //and reverse the links as fast pointer moves ahead
        fast->next= pfast;
        pfast= fast;
        fast= next;
        ++i;
    }
    
    slow->next= fast;                       
    
    if(!pslow)                          //if pslow=NULL, it means m=1 and A needs to be adjusted
        A= pfast;
        
    else pslow->next= pfast;            
    
    return A;
}
