#ifndef SET_H
#define SET_H

class Set{
    private:
        int length;
        int count;
        int* items;
    public:
    // Set(int vals[]);
        Set(int len);
        ~Set();
        int getCount();
        int getAt(int i);
        void insert(int item);
        Set * sjednotit(Set * secondSet);
        Set * complement(Set * secondSet);
};

#endif