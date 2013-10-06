/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Merge Two Sorted Lists
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 07时54分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
            
        ListNode* pre = new ListNode(-1);
        ListNode* tail = pre;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                tail -> next = l1;
                l1 = l1 -> next;
            }
            else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;
        }
        
        if(l1 == NULL)
            tail -> next = l2;
        if(l2 == NULL)
            tail -> next = l1;
            
        ListNode* head = pre -> next;
        delete pre;
        return head;
    }
};
