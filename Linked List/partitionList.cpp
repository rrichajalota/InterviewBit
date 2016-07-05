/*  Partition List

    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.

    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {

    ListNode *temp= A, *smallhead= NULL, *small= NULL, *largehead= NULL, *prev= NULL;

    while(temp){

        if(temp->val < B){
            if(smallhead==NULL)
                smallhead= temp;
            else small->next= temp;
            
            small= temp;
            if(prev)
                prev->next= temp->next;
        }

        else if(temp->val >= B){
            if(largehead==NULL)
                largehead= temp;
            prev= temp;
        }

        temp= temp->next;
    }

    if(smallhead && largehead){
        small->next= largehead;
        return smallhead;
    }

    if(!smallhead && largehead)
        return largehead;
        
    return smallhead;
}
