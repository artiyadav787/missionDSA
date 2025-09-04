#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, count, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
