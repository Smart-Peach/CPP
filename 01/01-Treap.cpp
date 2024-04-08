#include "Treap.hpp"

void Node::update() {
    this->size = 1 + get_size(this->left) + get_size(this->right);
    this->sum = this->val + get_sum(this->left) + get_sum(this->right);
}

int Node::get_size() {
    return this ? this->size : 0;
}

int Node::get_sum() {
    return this ? this->sum : 0;
}

static void Treap::split_by_size(Node* t, int size, Node*& left, Node*& right) {
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

static Treap::Node* Treap::merge(Node* t1, Node* t2) {
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

Treap::Treap() : head(nullptr) {}

Treap::~Treap() {
    delete head;
}

void Treap::insert(int val, int pos) {
    Node* l, * r;
    split_by_size(head, pos - 1, l, r);
    Node* new_node = new Node{val};
    Node* t1 = merge(l, new_node);
    this->head = merge(t1, r);
}

void Treap::erase(Node* t, int pos) {
    Node* l, * r;
    split_by_size(t, pos - 1, l, r);
    Node* e, * rr;
    split_by_size(r, 1, e, rr);
    delete e;
    this->head = merge(l, rr);
}

int Treap::summa(int _from, int _to) {
    if (_from < 1 || _from > this->head->size || _to > this->head->size) {
        throw std::out_of_range("Index out of range!");
    }
    Node* l, * r;
    split_by_size(this->head, _from - 1, l, r);
    Node* rl, * rr;
    split_by_size(r, _to - _from + 1, rl, rr);
    return rl->sum;
}

static void Treap::print_bst(Node* root) {
    if (!root) {
        std::cout << "x ";
        return;
    }
    std::cout << root->val << " ";
    print_bst(root->left);
    print_bst(root->right);
}

static void Treap::print_numbers(Node* root) {
    if (root->left) {
        print_numbers(root->left);
    }
    std::cout << root->val << ' ';
    if (root->right) {
        print_numbers(root->right);
    }
}
