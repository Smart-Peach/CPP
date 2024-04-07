#include <iostream>
#include <random>

class Treap {

private:
    struct Node {
        int val = 0;
        int priority = rand() % ((int)pow(2,32) - 1);;
        int size = 1;
        int sum = val;
        Node* left = nullptr;
        Node* right = nullptr;

        // Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right) {
        //     priority = rand() % ((int)pow(2,32) - 1);
        //     size = 1;
        //     sum = val;
        // }

        // ~Node() {
        //     delete left;
        //     delete right;
        // }
    };

    int get_size(Node* t) {
        return t ? t->size : 0;
    }

    int get_sum(Node* t) {
        return t ? t->sum : 0;
    }

    void split_by_size(Node* t, int size, Node*& left, Node*& right) {
        if (!t) {
            left = right = nullptr;
            return;
        }

        if (size <= get_size(t->left)) {
            split_by_size(t->left, size, left, t->left);
            update(t);
            right = t;
        }
        else {
            split_by_size(t->right, size - get_size(t->left) - 1, t->right, right);
            update(t);
            left = t;
        }
    }

    void update(Node* t) {
        t->size = 1 + get_size(t->left) + get_size(t->right);
        t->sum = t->val + get_sum(t->left) + get_sum(t->right);
    }

    Node* merge(Node* t1, Node* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }

        if (t1->priority < t2->priority) {
            t1->right = merge(t1->right, t2);
            update(t1);
            return t1;
        }
        else {
            t2->left = merge(t1, t2->left);
            update(t2);
            return t2;
        }
    }

public:
    Node* head;

    Treap() : head(nullptr) {}


    void insert(int val, int pos) {
        Node* l, * r;
        split_by_size(head, pos - 1, l, r);
        // Node* new_node;
        // new_node->val = val;
        Node* new_node = new Node(val);
        Node* t1 = merge(l, new_node);
        head = merge(t1, r);
    }

    void erase(Node* t, int pos) {
        Node* l, * r;
        split_by_size(t, pos - 1, l, r);
        Node* e, * rr;
        split_by_size(r, 1, e, rr);
        head = merge(l, rr);
    }

    int summa(int _from, int _to) {
        if (_from < 1 || _from > head->size || _to > head->size) {
            throw std::out_of_range("Index out of range!");
        }
        Node* l, * r;
        split_by_size(head, _from - 1, l, r);
        Node* rl, * rr;
        split_by_size(r, _to - _from + 1, rl, rr);
        return rl->sum;
    }


    void print_bst(Node* root) {
        if (!root) {
            std::cout << "x ";
            return;
        }
        std::cout << root->val << " ";
        print_bst(root->left);
        print_bst(root->right);
    }

    void print_numbers(Node* root) {
        if (root->left) {
            print_numbers(root->left);
        }
        std::cout << root->val << ' ';
        if (root->right) {
            print_numbers(root->right);
        }
    }

    ~Treap() {
        delete head;
    }
};

int main() {
    Treap treap;
    //treap.insert(1, 0);
    //treap.insert(2, 1);
    //treap.insert(3, 2);

    // 5 24 42 13 99 2 17
    treap.insert(5, 1);
    treap.insert(17, 2);
    treap.insert(99, 2);
    treap.insert(2, 3);
    treap.insert(24, 2);
    treap.insert(13, 3);
    treap.insert(42, 3);
    treap.insert(92, 3);
    treap.insert(12, 3);

    std::cout << "BST: ";
    treap.print_bst(treap.head);
    std::cout << std::endl;

    std::cout << "Values: ";
    treap.print_numbers(treap.head);
    std::cout << std::endl;

    return 0;
}
