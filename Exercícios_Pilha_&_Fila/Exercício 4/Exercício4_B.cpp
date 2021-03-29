#include <iostream>
#include <stack>
using namespace std;

stack<char> mainStack;
stack<char> invertingStack;
stack<char> secondaryStack;


int main() {
    mainStack.push('A');
    mainStack.push('B');
    mainStack.push('C');
    mainStack.push('D');
    mainStack.push('E');

    cout << "\n-----------------------------------------\n";
    cout << " Inversao de pilha utilizando duas pilhas   ";
    cout << "\n-----------------------------------------\n";

    cout << "\nPilha original: A B C D E\n";

    // inverting algorithm
    int N = mainStack.size();

    for (int i = 0; i < N; i++) {
        invertingStack.push(mainStack.top());
        mainStack.pop();
    }

    N = invertingStack.size();
    for (int i = 0; i < N; i++) {
        secondaryStack.push(invertingStack.top());
        invertingStack.pop();
    }

    cout << "Pilha invertida: ";

    N = secondaryStack.size();
    for (int i = 0; i < N; i++) {
        mainStack.push(secondaryStack.top());
        secondaryStack.pop();
        cout << mainStack.top() << " ";
    }


    return 0;
}