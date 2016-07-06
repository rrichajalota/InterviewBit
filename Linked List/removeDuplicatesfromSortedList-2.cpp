/*  Remove Duplicates from sorted list- 2
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

    For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(!A){
        return A;
    }
    
    ListNode* temp= A, *prev=NULL;
    
    while(temp && temp->next){
        
        if(temp->val== temp->next->val){
            
            while(temp && temp->next && temp->val==temp->next->val){
                temp= temp->next;
            }
            
            if(prev){
                prev->next= temp->next;
                temp = prev->next;
            }
            else{
                A= temp->next;
                temp= A;
            } 
        }
        
        else{
            prev= temp;
            temp= temp->next;
        }
    }
    return A;
}
