#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<char> mainQueue;
queue<char> invertingQueue;
queue<char> secondaryQueue;

int main() {
    mainQueue.push('A');
    mainQueue.push('B');
    mainQueue.push('C');
    mainQueue.push('D');
    mainQueue.push('E');

    cout << "\n-----------------------------------------\n";
    cout << " Inversao de fila utilizando duas filas  ";
    cout << "\n-----------------------------------------\n";

    cout << "\nFila original: A B C D E\n";

    // inverting algorithm
    int N = mainQueue.size();

    while(secondaryQueue.size() != N) {
        int J = mainQueue.size();
        
        for (int i = 0; i < J - 1; i++) {
            invertingQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        secondaryQueue.push(mainQueue.front());
        mainQueue.pop();

        J = invertingQueue.size();
        mainQueue = invertingQueue;

        for(int i = 0; i < J; i++) {
            invertingQueue.pop();
        }
    }

    mainQueue.pop();

    int J = secondaryQueue.size();
    
    cout << "Fila invertida: ";
    for(int i = 0; i < J; i++) {
        mainQueue.push(secondaryQueue.front());
        secondaryQueue.pop();
        cout << mainQueue.back() << " ";
    }
    
    return 0;
}