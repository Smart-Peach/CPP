#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>


template <typename T>
class Treap {
public:
    struct Node {
        T val = 0;
        int priority = rand();
        int size = 1;
        T sum = val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(T val) : val(val) {};
        // ~Node();
        static int get_size(Node* node);
        static T get_sum(Node* node);
        void update();
    };

    Treap();
    ~Treap();
    Treap(const Treap& other);
    Treap(Treap&& other);
    Treap& operator=(const Treap& other);
    Treap& operator=(Treap&& other);

    void insert(T val, int pos);
    void erase(Node* t, int pos);
    T summa(int _from, int _to);
    static void print_bst(Node* root);
    static std::string print_numbers(Node* root, std::string line);
    Node* get_head();

private:
    Node* head;

    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    static Node* merge(Node* t1, Node* t2);
    void copyTreap(Node* node, int count);
    static void clearTreap(Node* node);
};
