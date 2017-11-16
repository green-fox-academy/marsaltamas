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

        void addNode_at_back(int value)
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

            Node *temp = new Node;
            Node *new_node = new Node;

            temp = head;

            if (size == 0) {
                addNode_at_back(value);
            } else if (pos > size - 1 || pos < 0) {
                cout << "This is an invalid position.\n";
            }else if (pos == 0){
                new_node->value = value;
                new_node->next = head;
                head = new_node;
            } else {
                new_node->value = value;
                new_node->next = NULL;

                for (int i = 0; i < pos - 1; ++i) {
                    temp = temp->next;
                }

                new_node->next = temp->next;
                temp->next = new_node;
            }
        }

        void remove_at_position(int pos) // first element is pos 0th
        {
            int size = get_size();

            if (size == 0) {
                cout << "The list is already empty.\n";
            } else if (pos < 0 || pos > size -1) {
                cout << "Invalid position.\n";
            } else if (pos == 0) {
                head = head->next;
            } else {
                Node *to_del = new Node;
                Node *temp = new Node;
                to_del = head;

                for (int i = 0; i < pos; ++i) {
                    if (i == pos -1) {
                        temp = to_del;
                    }
                    to_del = to_del->next;
                }
                temp->next = to_del->next;
            }
        }

};

int main()
{
    List l; // init list

    for (int i = 1; i <= 5; ++i) { // load list
        l.addNode_at_back(i);
    }

    l.display_list();
    l.remove_at_position(4);
    l.display_list();



    return 0;
}
