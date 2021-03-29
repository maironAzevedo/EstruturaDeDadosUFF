#include <iostream>
#include <queue>

using namespace std;

// creating both of the queues
queue<char> fstQueue;
queue<char> sndQueue; 

// functions
void stackPush(char v) {
    fstQueue.push(v);
    cout << "\nElemento " << v << " adicionado na pilha com sucesso!";
};

void stackTop() {
    if (fstQueue.size() > 0) {
        cout << "\nElemento situado no topo da pilha: "<< fstQueue.back();

    } else {
        cout << "\nNao existem itens na pilha!\n";
    }
};

void stackPop() {
    if (fstQueue.size() > 1) {
        for (int i = 0; i < fstQueue.size() - 1; i++) {
            sndQueue.push(fstQueue.front());
            fstQueue.pop();
        }

        fstQueue.pop();

        for (int i = 0; i < sndQueue.size(); i++) {
            fstQueue.push(sndQueue.front());
            sndQueue.pop();
        }

    } else {
        cout << "\nNao ha nada para retirar!\n";
    }

};

// main program
int main() {
    int option = 0;

    while (option != 4) {
        cout << "\n------------------------------\nSelecione uma opcao\n------------------------------\n1- INSERIR DADO NA PILHA\n2- REMOVER DADO DA PILHA\n3- MOSTRAR TOPO DA PILHA\n4- SAIR\n------------------------------\n";
        cout << "Total de itens na pilha: " << fstQueue.size() << "\nDigite sua opcao: "; 
        cin >> option;
        

        switch (option) {
            case 1:
                char data;
                cout << "\nDigite o dado que deseja inserir na pilha: ";
                cin >> data;
                stackPush(data);
                break;

            case 2:
                stackPop();
                break;

            case 3:
                stackTop();
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