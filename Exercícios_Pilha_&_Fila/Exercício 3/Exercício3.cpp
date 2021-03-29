#include <iostream>
#include <stack>
using namespace std;

// initializing stacks
stack<char> fstStack;
stack<char> sndStack;

// functions
void queuePush(char v) {
    fstStack.push(v);
    cout << "\nElemento " << v << " adicionado na fila com sucesso!";
}

void queuePop() {
    int size = fstStack.size();

    for (int i = 0; i < size - 1; i++) {
        sndStack.push(fstStack.top());
        fstStack.pop();
    }

    fstStack.pop();
    cout << "\nElemento da primeira posicao removido com sucesso!";

    size = sndStack.size();
    for (int i = 0; i < size; i++) {
        fstStack.push(sndStack.top());
        sndStack.pop();
    }
}

void queueTop() {
    int size = fstStack.size();
    for (int i = 0; i < size; i++) {
        sndStack.push(fstStack.top());
        fstStack.pop();
    }

    cout << "\nElemento situado na primeira posicao da fila: " << sndStack.top();

    size = sndStack.size();
    for (int i = 0; i < size; i++) {
        fstStack.push(sndStack.top());
        sndStack.pop();
    }
}

// main program
int main() {
    int option = 0;

    while (option != 4) {
        cout << "\n------------------------------\nSelecione uma opcao\n------------------------------\n1- INSERIR DADO NA FILA\n2- REMOVER DADO DA FILA\n3- MOSTRAR FRENTE DA FILA\n4- SAIR\n------------------------------\n";
        cout << "Total de itens na fila: " << fstStack.size() << "\nDigite sua opcao: "; 
        cin >> option;
        
        switch (option) {
            case 1:
                char data;
                cout << "\nDigite o dado que deseja inserir na fila: ";
                cin >> data;
                queuePush(data);
                break;

            case 2:
                queuePop();
                break;

            case 3:
                queueTop();
                break;
            
            case 4:
                cout << "\nFim do programa :)\n";
                break;
            
            default:
                cout << "\nDigite uma opcao valida!\n";
                break;
        }
    }

    return 0;
}