//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        // Insert index at end of heap
        data[size] = idx;
        size++;

        // Restore heap
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        if (size == 0) {
            return -1; // placeholder
        }

        // Save root
        int root = data[0];

        // Move last element to root
        data[0] = data[size - 1];
        size--;

        // Restore heap
        if (size > 0 ) {
            downheap(0, weightArr);
        }

        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos < size) {
            int parent = (pos - 1) / 2;

            // Compare current node vs parent
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                // Swap
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;
                pos = parent;
            }
            else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (2 * pos + 1 < size) {
            int left = 2 * pos + 1;
            int right =2 * pos + 2;
            int smallest = pos;

            // Find smallest
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            if (smallest != pos) {
                // Swap
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            }
            else {
                break;
            }
        }
    }
};

#endif