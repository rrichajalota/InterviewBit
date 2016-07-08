/*  Reorder List
    Given a singly linked list

        L: L0 → L1 → … → Ln-1 → Ln,
    reorder it to:

        L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
    You must do this in-place without altering the nodes’ values.

    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    ListNode *fast= A, *slow= A, *prev= NULL;
    
    while(fast && fast->next){      //find the middle of the list
        prev= slow;
        slow= slow->next;
        fast= fast->next->next;
    }
    
    prev= slow;         
    slow= slow->next;
    prev->next= NULL;
    
    while(slow!= NULL){             //reverse the latter part of the list
        ListNode *next= slow->next;
        slow->next= prev;
        prev= slow;
        slow= next;
    }
    
    ListNode *temp= A, *tail= prev;
    
    while(tail != temp->next){      //considering the case of even-numbered list
        ListNode *next= tail->next;
        tail->next= temp->next;
        temp->next= tail;
        temp= tail->next;
        tail= next;
        if(tail==temp)              // in case of odd-numbered list
            break;
    }
    return A;
}
