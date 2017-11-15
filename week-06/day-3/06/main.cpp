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

        void addNode(int value)
        {
            Node *temp = new Node;
            temp->value = value;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void display_list()
        {
            cout << "Printing list:" << endl;

            Node *temp = new Node;
            temp = head;

            while (temp != NULL) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        int get_size()
        {
            Node *temp = head;
            int size_counter = 0;

            while (temp != NULL) {
                size_counter++;
                temp = temp->next;
            }

            cout << "Running get_size: " << size_counter << endl;

            return size_counter;
        }

        void insert_before(int pos, int value) // first element is pos 0th
        {
            int size = get_size();

            if (size == 0) {
                addNode(value);
            } else {
                Node *temp = new Node;
                Node *new_node = new Node;
                new_node->value = value;
                new_node->next = NULL;
                temp = head;

                for (int i = 0; i < pos; ++i) {
                    temp = temp->next;
                }

                new_node->next = temp->next;
                temp->next = new_node;
            }
        }

        void remove_at_position(int pos)
        {

        }

};

int main()
{
    List l; // init list

    for (int i = 1; i <= 5; ++i) { // load list
        l.addNode(i);
    }


    l.display_list();
    l.get_size();
    l.insert_before(3, 100);
    l.display_list();



    return 0;
}
