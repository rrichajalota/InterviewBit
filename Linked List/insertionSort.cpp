/*  Insertion Sort List
    Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {

    if(!A || !A->next)
        return A;
    ListNode *ans=A;
    A= A->next;
    ans->next= NULL;
    
    while(A){
        ListNode* next= A->next, *prev=NULL, *temp= ans;

        while(temp && temp->val < A->val){
            prev= temp;
            temp= temp->next;
        }

        A->next= temp;
        if(prev==NULL)
            ans= A;

        else prev->next= A;
        
        A= next;
    }

    return ans;
}
