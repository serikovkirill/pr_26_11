//???????? ???????, ??????? ????????? ???????? ??? ???????? ?????? ?????????
//???????: ???? ???????? data ? ??????, ?? ????????? ?? 2 (2 * ?); ???? ????????, ??
//???????? ?? 3 ? ??????? 1 (3 * ? - 1).
#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* next;
    Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_Empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_Empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_Empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(int _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_Empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_Empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(int _val) {
        if (is_Empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if (is_Empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
    void reverse() {
        struct Node* p = first,
            * q = nullptr, * r;
        while (p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }
};


int main()
{
    list l;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> i;
        l.push_back(i);
    }
    l.print();
    l.reverse();
    l.print();
}