/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
	    public:
            ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry=0;
		ListNode result(0),*end=&result;
		while(l1||l2||carry){
			int digitSum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
			end->next=new ListNode(digitSum%10);
			end=end->next;
			carry=digitSum/10;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return result.next;
	}
};
