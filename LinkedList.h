#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    int count;
    Node* next;
    
    Node(int v, int c) : value(v), count(c), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int value, int count) {
        Node* newNode = new Node(value, count);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void removeNode(int value) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->value != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value not found in list" << endl;
        } else if (prev == nullptr) {
            head = curr->next;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    void printList() {
        Node* curr = head;

        while (curr != nullptr) {
            cout << "The value "<< curr->value << " is repeated " << curr->count << " times" << endl;
            curr = curr->next;
        }

        cout << endl;
    }

    int sumList() {
        int sum = 0;
        Node* curr = head;

        while (curr != nullptr) {
            sum += curr->value * curr->count;
            curr = curr->next;
        }

        return sum;
    }
};

void insertAfter(vector<int>& vec, int firstValue, int secondValue) {
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        if (vec[i] == firstValue) {
            vec.insert(vec.begin() + i + 1, secondValue);
            i++;
            n++;
        }
    }
}

LinkedList createLinkedList(vector<int>& vec) {
    int n = vec.size();
    LinkedList list;

    for (int i = 0; i < n; i++) {
        int count = 1;
        int value = vec[i];
        
        for (int j = i + 1; j < n; j++) {
            if (vec[j] == value) {
                count++;
                vec.erase(vec.begin() + j);
                n--;
                j--;
            }
        }

        list.addNode(value, count);
    }

    return list;
}
#endif //LINKEDLIST_H