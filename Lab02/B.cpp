#include <iostream>
#include <assert.h>
using namespace std;

template <typename Elem> class Link {
public:
    Elem element;
    Link *pre;
    Link *next;
    Link(const Elem& elemval, Link *preval = NULL, Link* nextval = NULL) {
        element = elemval;
        pre = preval;
        next = nextval;
    }
    Link(Link* preval = NULL, Link* nextval = NULL) {
        pre = preval;
        next = nextval;
    }
};

template <typename Elem> class Linked_stack {
private:
    Link<Elem>* head;
    Link<Elem>* back;
    Link<Elem>* tail;
    int cnt;
    void init() {
        head = new Link<Elem>();
        tail = new Link<Elem>();
        head->next = tail;
        tail->pre = head;
        cnt = 0;
        back = head;
    }
    void clear() {
        while(back != head) {
            Link<Elem>* temp = back;
            back = back->pre;
            delete temp;
        }
        delete head;
        delete tail;
    }
public:
    Linked_stack() {
        init();
    }
    ~Linked_stack() {
        clear();
        init();
    }
    int size() {
        return cnt;
    }
    void Push(const Elem& it) {
        Link<Elem>* temp = back->next;
        back->next = new Link<Elem>(it, back, temp);
        temp->pre = back->next;
        cnt++;
        back = back->next;
    }
    void Pop() {
        assert(back != head);
        Link<Elem>* temp = back;
        back = back->pre;
        back->next = temp->next;
        temp->next->pre = back;
        delete temp;
        cnt--;
    }
    Elem Top() {
        assert(back != head);
        return back->element;
    }
};//1-indexed

int main() {
    Linked_stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << "The size of s: " << s.size() << '\n';
    cout << s.Top() << '\n';
    s.Pop();
    cout << s.Top() << '\n';
    s.Pop();
    cout << s.Top() << '\n';
    return 0;
}
