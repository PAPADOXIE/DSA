#include "DNode.cpp"
#include <cstdint>
#include <iostream>
#include <iterator>

using namespace std;

#define DUMMY 0

class DHCLList
{
    DNode *head;

  public:
    DHCLList()
    {
        head = new DNode(DUMMY);
        head->next = head->prev = head;
    }
    void addNodeAtHead(int d)
    {
        DNode *newNode = new DNode(d, head, head->next);
        head->next->prev = newNode;
        head->next = newNode;
    }
    void addNodeAtTail(int d)
    {
        DNode *newNode = new DNode(d, head->prev, head);
        head->prev->next = newNode;
        head->prev = newNode;
    }
    void print(DNode *t)
    {
        if (t == head)
            return;
        cout << t->data << ' ';
        print(t->next);
    }
    void print()
    {
        print(head->next);
        cout << '\n';
    }
    void printR(DNode *t)
    {
        if (t == head)
            return;
        cout << t->data << ' ';
        printR(t->prev);
    }
    void printR()
    {
        printR(head->prev);
        cout << '\n';
    }
    void addInOrder(int d, DNode *t)
    {
        if (t == head || t->data > d)
        {
            DNode *newNode = new DNode(d, t->prev, t);
            t->prev->next = newNode;
            t->prev = newNode;
            return;
        }
        addInOrder(d, t->next);
    }
    void addNodeInOrder(int d)
    {
        if (head->next == head)
        {
            addNodeAtHead(d);
            return;
        }
        addInOrder(d, head->next);
    }
    /*void addNodeAfter(int d1, int d2){
        Node *t;
        for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
        if (t != NULL){
            Node *newNode = new Node(d2);
            newNode -> next = t -> next;
            t -> next = newNode;
            if (t == last)	last = newNode;
        }
    }
    void deleteNodeFromStart(){
        if (first->next!=NULL){
            Node *t = first -> next;
            first -> next = t -> next; //t->next may be second node or NULL
            delete t;
            if (first -> next == NULL)		last = NULL;
        }
    }
    void deleteNodeFromEnd(){
        if (last!=NULL){
            if (first -> next == last)		deleteNodeFromStart();
            else{
                Node *t = first;
                for ( ; t->next != last; t = t -> next );//Move to second last node
                delete t->next;
                t->next = NULL;
                last = t;
            }
        }
    }
    void show(){
        if ( first -> next == NULL)
            cout << "List is empty\n";
        for ( Node *t = first -> next ; t != NULL ; t = t -> next )
            cout << t -> data << ' ';
        cout << '\n' ;
    }*/
    void swapNodes(int d1, int d2)
    {
        DNode *n1 = new DNode(0);
        DNode *n2 = new DNode(0);
        int found = 0;
        for (auto i = head->next; i->next != head; i = i->next)
        {
            if (i->data == d1)
            {
                found++;
                n1->prev = i->prev;
                n1->next = i->next;
                n1->data = i->data;
            }
            if (i->data == d2)
            {
                found++;
                n2->prev = i->prev;
                n2->next = i->next;
                n2->data = i->data;
            }
        }

        if (found == 2)
        {
            DNode *temp1 = n1->prev->next;
            DNode *temp2 = n2->prev->next;

            temp1->prev->next = n2;
            temp1->next->prev = n2;
            n2->prev = temp1->prev;
            n2->next = temp1->next;

            temp2->prev->next = n1;
            temp2->next->prev = n1;
            n1->prev = temp2->prev;
            n1->next = temp2->next;

            delete temp1;
            delete temp2;
        }
    }

    DNode *reverse(DNode *node)
    {
		if(node == head){
			return head;
		}
	
        DNode *temp = node->prev;
        node->prev = node->next;
        node->next = temp;

        return reverse(node->prev);
    }

    void reverse()
    {
        DNode *node = reverse(head->next);
        if (node != NULL)
        {
			DNode *temp = node->next;
			head->next = node->prev;
			head->prev = temp;
            return;
        }
    }
};

int main()
{
    DHCLList list;
    /*list.addNodeAtHead(23);
    list.addNodeAtHead(31);
    list.addNodeAtTail(45);
    list.addNodeAtTail(13);
    list.print();
    list.addNodeAtHead(11);
    list.addNodeAtTail(63);
    list.print();*/
    /*	list.deleteNodeFromEnd();
        list.print();
        list.deleteNodeFromStart();
        list.print();
        list.deleteNodeFromEnd();
        list.print();
        list.deleteNodeFromEnd();
        list.print();
        list.deleteNodeFromEnd();
        list.print();
        list.deleteNodeFromEnd();
        list.print();
        list.deleteNodeFromEnd();
        list.print();*/
    // list.addNodeAtHead(21);
    // list.addNodeAtTail(36);
    list.addNodeInOrder(23);
    list.addNodeInOrder(13);
    list.addNodeInOrder(53);
    list.addNodeInOrder(83);
    list.addNodeInOrder(73);
    list.addNodeInOrder(43);
    list.addNodeInOrder(93);
    list.print();
    list.printR();
    list.swapNodes(13, 23);
    list.print();
    list.reverse();
    list.print();
    return 0;
}
