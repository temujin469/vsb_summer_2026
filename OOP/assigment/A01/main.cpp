#include <iostream>
#include "node.h"
using namespace std;

Node::Node(int value)
{
    this->value = value;
    this->nr = nullptr;
    this->nl = nullptr;

}

Node *Node::createNext(int value)
{
    if (value > this->value)
    {
        if (this->nr == nullptr)
        {
            return this->nr = new Node(value);
        }
        else
        {
            // zavola se rekurzivne dal
            return this->nr->createNext(value);
        }
    }
    // vetsi nebo rovno
    else
    {
        if (this->nl == nullptr)
        {
            return this->nl = new Node(value);
        }
        else
        {
            return this->nl->createNext(value);
        }
    }
}

void Node::printStromu()
{
    //Rekurze funguje jako zasobnik
    // nejdriv levy podstrom
    if (nl != nullptr)
    {
        nl->printStromu();
    }

    // aktualni uzel
    cout << value << " ";

    // nakonec pravy podstrom
    if (nr != nullptr)
    {
        nr->printStromu();
    }
}

class Strom
{
public:
    Strom(int value)
    {
    }
};

int main()
{
    Node *node = new Node(5); // pocáteční prvek
    node->createNext(-6);
    node->createNext(7);
    node->createNext(-45);
    node->createNext(8);
    node->createNext(6);
    node->createNext(33);

    node->printStromu();

    return 1;
}