#pragma once
#include "VoidQueue.h"

template <typename T>
class TmpQueue : private VoidQueue {
public:
    void enqueue(T* item) {
        VoidQueue::enqueue(static_cast<void*>(item));
    }

    T* dequeue() {
        return static_cast<T*>(VoidQueue::dequeue());
    }

    bool isEmpty() const {
        return VoidQueue::isEmpty();
    }

    ~TmpQueue() {
        while (!isEmpty()) {
            delete dequeue();
        }
    }
};