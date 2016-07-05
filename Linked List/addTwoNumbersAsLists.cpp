/*  Add Two Numbers as Lists
    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

        342 + 465 = 807
    Make sure there are no trailing zeros in the output list
    So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    if(!B)
        return A;
    if(!A) 
        return B;
        
    ListNode *temp1= A, *temp2= B, *prev=NULL, *ans=NULL;
    int sum= 0,carry= 0;
    
    while(temp1 || temp2){
        sum= (temp1 ? temp1->val: 0) + (temp2 ? temp2->val: 0)+carry;

        carry= sum/10;
        
        ListNode *node= new ListNode(sum % 10);
        
        if(ans==NULL)
            ans= node;
        else 
            prev->next= node;
        
        prev= node;
        if(temp1)
            temp1= temp1->next;
        if(temp2)
            temp2= temp2->next;
    };     
    
    if(carry && !temp1 && !temp2){
        ListNode *node= new ListNode(carry);
        prev->next= node;
        prev= node;
    }
   
    return ans; 
}
