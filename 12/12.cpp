#include "12.hpp"

template <typename T>
int Treap<T>::Node::get_size(Node* node) {
    return node ? node->size : 0;
}

template <typename T>
T Treap<T>::Node::get_sum(Node* node) {
    return node ? node->sum : 0;
}

template <>
std::string Treap<std::string>::Node::get_sum(Node* node) {
    return node ? node->sum : "";
}

template <typename T>
void Treap<T>::Node::update() {
    this->size = 1 + get_size(this->left) + get_size(this->right);
    this->sum = this->val + get_sum(this->left) + get_sum(this->right);
}

template <typename T>
Treap<T>::Treap() : head(nullptr) {}

//Copy ctor
template <typename T>
Treap<T>::Treap(const Treap& other) {
    int pos = Node::get_size(head);
    head = nullptr;
    copyTreap(other.head, pos);
}

// Assignment operator
template <typename T>
Treap<T>& Treap<T>::operator=(const Treap<T>& other) {
    if (this != &other) {
        int pos = Node::get_size(head);
        clearTreap(this->head);
        copyTreap(other.head, pos);
    }
    return *this;
}

// Move constructor
template <typename T>
Treap<T>::Treap(Treap<T>&& other) {
    head = other.head;
    other.head = nullptr;
}

// Move assignment operator
template <typename T>
Treap<T>& Treap<T>::operator=(Treap<T>&& other) {
    if (this != &other) {
        delete head;
        this->head = other.head;
        other.head = nullptr;
    }
    return *this;
}

template <typename T>
Treap<T>::~Treap() {
    clearTreap(head);
}

template <typename T>
void Treap<T>::clearTreap(Node* node) {
    if (node){
        clearTreap(node->left);
        clearTreap(node->right);
        delete node;
        node = nullptr;
    }
}

template <typename T>
void Treap<T>::copyTreap(Node* node, int pos) {
    if (node != nullptr) {
        copyTreap(node->left, pos);
        insert(node->val, pos);
        copyTreap(node->right, pos);
    }
}

template <typename T>
void Treap<T>::split_by_size(Node* t, int size, Node*& left, Node*& right) {
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

template <typename T>
void Treap<T>::merge(Node*& t1, Node*& t2, Node*& parent) {
    if (!t1) {
        parent = t2;
        parent->parent = nullptr;
        return;
    }
    if (!t2) {
        parent = t1;
        parent->parent = nullptr;
        return;
    }

    if (t1->priority < t2->priority) {
        merge(t1->right, t2, t1->right);
        t1->update();
        t1->right->parent = t1;
        parent = t1;
    }
    else {
        merge(t1, t2->left, t2->left);
        t2->update();
        t2->left->parent = t2;
        parent = t2;
    }
    parent->parent = nullptr;
}

template <typename T>
void Treap<T>::insert(T val, int pos) {
    Node* l, * r;
    split_by_size(head, pos - 1, l, r);
    Node* new_node = new Node(val);
    Node* t1;
    merge(l, new_node, t1);
    Node* t2;
    merge(t1, r, t2);
    this->head = t2;
}

template <typename T>
void Treap<T>::erase(Treap<T>::Node* t, int pos) {
    Node* l, * r;
    split_by_size(t, pos - 1, l, r);
    Node* e, * rr;
    split_by_size(r, 1, e, rr);
    delete e;
    Node* h;
    merge(l, rr, h);
    this->head = h;
}

template <typename T>
T Treap<T>::summa(int _from, int _to) {
    if (_from < 1 || _from > this->head->size || _to > this->head->size) {
        throw std::out_of_range("Index out of range!");
    }
    Node* l, * r;
    split_by_size(this->head, _from - 1, l, r);
    Node* rl, * rr;
    split_by_size(r, _to - _from + 1, rl, rr);
    return rl->sum;
}

template <typename T>
void Treap<T>::print_bst(Treap<T>::Node* root) {
    if (!root) {
        std::cout << "x ";
        return;
    }

    T parent_val = T();
    if (root->parent) {
        parent_val = root->parent->val;
    }

    std::cout << root->val << " (" << parent_val << ") ";
    print_bst(root->left);
    print_bst(root->right);
}

template <typename T>
std::string Treap<T>::print_numbers(Treap<T>::Node* root, std::string line) {
    if (root->left) {
        print_numbers(root->left, line);
    }
    line = line + std::to_string(root->val) + " ";
    if (root->right) {
        print_numbers(root->right, line);
    }
    return line;
}

template<>
std::string Treap<std::string>::print_numbers(Treap<std::string>::Node* root, std::string line) {
    if (root->left) {
        print_numbers(root->left, line);
    }
    line = line + root->val + " ";
    if (root->right) {
        print_numbers(root->right, line);
    }
    return line;
}


template <typename T>
typename Treap<T>::Node* Treap<T>::get_head() { return head; }

// ITERATOR FUNCTIONS :

template<typename T>
typename Treap<T>::Node* Treap<T>::get_leftest(Treap<T>::Node* root) {
    // if (!root->left or !root) { return root; }
    // get_leftest(root->left);
    if(!root->left || !root) { return root; }
    // std::cout << root->val << std::endl;
    return get_leftest(root->left);
}

template<typename T>
typename Treap<T>::Iterator& Treap<T>::Iterator::operator++(){
    if (curr_node->right) {
        curr_node = get_leftest(curr_node->right);
    } else {
        Node* parent = curr_node->parent;
        while(parent && curr_node == parent->right) {
            curr_node = parent;
            parent = curr_node->parent;
        }
        curr_node = parent;
    }
    return *this;
}

template class Treap<int>;
template class Treap<double>;
template class Treap<bool>;
// template class Treap<std::string>;
