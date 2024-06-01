#pragma once
#include <queue>
#include <iostream>

class VoidQueue {
protected:
    std::queue<void*> container;
public:
    void enqueue(void* item) {
        container.push(item);
    }

    void* dequeue() {
        if (container.empty()) {
            return nullptr;
        }
        void* item = container.front();
        container.pop();
        return item;
    }

    bool isEmpty() const {
        return container.empty();
    }

    ~VoidQueue() {
        while (!container.empty()) {
            container.pop();
        }
    }
};