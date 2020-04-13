class Node
{
public:
    int Element;
    Node* Next;

    Node() : Next(nullptr) {}
    Node(int data, Node* pnode = nullptr) :
        Element(data), Next(pnode) {}
};
