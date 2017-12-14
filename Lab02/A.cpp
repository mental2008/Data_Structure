#include <iostream>
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

template <typename Elem> class Linked_list {
private:
    Link<Elem>* head;
    Link<Elem>* curr;
    Link<Elem>* tail;
    int cnt;
    int currPos;
    void init() {
        head = new Link<Elem>();
        tail = new Link<Elem>();
        head->next = tail;
        tail->pre = head;
        cnt = 0;
        curr = head;
        currPos = 0;
    }
    void clear() {
        curr = head->next;
        while(curr != tail) {
            Link<Elem>* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        delete tail;
    }
public:
    Linked_list() {
        init();
    }
    ~Linked_list() {
        clear();
        init();
    }
    int size() {
        return cnt;
    }
    bool SetPos(int pos) {
        if(pos > cnt) return false;
        currPos = pos;
        curr = head;
        for(int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        return true;
    }
    void Insert(const Elem& it) {
        Link<Elem>* temp = curr->next;
        curr->next = new Link<Elem>(it, curr, temp);
        temp->pre = curr->next;
        cnt++;
        curr = curr->next;
        currPos++;
    }
    bool Insert(const Elem& it, int pos) {
        if(!SetPos(pos)) return false;
        Insert(it);
        return true;
    }
    bool Remove() {
        if(curr == head) return false;
        Link<Elem>* temp = curr;
        curr = curr->pre;
        curr->next = temp->next;
        temp->next->pre = curr;
        Elem& it = temp->element;
        delete temp;
        cnt--;
        return true;
    }
    void Print() {
        Link<Elem>* temp = head->next;
        while(temp != tail) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};//1-indexed

int main() {
    Linked_list<int> test;
    test.Insert(1);
    test.Insert(2);
    test.Insert(3);
    test.Insert(4);
    test.Insert(5);
    test.SetPos(2);
    test.Remove();
    test.Insert(6, 2);
    cout << "The size of test: " << test.size() << '\n';
    test.Print();
    return 0;
}
