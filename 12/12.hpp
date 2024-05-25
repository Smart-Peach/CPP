#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>
#include <vector>


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
        Node* parent = nullptr;

        Node(T val) : val(val) {};
        static int get_size(Node* node);
        static T get_sum(Node* node);
        void update();
    };

    // class Iterator {
    //     private:
    //         Node* curr_node;
    //         std::vector<Node*> stack;
        
    //     public:
    //         Iterator(Node* node) : curr_node(node) {
    //             fill_stack(node);
    //         }

    //         bool operator!=(Iterator const &other) {
    //             return this->curr_node != other.curr_node;
    //         }

    //         T operator*() const {
    //             return curr_node->val;
    //         }

    //         Iterator& operator++() {
    //             curr_node = curr_node->successor(); // point to next node
    //             return *this;
    //         }
    // };

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

    // Iterator begin() const {
    //     return Iterator(head);
    // }

    // Iterator end() const {
    //     return Iterator(nullptr);
    // }

private:
    Node* head;

    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    Node* merge(Node*& t1, Node*& t2);
    void copyTreap(Node* node, int count);
    static void clearTreap(Node* node);
};
