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

        int get_size();
        int get_sum();
        void update();
    };

    Node* head;


    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    static Node* merge(Node* t1, Node* t2);

public:
    Treap();
    ~Treap();
    void insert(int val, int pos);
    void erase(Node* t, int pos);
    int summa(int _from, int _to);
    static void print_bst(Node* root);
    static void print_numbers(Node* root);
};
