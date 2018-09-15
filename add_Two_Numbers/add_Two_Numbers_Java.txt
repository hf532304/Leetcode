/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int added = 0;
        ListNode head, res = new ListNode(0);
        head = res;
        while(l1 != null || l2 != null || added !=0){
                res.next = new ListNode(0);
                res = res.next;
                res.val = (l1!=null? l1.val : 0) + (l2!=null? l2.val : 0) + added;
                added = res.val >= 10? 1 : 0;
                res.val = res.val % 10;
                l1 = (l1!=null)? l1.next : l1;
                l2 = (l2!=null)? l2.next : l2;
            }
                return head.next;
        }
    }