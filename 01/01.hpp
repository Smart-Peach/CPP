#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>

class Treap {
private:
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

    Node* head;


    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    static Node* merge(Node* t1, Node* t2);
    Node* deep_copy(Node* other);
    static void clearTreap(Node* node);

public:
    Treap();
    ~Treap();
    Treap(const Treap& other);
    Treap& operator=(const Treap& other);

    void insert(int val, int pos);
    void erase(Node* t, int pos);
    int summa(int _from, int _to);
    static void print_bst(Node* root);
    static void print_numbers(Node* root);
};
