#include <iostream>
using namespace std;
struct Stack {
    int data;
    struct Stack* link;
    Stack(int d) {
        data = d;
        link = NULL;
    }
    void push(int d) {
        Stack* temp = this;
        while (temp->link != NULL) {
            temp = temp->link;
        }

        Stack* ptemp = new Stack(d);
        temp->link = ptemp;
    }
    void pop() {
        Stack* temps = this;
        while (temps->link->link != NULL) {
            temps = temps->link;
        }
        delete temps->link;
        temps->link = NULL;
    }
    void print() {
        Stack* temp = this;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};
int main() {
    Stack s1(10);
    s1.print();  // 10

    s1.push(20);
    s1.print();  // 10 20
    s1.push(30);
    s1.print();  // 10 20
    s1.push(40);
    s1.print();  // 10 20
    s1.push(50);
    s1.print();  // 10 20

    s1.pop();
    s1.print();
    s1.pop();
    s1.print();
    s1.pop();
    s1.print();
    s1.pop();
    s1.print();

    return 0;
}
