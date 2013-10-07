/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2013 11:48:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* cur = head;
        while(cur -> next){
            if(cur -> next -> val == cur -> val){
                ListNode* tmp = cur -> next;
                cur -> next = cur -> next -> next;
                delete tmp;
            }
            else{
                cur = cur -> next;
            }
        }
        return head;
    }
};
