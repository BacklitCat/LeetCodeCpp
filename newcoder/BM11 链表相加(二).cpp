/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <iostream>

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
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    void printList(ListNode *vhead) {
        ListNode *p = vhead->next;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    void reverse(ListNode *vhead) {
        // 空链表 或 只有一个节点 快速返回
        if (vhead->next == nullptr || vhead->next->next == nullptr) {
            return;
        }
        // p 待头插节点 tail 尾节点
        ListNode *p = vhead->next->next, *tail = vhead->next, *t;
        tail->next = nullptr;

        while (p) {
            t = p->next;
            p->next = vhead->next;
            vhead->next = p;
            p = t;
        }
        return;
    }

    void addNumAtHead(ListNode *vhead, int val) {
        ListNode *t = vhead->next;
        auto newNode = new ListNode(val);
        newNode->next = t;
        vhead->next = newNode;
    }

    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // 思路：1.反转链表 2.相加 3.头插新链
        auto vhead1 = new ListNode(0), vhead2 = new ListNode(0);
        vhead1->next = head1;
        vhead2->next = head2;
        // printList(vhead1); printList(vhead2);
        reverse(vhead1);
        reverse(vhead2);
        // printList(vhead1); printList(vhead2);

        ListNode *p1 = vhead1->next, *p2 = vhead2->next;
        auto ret = new ListNode(0);
        int sum = 0, num1 = 0, num2 = 0;

        while (p1 && p2) {
            sum = p1->val + p2->val + num2;
            num1 = sum % 10;
            num2 = (sum - num1) / 10;
            addNumAtHead(ret, num1);
            p1 = p1->next;
            p2 = p2->next;
        }

        // printList(ret);

        ListNode *left = p1 != nullptr ? p1 : p2;

        while (left) {
            sum = left->val + num2;
            num1 = sum % 10;
            num2 = (sum - num1) / 10;
            addNumAtHead(ret, num1);
            left = left->next;
        }

        // printList(ret);

        if (num2 > 0) {
            addNumAtHead(ret, num2);
        }

        // printList(ret);
        return ret->next;
    }
};