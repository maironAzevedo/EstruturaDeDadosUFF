#include <iostream>
#include <new>

using namespace std;

class NoStack1 {
    public:
        int data;
        NoStack1* next;
        NoStack1* previous;
};

class Stack1 {
    public:
        NoStack1* start;
        NoStack1* end;
        NoStack1* value;

        int N;
        
        void create() {
            this -> N = 0;
            this -> start = 0;
            this -> end = 0;
        };

        void release() {
            while (this -> N > 0) {
                NoStack1* p = this -> start -> next;
                delete this -> start;
                this -> start = p;
                this -> N--;
            }
        };

        int top() {
            if (this -> N == 0) {
                cout << "Nao existem itens na pilha!";
            } else {
                int r = this -> start -> data;
                cout << r;
            }
        };

        void push (int v) {
            auto no = new NoStack1{.data = v, .next = this -> start};

            if (start == 0 && end == 0) {
                this -> start = no;
                this -> end = no;
            } else {
                this -> value = this -> start;
                no -> next = this -> value;
                this -> value -> previous = no;
                this -> start = no; 
            }

            cout << v << " ";

            this -> N++;
        };

        int pop() {
            if (this -> N == 0) {
                cout << "Nao existem itens a serem removidos!";
            } else {
                NoStack1* p = this -> start -> next;
                int r = this -> start -> data;
                delete this -> start;
                this -> start = p;
                this -> N--;
                return r;
            }
        };

        int minorValue() {
            if (this -> N == 0) {
                cout << "Nao existem itens na pilha!";
            } else {
                int minor = this -> start -> data;
                int J = this -> N;

                for(int i = 0; i < J - 1; i++) {
                    if (this -> start -> data < minor) {
                        minor = this -> start -> data;
                    }
                    this -> start = this -> start -> next;
                }
                
                return minor;
            }
        }
};

int main () {
    Stack1 stack;
    int option = 0;
    
    cout << "Pilha original: ";
    stack.create();
    stack.push(10);
    stack.push(30);
    stack.push(50);
    stack.push(2);
    stack.push(7);

    cout << "\nMenor valor encontrado: ";
    cout << stack.minorValue();


    return 0;
}
