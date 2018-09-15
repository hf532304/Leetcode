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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = NULL;
        ListNode *cur1 = NULL;
        ListNode *res = NULL;
        ListNode *res_head = NULL;
        cur = l1;
        cur1 = l2;
        while(cur != NULL || cur1 != NULL){
            if(res == NULL){
                res_head = new ListNode(0);
                res = res_head;
            }
            else if(res !=NULL && res->next == NULL){
                res->next = new ListNode(0);
                res = res->next;
            }
            else
                res = res->next;
            res->val = (cur? cur->val:0) + (cur1 ? cur1->val : 0) + res->val;
            if(res->val >= 10){
                res->val = res->val - 10;
                   res->next = new ListNode(1);
            }
            cur = cur? cur->next : cur;
            cur1 = cur1? cur1->next : cur1;
        }
        return res_head;
    }
};