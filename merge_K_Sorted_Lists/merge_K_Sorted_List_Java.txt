/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode merge2Lists(ListNode a, ListNode b){
        if(a == null)
            return b;
        if(b == null)
            return a;
        if(a.val > b.val)
            return merge2Lists(b,a);
        ListNode head = new ListNode(0);
        head.next = a;
        ListNode tmp;
        while(head.next != null && b != null){
            if(head.next.val <= b.val){
                head = head.next;
            }
            else{
                tmp = head.next;                //insert b to a
                head.next = new ListNode(b.val);
                head.next.next = tmp;
                head = head.next;
                b = b.next;
            }
        }
        while(b != null){
            head.next = new ListNode(b.val);
            b = b.next;
            head = head.next;
        }
        return a;
    }
    public ListNode mergeKLists(ListNode[] lists) {   //merge with divide and conquer
        if(lists.length == 0)
            return null;
        List<ListNode> list = Arrays.asList(lists);
        ArrayList <ListNode> Input = new ArrayList<ListNode>();
        Input.addAll(list);
        int tmp = 0;
        while(Input.size() > 1){            //divide and merge
            while(tmp + 1 <= Input.size() -1)
            {
                Input.set(tmp, merge2Lists(Input.get(tmp), Input.get(tmp+1)));
                Input.remove(tmp+1);
            }
            tmp = 0;
        }
        return Input.get(0);
    }
}