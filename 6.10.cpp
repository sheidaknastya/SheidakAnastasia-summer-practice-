#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack_in;
    stack<int> stack_out;

    void transfer() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    void enqueue(int x) {
        stack_in.push(x);
    }

    void dequeue() {
        if (stack_out.empty()) {
            if (stack_in.empty()) {
                cout << "Очередь пуста!\n";
                return;
            }
            transfer();
        }
        cout << "Удален: " << stack_out.top() << endl;
        stack_out.pop();
    }

    int front() {
        if (stack_out.empty()) {
            if (stack_in.empty()) {
                throw runtime_error("Очередь пуста");
            }
            transfer();
        }
        return stack_out.top();
    }

    bool isEmpty() {
        return stack_in.empty() && stack_out.empty();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Передний элемент: " << q.front() << endl;

    q.dequeue(); 
    cout << "Передний элемент: " << q.front() << endl;

    q.dequeue(); 
    q.dequeue(); 

    q.dequeue(); 

    return 0;
}
