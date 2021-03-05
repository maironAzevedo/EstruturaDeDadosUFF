#include <iostream>
#include <new>

class NoStack1 {
    public:
        char data;
        NoStack1* next;
};

class ChainStack1 {
    public:
        NoStack1* start;
        int N;

        void create() {
            this -> N = 0;
            this -> start = 0;
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
        };

        void push (char v) {
            auto* no = new NoStack1{.data = v, .next = this -> start};
            this -> start = no;
            this -> N++;
        };

        char pop () {
            NoStack1* p = this -> start -> next;
            char r = this -> start -> data;
            delete this -> start;
            this -> start = p;
            this -> N--;
            return r;
        };
};

int main () {



    return 0;
}