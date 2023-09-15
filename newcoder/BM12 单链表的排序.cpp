/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <iostream>
#include <queue>

using namespace std;

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
     * @param head ListNode类 the head node
     * @return ListNode类
     */

    static bool cmp(ListNode *node1, ListNode *node2) {
        return node1->val > node2->val; // 最小堆
    }

    ListNode *sortInList(ListNode *head) {
        if (head == nullptr) return nullptr;
        // 思路 1.用最小堆
        priority_queue<ListNode *, vector<ListNode *>, decltype(&cmp)> q(cmp);
        ListNode *p = head;
        while (p) {
            q.emplace(p);
            p = p->next;
        }
        auto vhead = new ListNode(0);
        ListNode *tail = vhead;
        while (!q.empty()) {
            auto top = q.top();
            tail->next = top;
            tail = top;
            q.pop();
        }
        tail->next = nullptr;
        return vhead->next;
    }
};