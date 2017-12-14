#include <iostream>
#include <string>
using namespace std;

template <typename Elem> class Link {
public:
    Elem element;
    Link *pre;
    Link *next;
    Link(const Elem& elemval, Link *preval = NULL, Link *nextval = NULL) {
        element = elemval;
        pre = preval;
        next = nextval;
    }
    Link(Link *preval = NULL, Link *nextval = NULL) {
        pre = preval;
        next = nextval;
    }
};

template <typename Elem> class Linked_list {
private:
    Link<Elem> *head;
    Link<Elem> *tail;
    Link<Elem> *curr;
    int cnt;
    void init() {
        head = new Link<Elem>();
        tail = new Link<Elem>();
        head->next = tail;
        tail->pre = head;
        curr = head;
        cnt = 0;
    }
    void clear() {
        curr = head->next;
        while(curr != tail) {
            Link<Elem> *temp = curr;
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
    void append(const Elem& it) {
        curr = tail->pre;
        curr->next = new Link<Elem>(it, curr, tail);
        tail->pre = curr->next;
        cnt--;
    }
    void insert(int n, const Elem A[]) {
        for(int i = 0; i < n; ++i) {
            append(A[i]);
        }
    }
    void show() {
        if(cnt == 0) return;
        curr = head->next;
        while(curr != tail) {
            std::cout << curr->element;
            if(curr->next != tail) std::cout << " ";
            curr = curr->next;
        }
        std::cout << '\n';
    }
    void rshow() {
        if(cnt == 0) return;
        curr = tail->pre;
        while(curr != head) {
            std::cout << curr->element;
            if(curr->pre != head) std::cout << " ";
            curr = curr->pre;
        }
        std::cout << '\n';
    }
    Link<Elem>* Remove(Link<Elem>* removal) {
        Link<Elem>* temp = removal->pre;
        temp->next = removal->next;
        removal->next->pre = temp;
        delete removal;
        cnt--;
        return temp->next;
    }
    void Delete(const Elem& it) {
        curr = head->next;
        while(curr != tail) {
            if(curr->element == it) {
                curr = Remove(curr);
            }
            else curr = curr->next;
        }
    }
};

int main() {
    string order;
    Linked_list<int> list;
    while(cin >> order) {
        if(order == "END") break;
        else if(order == "insert") {
            int n;
            cin >> n;
            int *A = new int[n];
            for(int i = 0; i < n; ++i) cin >> A[i];
            list.insert(n, A);
        }
        else if(order == "show") {
            list.show();
        }
        else if(order == "rshow") {
            list.rshow();
        }
        else if(order == "delete") {
            int elem;
            cin >> elem;
            list.Delete(elem);
        }
    }
    return 0;
}
