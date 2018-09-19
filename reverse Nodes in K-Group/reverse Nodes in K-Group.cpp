class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int count = 0;
		bool first = false;
		ListNode** chain = new ListNode*[k];
		ListNode* new_Head = head;
		ListNode* tmp = NULL;
		if (head == NULL)
			return head;
		while (true) {
			if (head!= NULL) {           // count less than k, break.
				chain[count] = head;
				head = head->next;
			}
			else
				break;
			count++;
			if (count == k) {                   //to reverse
				count = 0;
				if (!first) {                   //change the begin node of list
					new_Head = chain[k - 1];
					first = true;
				}
                if(tmp != NULL){
                    tmp->next = chain[k-1];
                }
                tmp = chain[0];  //save the next order begin node
                tmp->next = chain[k-1]->next;
				for (int i = k - 1; i >= 1; i--) {
					chain[i]->next = chain[i - 1];
				}  
			}
		}
		return new_Head;
	}
};