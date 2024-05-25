#include <iostream>
#include <stdexcept>
#include <random>
#include <cmath>
#include <vector>


template <typename T>
class Treap {
public:
    struct Node {
        T val = T();
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

    class Iterator {
        Node* curr_node;
    public:
        Iterator(Node* ptr): curr_node(ptr) { }
        Iterator(const Iterator& other) { curr_node = other.curr_node; }
        Iterator& operator=(const Iterator& other) {
            curr_node = other.curr_node;
            return *this;
        };
        ~Iterator() { }

        Node& operator*() { return *curr_node; }
        Node* operator->() { return curr_node; };
        Iterator& operator++();
        Iterator operator++(int) {
            Iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator& first, const Iterator& second) {
            return first.curr_node == second.curr_node;
        };
        friend bool operator!=(const Iterator& first, const Iterator& second) {
            return !(first == second);
        }
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

    Iterator begin() const { return Iterator(get_leftest(head)); }
    Iterator end() const { return Iterator(nullptr); }

private:
    Node* head;

    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    void merge(Node*& t1, Node*& t2, Node*& parent);
    void copyTreap(Node* node, int count);
    static void clearTreap(Node* node);

    static Node* get_leftest(Node* root);
};
