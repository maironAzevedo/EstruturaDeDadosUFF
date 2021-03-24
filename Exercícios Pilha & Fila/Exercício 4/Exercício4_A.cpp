#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<char> mainStack;
queue<char> invertingQueue;

int main() {
    mainStack.push('A');
    mainStack.push('B');
    mainStack.push('C');
    mainStack.push('D');
    mainStack.push('E');

    cout << "\n-----------------------------------------\n";
    cout << " Inversao de pilha utilizando uma fila   ";
    cout << "\n-----------------------------------------\n";

    cout << "\nPilha original: A B C D E\n";

    // inverting algorithm
    int N = mainStack.size();

    for (int i = 0; i < N; i++) {
        invertingQueue.push(mainStack.top());
        mainStack.pop();
    }

    cout << "Pilha invertida: ";

    for (int i = 0; i < N; i++) {
        mainStack.push(invertingQueue.front());
        invertingQueue.pop();

        cout << mainStack.top() << " ";        
    }



    return 0;
}
