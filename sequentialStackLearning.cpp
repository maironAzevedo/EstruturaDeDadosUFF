#include <iostream>

constexpr int MAXN = 100'000;

class StackSeq1 {
    public:
        char elements [MAXN];
        int N;
        void create () {
            this -> N = 0;
        };

        void release () {
            while (N > 0) {
                pop();
            }
        };

        char top () {
            return this -> elements[N - 1];

        };

        void push ( char data ) {
            this -> elements[N] = data;
            this -> N++;
        };

        char pop () {
            this -> N--;
            return elements[N];
        };
};

int main() {
    StackSeq1 p;
    p.create();

    p.push('A');
    p.push('B');
    p.push('C');

    printf("%c\n", p.top());

    printf("%c\n", p.pop());

    p.push('D');

    while(p.N > 0) {
        printf("%c\n", p.pop());
    }    
    return 0;
}