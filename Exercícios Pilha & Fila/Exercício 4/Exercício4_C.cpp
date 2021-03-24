#include <iostream>
#include <stack>
using namespace std;

stack<char> mainStack;
stack<char> invertingStack;


int main() {
    mainStack.push('A');
    mainStack.push('B');
    mainStack.push('C');
    mainStack.push('D');
    mainStack.push('E');

    cout << "\n-----------------------------------------\n";
    cout << " Inversao de pilha utilizando uma pilha  ";
    cout << "\n-----------------------------------------\n";

    cout << "\nPilha original: A B C D E\n";

    // inverting algorithm
    int N = mainStack.size();

    invertingStack = mainStack;
    for (int i = 0; i < N; i++) {
        mainStack.pop();
    }

    cout << "Pilha invertida: ";
    N = invertingStack.size();
    for (int i = 0; i < N; i++) {
        mainStack.push(invertingStack.top());
        invertingStack.pop();

        cout << mainStack.top() << " ";
    }

    return 0;
}
