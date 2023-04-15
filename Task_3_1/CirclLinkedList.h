#include <iostream>
using namespace std;
template <typename T>
class CirclLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    CirclLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(T val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = newNode;
            tail = head;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
    }

    void push_front(T val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = newNode;
            tail = head;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void pop_front() {
        if (size == 0) {
            std::cout << "Error: list is empty." << std::endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        size--;
    }

    void pop_back() {
        if (size == 0) {
            std::cout << "Error: list is empty." << std::endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
        size--;
    }

    void display() {
        if (size == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};