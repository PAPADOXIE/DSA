class Node
{
  public:
    int data;
    Node *next; // TO point to next node, null otherwise
    int count;

	// Constructor
    Node(int d, Node *n = nullptr)
    {
        data = d;
        next = n;
		count = -1;
    }
};
