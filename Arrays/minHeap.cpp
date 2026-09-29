#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] <= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void removeMin() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    int getMin() {
        if (heap.empty())
            return -1;

        return heap[0];
    }

    void print() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);
    h.insert(8);

    h.print();

    cout << "Minimum: " << h.getMin() << endl;

    h.removeMin();

    h.print();

    return 0;
}