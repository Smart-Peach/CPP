#include "03-Treap_construc.hpp"

int Treap::Node::get_size(Node* node) {
    return node ? node->size : 0;
}

int Treap::Node::get_sum(Node* node) {
    return node ? node->sum : 0;
}

void Treap::Node::update() {
    this->size = 1 + get_size(this->left) + get_size(this->right);
    this->sum = this->val + get_sum(this->left) + get_sum(this->right);
}

void Treap::split_by_size(Node* t, int size, Node*& left, Node*& right) {
    if (!t) {
        left = right = nullptr;
        return;
    }

    if (size <= Node::get_size(t->left)) {
        split_by_size(t->left, size, left, t->left);
        t->update();
        right = t;
    }
    else {
        split_by_size(t->right, size - Node::get_size(t->left) - 1, t->right, right);
        t->update();
        left = t;
    }
}

Treap::Node* Treap::merge(Node* t1, Node* t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }

    if (t1->priority < t2->priority) {
        t1->right = merge(t1->right, t2);
        t1->update();
        return t1;
    }
    else {
        t2->left = merge(t1, t2->left);
        t2->update();
        return t2;
    }
}

Treap::Treap() : head(nullptr) {}

// Copy constructor
Treap::Treap(const Treap& other) : head(deep_copy(other.head)) {}

Treap::~Treap() {
    delete head;
}

Treap::Node* Treap::deep_copy(Treap::Node* other) {
    if (!other) {
        return nullptr;
    }
    Node* new_node;
    new_node->val = other->val;
    new_node->priority = other->priority;
    new_node->size = other->size;
    new_node->sum = other->sum;
    new_node->left = deep_copy(other->left);
    new_node->right = deep_copy(other->right);
    return new_node;
} 

// Assignment operator
Treap& Treap::operator=(const Treap& other) {
    if (this != &other) {
         clear(head);
         head = deep_copy(other.head);
    }
    return *this;
}

void Treap::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void Treap::insert(int val, int pos) {
    Node* l, * r;
    split_by_size(head, pos - 1, l, r);
    Node* new_node = new Node{val};
    Node* t1 = merge(l, new_node);
    this->head = merge(t1, r);
}

void Treap::erase(Treap::Node* t, int pos) {
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

void Treap::print_bst(Treap::Node* root) {
    if (!root) {
        std::cout << "x ";
        return;
    }
    std::cout << root->val << " ";
    print_bst(root->left);
    print_bst(root->right);
}

void Treap::print_numbers(Treap::Node* root) {
    if (root->left) {
        print_numbers(root->left);
    }
    std::cout << root->val << ' ';
    if (root->right) {
        print_numbers(root->right);
    }
}

int main() {}
