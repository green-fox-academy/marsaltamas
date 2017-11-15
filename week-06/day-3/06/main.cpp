// Create a linked list using classes.
// If you are not similar whit linked lists look it up on the internet.
// Feel free to walk through some tutorials, get familiar with your implementation.
#include <iostream>
using namespace std;

class List {

    typedef struct Node {
        int value;
        Node *next;
    } Node;

    public:
        Node *head;
        Node *tail;

        List()
        {
            head = NULL;
            tail = NULL;
        }

        void addNote(int value)
        {
            Node *temp = new Node;
            temp->value = value;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
                //delete temp;
            } else {
                tail->next = temp;
                tail = tail->next;
                //delete temp;
            }
        }

        void display_list()
        {
            Node *temp = new Node;
            temp = head;

            while (temp != NULL) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

};

int main()
{
    List l;

    for (int i = 0; i < 5; ++i) {
        l.addNote(i);
    }

    cout << l.head->value << endl;
    cout << l.tail->value << endl;

    l.display_list();

    return 0;
}
