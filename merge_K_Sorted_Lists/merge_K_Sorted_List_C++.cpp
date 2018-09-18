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
    struct cmp{
        bool operator ()(const ListNode *a, const ListNode *b){
            return a->val >= b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists){     //try to use the priority queue
        priority_queue<ListNode*, vector<ListNode*>, cmp> PQ;
        ListNode *res = new ListNode(0);                             //for storing results
        ListNode *head = res;
        for(int i = 0; i < lists.size(); i++){
            ListNode *cur = NULL;                         //cur points to the current position of lists[i]
            cur = lists[i];
            if(cur != NULL){                             //cur could be null at the beginning
                PQ.push(cur);
            }
        }
        while(!PQ.empty()){
            ListNode *tmp = PQ.top();
            PQ.pop();
            if(tmp->next != NULL){
                PQ.push(tmp->next);
            }
            res->next = new ListNode(tmp->val);
            res = res->next;
        }
        return head->next;
    }
};