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
   void Binary_Insert(vector<int>& V, int num){
        int left = 0;
        int right = V.size() - 1;
        int mid = 0;
		if(right == -1){V.insert(V.begin(), num);return;}
        if(right == 0){
            if(num > V[0]) V.insert(V.begin() + 1, num);
            else V.insert(V.begin(), num);
            return;
        }
        while(left <= right){                        //binary search
            mid = (left + right + 1) / 2;
            if(num == V[mid]){
                left = mid;
                break;
            }
            if(num > V[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
       V.insert(V.begin() + left, num);
    }
    ListNode* insertionSortList(ListNode* head) {// to decrease time complexity, use a vector to record the sorted list
        vector<int> Vec;
        ListNode* current = head;
        int count = 0;  
        while(current != NULL){
            Binary_Insert(Vec,current->val);
            current = current -> next;
        }
        current = head;
        while(current != NULL){
            current->val = Vec[count];
            current = current->next;
            count ++;
        }
        return head;
    }
};