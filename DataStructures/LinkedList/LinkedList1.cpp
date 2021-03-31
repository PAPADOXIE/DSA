#include "Node.cpp"
#include <iostream>
#include <map>

using namespace std;

class LinkedList
{
    Node *first, *last;

  public:
    LinkedList()
    {
        first = new Node(0);
        last = NULL;
    }
    void addNodeAtStart(int d)
    {
        Node *newN = new Node(d);
        newN->next = first->next;
        first->next = newN;
        if (last == NULL)
            last = newN;

        first->count++;
    }
    void addNodeAtEnd(int d)
    {
        if (last == NULL)
            addNodeAtStart(d);
        else
        {
            last->next = new Node(d);
            last = last->next;
        }
        first->count++;
    }

    void deleteNodeFromStart()
    {
        if (first->next != NULL)
        {
            Node *t = first->next;
            first->next = t->next; // t->next may be second node or NULL
            delete t;
            if (first->next == NULL)
                last = NULL;
            first->count--;
        }
    }

    void deleteNodeFromEnd()
    {
        if (last != NULL)
        {
            if (first->next == last)
                deleteNodeFromStart();
            else
            {
                Node *t = first;
                for (; t->next != last; t = t->next)
                    ; // Move to second last node
                delete t->next;
                t->next = NULL;
                last = t;
            }
        }
        first->count--;
    }

    void splitNode()
    {
        for (Node *i = first->next; i != NULL; i = i->next)
        {
            if (i->data > 50)
            {
                int data = i->data;
                data = data / 2;
                Node *temp = new Node(data, i->next);
                i->next = temp;
                if (i->data % 2 != 0)
                {
                    i->data = data + 1;
                    continue;
                }
                i->data = data;
            }
        }
    }

    void palindrome()
    {
        if (first->count % 2 != 0)
        {
            std::cout << "Not a Palindrome\n";
            return;
        }

        int *arr = new int[first->count];
        int count = 0;

        for (Node *i = first->next; i != NULL; i = i->next, count++)
        {
            arr[count] = i->data;
        }

        for (int i = 0, j = count; i <= count / 2; i++, j--)
        {
            std::cout << arr[i] << " " << arr[j] << "\n";
            if (arr[i] != arr[j])
            {
                std::cout << "Not a Palindrome\n";
                return;
            }
        }
        std::cout << "Palindrome\n";
    }

    void pair()
    {
        for (Node *i = first->next; i->next != nullptr;)
        {
            std::cout << i->data << " ";
            i = i->next;
            std::cout << i->data << "\n";
        }
    }

	void deleteNegative(){

	}

	void addArray(){
		
	}

    void swap(Node *t1, Node *t2)
    {
        int temp = t1->data;
        t1->data = t2->data;
        t2->data = temp;
    }
    void bubbleSort()
    {
        Node *t1, *t2;
        for (t1 = first->next; t1->next != NULL; t1 = t1->next)
            for (t2 = first->next; t2->next != NULL; t2 = t2->next)
                if (t2->data > t2->next->data)
                    swap(t2, t2->next);
    }

    void selectionSort()
    {
        Node *t1, *t2, *minNode;
        for (t1 = first->next; t1->next != NULL; t1 = t1->next)
        {
            minNode = t1;
            for (t2 = t1->next; t2 != NULL; t2 = t2->next)
                if (t2->data < minNode->data)
                    minNode = t2;
            if (minNode != t1)
                swap(t1, minNode);
        }
    }
    void show()
    {
        for (Node *t = first->next; t != NULL; t = t->next)
            cout << t->data << ' ';
        cout << '\n';
    }
};

int main()
{
    LinkedList list;
    list.addNodeAtEnd(1);
    list.addNodeAtEnd(2);
    list.addNodeAtEnd(2);
    list.show();
    list.addNodeAtEnd(1);
    list.show();
    // list.bubbleSort();
    // list.selectionSort();
    // list.show();
    list.splitNode();
    list.show();
    list.palindrome();
	list.pair();
    return 0;
}
