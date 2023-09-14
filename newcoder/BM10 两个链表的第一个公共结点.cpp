struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

#include <cstdlib>
class Solution {
public:
    int countLen(ListNode *head){
        int count = 0;
        ListNode *p=head;
        while (p) {
            count++;
            p = p -> next;
        }
        return count;
    }

    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==pHead2) return pHead1;
        int l1 = countLen(pHead1), l2 = countLen(pHead2);
        int diff = abs(l1-l2);
        auto vHead1 = new ListNode(0), vHead2 = new ListNode(0);
        vHead1->next = pHead1; vHead2->next = pHead2;
        ListNode *fast = l1 >= l2 ? vHead1 : vHead2;
        ListNode *slow = l1 < l2 ? vHead1 : vHead2;
        while (diff--) {
            fast = fast -> next;
        }
        while(fast->next && slow->next){
            fast = fast -> next;
            slow = slow -> next;
            if(fast==slow){
                return fast;
            }
        }
        return nullptr;
    }
};
