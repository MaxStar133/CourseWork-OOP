#pragma once
#include "VoidQueue.h"

template <typename T>
class TmpQueue : private VoidQueue {
public:
    void Enqueue(T* item) {
        VoidQueue::Enqueue(static_cast<void*>(item));
    }

    T* Dequeue() {
        return static_cast<T*>(VoidQueue::Dequeue());
    }

    bool IsEmpty() const {
        return VoidQueue::IsEmpty();
    }

    size_t Size() const {
        return VoidQueue::Size();
    }

    T* At(size_t index) const {
        return static_cast<T*>(VoidQueue::At(index));  
    }

    //template <typename Comparator>
    //void sort(Comparator comp) {
    //    VoidQueue::sort([comp](void* a, void* b) {
    //        return comp(static_cast<T*>(a), static_cast<T*>(b));
    //        });
    //}

    //template <typename Predicate>
    //std::vector<T*> findInRange(Predicate pred) const {
    //    auto result = VoidQueue::findInRange([pred](void* item) {
    //        return pred(static_cast<T*>(item));
    //        });

    //    std::vector<T*> typedResult;
    //    for (void* item : result) {
    //        typedResult.push_back(static_cast<T*>(item));
    //    }

    //    return typedResult;
    //}

    void OutputToFile(const string& filename) {
        VoidQueue::OutputToFile(filename);
    }
    void InputFromFile(const string& filename) {
        VoidQueue::InputFromFile(filename);
    }
    void PrintByName(const string& name) {
        VoidQueue::PrintByName(name);
    }
    ~TmpQueue() {
        while (!IsEmpty()) {
            delete Dequeue();
        }
    }
};