#include "Node.cpp"
#include <iostream>
#include <map>
#include <system_error>

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

    bool printKthPositiveNode(int k, int run, Node *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data >= 0)
        {
            run++;
        }

        if (k == run)
        {
            std::cout << node->data << '\n';
            return true;
        }

        return printKthPositiveNode(k, run, node->next);
    }

    bool printKthPositiveNode(int k)
    {
        return printKthPositiveNode(k, 0, first->next);
    }

    bool isSumEqual(Node *node, int n, int sum)
    {
        if (node == NULL)
        {
            return false;
        }

        sum = sum + node->data;

        if (n == sum)
        {
            return true;
        }

        if (isSumEqual(node->next, n, sum))
        {
            return true;
        }

        for (int i = 0; i < 100; i++)
        {
            if (node->next != NULL)
            {
                node = node->next;
                if (isSumEqual(node, n, sum))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isSumEqual(int n)
    {
        Node *node = first;
        for (int i = 0; i < 100; i++)
        {
            if(node->next != NULL){
                node = node->next;
                if(isSumEqual(node, n, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    LinkedList list;
    list.addNodeAtEnd(23);
    list.addNodeAtEnd(59);
    list.addNodeAtEnd(37);
    // list.show();
    list.addNodeAtEnd(46);
    list.addNodeAtEnd(64);
    list.addNodeAtEnd(29);
    // list.addNodeAtEnd(29);
    // list.addNodeAtEnd(30);
    list.show();
    std::cout << list.printKthPositiveNode(3) << '\n';
    std::cout << list.isSumEqual(123);
    return 0;
}
