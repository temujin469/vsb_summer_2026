#include <iostream>
#include <stack>
using namespace std;

// #define Capacita 100
const int Capacita = 100;

template <typename T>
class Stack
{
private:
    T data[Capacita];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Přidání prvku do zásobníku
    void push(T x)
    {
        if (top + 1 >= Capacita)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = x;
    }

    // Odebrání prvku ze zásobníku
    T pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        // top--;
        return this->data[top--];
    }

    // Vrátí horní prvek
    T peek()
    {
        if (top < 0)
        {
            cout << "Zasobnik je prazdny" << endl;
            return -1;
        }
        return data[top];
    }

    // Kontrola, zda je zásobník prázdný
    bool isEmpty()
    {
        return (top < 0);
    }
};

bool checkParity(string str)
{
    Stack<char> stack;
    // Stack<int> * stack = new Stack<int>();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            stack.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}

int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    // 12, 60%12=0
    return gcd(n, m % n);
}

void bubbleSort(int *pole, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (pole[j] > pole[j + 1])
            {
                int temp = pole[j];
                pole[j] = pole[j + 1];
                pole[j + 1] = temp;
            }
        }
    }
}

// The Tower of Hanoi is a puzzle with:

// 3 rods (A, B, C)

// N disks of different sizes

// Rules:

// Only one disk can be moved at a time

// You can only move the top disk of a stack

// A bigger disk can never be placed on a smaller disk

// Goal:

// Move all disks from rod A → rod C using rod B as auxiliary.
class TowersOfHanoi
{
    int N;
    stack<int> A;
    stack<int> B;
    stack<int> C;

    TowersOfHanoi(int N)
    {
        this->N = N;

        for (int i = N; i > 0; i--)
        {
            // A: [3,2,1]
            // B: []
            // C: []
            A.push(i);
        }
    }

    bool isMoveValid(stack<int> from, stack<int> to)
    {   
        // destination stack is empty, OR
        if (to.empty())
            return true;
        if (from.empty())
            return false;

            // the top disk on from is smaller than the top disk on to
        return from.top() < to.top();
    }

    void moveDisk(stack<int>& from, stack<int>& to)
    {
        if (isMoveValid(from, to))
        {
            to.push(from.top());
            from.pop();
        }
        else
        {
            from.push(to.top());
            to.pop();
        }
    }


    // Move N disks from A → C using B
    void solve()
    {
        solve(A, B, C, N);
    }

    void print() {};

    void solve(stack<int> from, stack<int> aux, stack<int> to, int N)
    {
        if (N == 1)
        {
            moveDisk(from, to);
            print();
            return;
        }
        solve(from, to, aux, N - 1);
        moveDisk(from, to);
        print();
        solve(aux, from, to, N - 1);
    }
};

int main()
{

    TowersOfHanoi towers(5);
    cout << "----------------------------" << endl;

    cout << gcd(60, 12) << endl;

    cout << "----------------------------" << endl;

    Stack<int> stack;

    // stack.push(5);
    // stack.push(10);
    // stack.push(15);

    // // vrchol
    // cout << "Horni prvek: " << stack.peek() << endl;

    // stack.pop();
    // cout << "Horni prvek po pop: " << stack.peek() << endl;
    // delete stack;

    // for chars
    if (checkParity("(((())))"))
        cout << "Zavorky jsou vyvazene" << endl;
    else
        cout << "Zavorky nejsou vyvazene" << endl;

    return 0;
}