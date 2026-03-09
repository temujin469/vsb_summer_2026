#pragma once

class Node
{
public:
    int value;
    // Node *next;
    Node *nl;
    Node *nr;
    Node(int value);
    Node *createNext(int value);
    void printStromu();
};