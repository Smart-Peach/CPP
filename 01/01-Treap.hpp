#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>

class Treap {
private:
    struct Node {
        int val = 0;
        int priority = rand() % ((int)std::pow(2, 32) - 1);
        int size = 1;
        int sum = val;
        Node* left = nullptr;
        Node* right = nullptr;

        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* head;

    int get_size(Node* t);
    int get_sum(Node* t);
    void split_by_size(Node* t, int size, Node*& left, Node*& right);
    void update(Node* t);
    Node* merge(Node* t1, Node* t2);

public:
    Treap();
    ~Treap();
    void insert(int val, int pos);
    void erase(Node* t, int pos);
    int summa(int _from, int _to);
    void print_bst(Node* root);
    void print_numbers(Node* root);
};
