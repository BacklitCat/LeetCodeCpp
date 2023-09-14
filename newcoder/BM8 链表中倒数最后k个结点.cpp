struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        if (pHead == nullptr) {
            return nullptr;
        }
        // 虚头 代码优雅
        auto vHead = new ListNode(0);
        vHead->next = pHead;

        // 快慢指针 k是从1数
        ListNode *fast = vHead, *slow = vHead;

        // 先让fast走k
        int n = k;
        while (n--) {
            if (fast->next) {
                fast = fast->next;
            } else { // k过大直接null
                return nullptr;
            }
        }
        // 再让fast走到null
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};