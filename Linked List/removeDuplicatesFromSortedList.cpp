/*  Remove duplicates from sorted list
    Given a sorted linked list, delete all duplicates such that each element appear only once.

    For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.
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
    if(!A) 
        return A;
    ListNode* temp= A;
    while(temp->next){
        if(temp->val==temp->next->val){
            temp->next= temp->next->next;
        }
        else temp= temp->next;
    }
    return A;
}
