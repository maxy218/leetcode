/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年10月15日 21时36分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(head == NULL)
			return NULL;
        // copy the node at first.
		RandomListNode* cur = head;
		while(cur != NULL){
			RandomListNode* tmp = new RandomListNode(cur -> label);
			tmp -> next = cur -> next;
			cur -> next = tmp;
			cur = cur -> next -> next;
		}
		
		cur = head;
		while(cur != NULL){
			if(cur -> random){
				cur -> next -> random = cur -> random -> next;
			}
			cur = cur -> next -> next;
		}
		
		// split out the new copied linklist
		RandomListNode* newHead = head -> next;
		RandomListNode* newCur = newHead;
		cur = head;
		// while(cur != NULL && newCur != NULL){
		while(cur){
			newCur = cur -> next;
			cur -> next = newCur -> next;
			cur = newCur -> next;
			if(cur){
				newCur -> next = cur -> next;
				newCur = cur -> next;
			}
		}
		return newHead;
    }
};
