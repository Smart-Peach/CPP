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
        Node* curr_;
    public:
        Iterator(Node* ptr): curr_(ptr) { }
        Iterator(const Iterator& other);
        Iterator& operator=(const Iterator& other);
        ~Iterator() { }

        // Iterator's operators
        Node& operator*();
        Node* operator->();
        Iterator& operator++();
        Iterator operator++(int);
        friend bool operator==(const Iterator& first, const Iterator& second) {
            return first.curr_ == second.curr_;
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

    // Iterator begin() const {
    //     return Iterator(head);
    // }

    // Iterator end() const {
    //     return Iterator(nullptr);
    // }

private:
    Node* head;

    static void split_by_size(Node* t, int size, Node*& left, Node*& right);
    // Node* merge(Node*& t1, Node*& t2);
    void merge(Node*& t1, Node*& t2, Node*& parent);
    void copyTreap(Node* node, int count);
    static void clearTreap(Node* node);
};
