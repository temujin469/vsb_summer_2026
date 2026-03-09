#include <iostream>
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

int main()
{
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