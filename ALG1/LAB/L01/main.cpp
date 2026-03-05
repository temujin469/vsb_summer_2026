#include <iostream>
using namespace std;

#define Capacita 100

class Stack {
private:
    char data[Capacita];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Přidání prvku do zásobníku
    void push(int x) {
        if (top + 1 >= Capacita) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = x;
    }

    // Odebrání prvku ze zásobníku
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        // top--;
        return this->data[top--];
    }

    // Vrátí horní prvek
    int peek() {
        if (top < 0) {
            cout << "Zasobnik je prazdny" << endl;
            return -1;
        }
        return data[top];
    }

    // Kontrola, zda je zásobník prázdný
    bool isEmpty() {
        return (top < 0);
    }
};

bool checkParity(string str){
    Stack stack;
    for(int i = 0;i< str.length();i++){
        if(str[i] == '('){
            stack.push(str[i]);
        }
        else if(str[i] == ')'){
            int top = stack.pop();
            if(to)
            stack.pop();
        }
    }
}

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    //vrchol
    cout << "Horni prvek: " << stack.peek() << endl;

    stack.pop();
    cout << "Horni prvek po pop: " << stack.peek() << endl;

    return 0;
}