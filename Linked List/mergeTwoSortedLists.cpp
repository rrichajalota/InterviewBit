/*  Merge Two Sorted Lists

    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

    For example, given following linked lists :

      5 -> 8 -> 20 
      4 -> 11 -> 15
    The merged list should be :

    4 -> 5 -> 8 -> 11 -> 15 -> 20
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode *temp1= A, *prev1= NULL, *temp2= B;
    
    while(temp1 && temp2){
        
        if(temp1->val <= temp2->val){
            prev1= temp1;
            temp1= temp1->next;
        }
        
        else{
            
            ListNode *next= temp2->next;
            
            if(prev1){
                temp2->next= temp1;
                prev1->next= temp2;
                prev1= temp2;
            }
            
            else{
                temp2->next= A;
                A= temp2;
                prev1= temp2;
            }
            
            temp2= next;
        }
    }
    
    if(!temp1 && temp2){
       prev1->next= temp2;
    }
    
    return A;
}
