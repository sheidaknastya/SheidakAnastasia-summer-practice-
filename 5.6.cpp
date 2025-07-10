#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Очередь пуста! Нечего удалять.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Удален элемент: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Очередь пуста.\n";
            return;
        }

        cout << "Элементы очереди: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    srand(time(0));
    Queue q;

    int n;
    cout << "Введите количество элементов для очереди: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int value = rand() % 100; 
        cout << "Добавлен элемент: " << value << endl;
        q.enqueue(value);
    }

    q.display();

    cout << "\nУдалим два элемента:\n";
    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
