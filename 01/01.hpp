#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>

class Treap {

public:
    struct Node {
        int val = 0;
        int priority = rand();
        int size = 1;
        int sum = val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int val);
        static int get_size(Node* node);
        static int get_sum(Node* node);
        void update();
    };

    Treap();
    ~Treap();
    Treap(const Treap& other);
    Treap(Treap&& other);
    Treap& operator=(const Treap& other);
    Treap& operator=(Treap&& other);

    void insert(int val, int pos);
    void erase(Node* t, int pos);
    int summa(int _from, int _to);
    static void print_bst(Node* root);
    static void print_numbers(Node* root);
    Node* get_head();

private:
    Node* head;

    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    static Node* merge(Node* t1, Node* t2);
    void copyTreap(Node* node, int count);
    static void clearTreap(Node* node);
};
