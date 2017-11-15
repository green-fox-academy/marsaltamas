// Create a linked list using classes.
// If you are not similar whit linked lists look it up on the internet.
// Feel free to walk through some tutorials, get familiar with your implementation.
#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node;

class List {

    public:
        Node *head;
        Node *tail;
        List()
        {
            head = NULL;
            tail = NULL;
        }
        void push_back_node(int data)
        {
            Node *new_node = new Node;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
                new_node->data = data;
                tail = new_node;
            } else {
                tail = new_node;
                new_node->data = data;
            }
        }
};

int main()
{
    List list;

    for (int i = 0; i < 5; ++i) {
        list.push_back_node(i);
    }

    cout << "Head data: " << list.head->data << endl;
    cout << "Tail data: " << list.tail->data << endl;

    return 0;
}
