#include <iostream>
#include <new>

using namespace std;

class NoStack1 {
    public:
        char data;
        NoStack1* next;
        NoStack1* previous;
};

class Deck1 {
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

        char top() {
            if (this -> N == 0) {
                cout << "Nao existem itens no deque!";
            } else {
                char r = this -> start -> data;
                cout << r;
            }
        };

        void push (char v) {
            auto* no = new NoStack1{.data = v, .next = this -> start};

            if (start == 0 && end == 0) {
                this -> start = no;
                this -> end = no;
            } else {
                this -> value = this -> start;
                no -> next = this -> value;
                this -> value -> previous = no;
                this -> start = no; 
            }

            cout << "\nO dado " << v << " foi adicionado ao deque!\n";

            this -> N++;
        };

        char pop() {
            if (this -> N == 0) {
                cout << "Nao existem itens a serem removidos!";
            } else {
                NoStack1* p = this -> start -> next;
                char r = this -> start -> data;
                delete this -> start;
                this -> start = p;
                this -> N--;
                return r;
            }
        };
        
        char bottom() {
            char r = this -> end -> data;
            cout << r;
        }

        void popBottom() {
            if (this -> N == 0) {
                cout << "Nao existem itens a serem removidos!";
            } else {
                NoStack1* p = this -> end -> next;
                char data = this -> end -> data;

                delete this -> end;
                this -> end = p;
                N--;

                cout << "\nNumero localizado no topo do deque removido: " << data;
            }
        }

        void pushBottom(char v) {
            auto* no = new NoStack1{.data = v, .next = 0, .previous = 0};

            if (this -> start == 0 && this -> end == 0) {
                this -> start = no;
                this -> end = no;
            } else {
                NoStack1* value;
                value = this -> end;
                no -> previous = value;
                value -> next = no;
                this -> end = no;                
            }

            cout << "\nO dado " << v << " foi adicionado ao deque!\n";

            this -> N++;
        };
};

int main() {
    Deck1 deck;
    int option = 0;
    char data;

    deck.create();

    while (option != 7) {
        cout << "\n------------------------------\nSelecione uma opcao\n------------------------------\n1- INSERIR NO INICIO\n2- INSERIR NO FINAL\n3- REMOVER INICIO\n4- REMOVER FINAL\n5- MOSTRAR INICIO\n6- MOSTRAR FINAL\n7- SAIR\n------------------------------\n";
        cout << "Total de itens no deque: ";
        cout << deck.N;
        cout << "\nSelecione uma opcao: ";
        cin >> option;
    
        switch (option) {
        case 1:
            cout << "\nPor favor, digite o item que deseja inserir no inicio do deque: ";
            cin >> data;

            deck.push(data);
            break;

        case 2:
            cout << "\nPor favor, digite o item que deseja inserir no fim do deque: ";
            cin >> data;

            deck.pushBottom(data);
            break;

        case 3:
            cout << "\nNumero localizado no topo do deque removido: ";
            deck.pop();            
        
            break;

        case 4:
            deck.popBottom();
        
            break;

        case 5:
            cout << "\nElemento situado no inicio do deque: ";
            deck.top();
            cout << "\n";
            break;
        
        case 6:
            cout << "\nElemento situado no fim do deque: ";
            deck.bottom();
            cout << "\n";
            
            break;

        case 7:
            cout << "\nFim do programa! :) tmj";
            break; 

        default:
            cout << "\nAlgarismo invalido! Por favor selecione uma das opcoes\n------------------------------\n";
            break;
        }
    };

    deck.release();
    return 0;
}
