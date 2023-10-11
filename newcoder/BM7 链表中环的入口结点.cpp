struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 快慢指针 记环外为X 环内慢指针已走 Y 未走 Z
    // 则慢已走 X+Y 快已走 2(X+Y)
    // 环内 慢未走 Z = 2(X+Y) - 2Y - X = X
    // 所以相遇后 从起点再走一个慢指针 两个慢指针走X相遇即为入点
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *fast = pHead, *slow = pHead;
        while (fast) {
            if (fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow){
                    break;
                }
            }else{
                return nullptr;
            }
        }
        ListNode *newSlow = pHead;
        while (newSlow != slow) {
            newSlow = newSlow->next;
            slow = slow->next;
        }
        return newSlow;
    }
};