#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter an integer: "<<endl;
        cin >> vec[i];
    }

    int firstValue, secondValue;
    cout << "Enter the first value: ";
    cin >> firstValue;
    cout << "Enter the second value: ";
    cin >> secondValue;

    insertAfter(vec, firstValue, secondValue);

    cout << "Modified vector: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    LinkedList list = createLinkedList(vec);

    cout << "Linked list: "<<endl;
    list.printList();

    cout << "Sum of all nodes: " << list.sumList();
}