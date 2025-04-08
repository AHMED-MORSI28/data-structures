#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode *next;
};

SNode* CreateSNode(int n) {
    SNode* newNode = new SNode;
    newNode->data = n;
    newNode->next = nullptr;
    return newNode;
}

void InsertSortedSingly(SNode* &head, int n) {
    SNode* newNode = CreateSNode(n);
    if (head == nullptr || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    SNode* current = head;
    while (current->next != nullptr && current->next->data < newNode->data)
        current = current->next;
    newNode->next = current->next;
    current->next = newNode;
}

struct DNode {
    int data;
    DNode *next;
    DNode *prev;
};

DNode* CreateDNode(int n) {
    DNode* newNode = new DNode;
    newNode->data = n;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void InsertSortedDoubly(DNode* &head, DNode* &tail, int x, int &counter) {
    DNode* newNode = CreateDNode(x);
    if (head == nullptr || x < head->data) {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
        counter++;
        return;
    }
    DNode* current = head;
    while (current->next != nullptr && current->next->data < x)
        current = current->next;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
        current->next->prev = newNode;
    else
        tail = newNode;
    current->next = newNode;
    counter++;
}

void MakeNullDoubly(DNode* &head, DNode* &tail, int &counter) {
    DNode* current = head;
    while (current != nullptr) {
        DNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    counter = 0;
}
