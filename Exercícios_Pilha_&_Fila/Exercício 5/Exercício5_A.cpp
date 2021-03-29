#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<char> mainQueue;
stack<char> invertingStack;

int main() {
    mainQueue.push('A');
    mainQueue.push('B');
    mainQueue.push('C');
    mainQueue.push('D');
    mainQueue.push('E');

    cout << "\n-----------------------------------------\n";
    cout << " Inversao de fila utilizando uma pilha  ";
    cout << "\n-----------------------------------------\n";

    cout << "\nFila original: A B C D E\n";

    // inverting algorithm
    int N = mainQueue.size();

    return 0;
}