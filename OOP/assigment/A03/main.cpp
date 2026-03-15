#include <iostream>
#include "Set.h"
using namespace std;

Set::Set(
    // int vals[] same
    // int *items,
    int len)
{
    length = len;
    count = 0;
    items = new int[len]; // every Set object has its own array

    // data just points to an array that exists somewhere else
    // int array[10];
    // items = array;
}

Set::~Set()
{
    delete[] items;
}

int Set::getCount()
{
    return this->count;
}

int Set::getAt(int i)
{
    if (i >= 0 && i < count)
        return items[i];
    return -1;
}

void Set::insert(int item)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i] == item)
        {
            return;
        }
    }

    if (count < length)
    {
        items[count] = item;
        count++;
    }
}

Set *Set::sjednotit(Set *secondSet)
{
    int sum = secondSet->count + this->count;
    // Set unionSet(sum); local object on stack, will be destroyed when func ends
    Set *unionSet = new Set(sum); // on the heap
    for (int i = 0; i < this->count; i++)
    {
        unionSet->insert(items[i]);
    }

    for (int i = 0; i < secondSet->count; i++)
    {
        unionSet->insert(secondSet->items[i]);
    }

    return unionSet;
}

Set *Set::complement(Set *secondSet)
{
    Set *complementSet = new Set(this->length);

    // O(n * m)
    for (int i = 0; i < this->count; i++)
    {
        bool found = false;
        
        for (int j = 0; j < secondSet->count; j++)
        {
            if (items[i] == secondSet->items[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            complementSet->insert(items[i]);
        }
    }

    return complementSet;
}

int main()
{

    Set s(10);
    Set s2(5);

    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(5);
    s.insert(2);


    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(5);

    // Set *result = s.sjednotit(&s2);
    Set *result = s.complement(&s2);

    // for (int i = 0; i < s.getCount(); i++)
    // {
    //     cout << s.getAt(i) << endl;
    // }

    for (int i = 0; i < result->getCount(); i++)
    {
        cout << result->getAt(i) << endl;
    }

    delete result;

    return 0;
}