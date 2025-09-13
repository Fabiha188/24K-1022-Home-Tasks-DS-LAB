#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sortList() {
        if (!head) return;
        for (Node* i = head; i && i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    void concatenate(LinkedList& list2) {
        if (!head) {
            head = list2.head;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = list2.head;
    }

    void findMiddle() {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    void removeDuplicates() {
        Node* current = head;
        while (current && current->next) {
            Node* temp = current;
            while (temp->next) {
                if (temp->next->data == current->data) {
                    Node* dup = temp->next;
                    temp->next = temp->next->next;
                    delete dup;
                } else {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }

    static LinkedList mergeSorted(LinkedList& list1, LinkedList& list2) {
        LinkedList result;
        Node* p1 = list1.head;
        Node* p2 = list2.head;
        while (p1 && p2) {
            if (p1->data < p2->data) {
                result.insertAtEnd(p1->data);
                p1 = p1->next;
            } else {
                result.insertAtEnd(p2->data);
                p2 = p2->next;
            }
        }
        while (p1) {
            result.insertAtEnd(p1->data);
            p1 = p1->next;
        }
        while (p2) {
            result.insertAtEnd(p2->data);
            p2 = p2->next;
        }
        return result;
    }
};

int main() {
    LinkedList list1, list2;
    list1.insertAtEnd(3);
    list1.insertAtEnd(1);
    list1.insertAtEnd(4);
    list1.insertAtEnd(2);

    list2.insertAtEnd(6);
    list2.insertAtEnd(5);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list1.sortList();
    cout << "Sorted List 1: ";
    list1.display();

    list1.findMiddle();

    list1.concatenate(list2);
    cout << "After concatenation: ";
    list1.display();

    list1.removeDuplicates();
    cout << "After removing duplicates: ";
    list1.display();

    LinkedList merged = LinkedList::mergeSorted(list1, list2);
    cout << "Merged Sorted List: ";
    merged.display();

    return 0;
}
