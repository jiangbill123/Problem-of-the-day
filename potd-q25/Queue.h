#pragma once

#include <cstddef>
#include <vector>
using namespace std;

class Queue {
    public:
        Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        vector<int> q;

};