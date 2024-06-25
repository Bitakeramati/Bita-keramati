#include <iostream>
#include <vector>

class MinHeap {
private:
 std::vector<int> heap;

 void heapifyUp(int index) {
 int parent = (index - 1) / 2;
 while (index > 0 && heap[index] < heap[parent]) {
 std::swap(heap[index], heap[parent]);
 index = parent;
 parent = (index - 1) / 2;
 }
 }

 void heapifyDown(int index) {
 int leftChild = (2 * index) + 1;
 int rightChild = (2 * index) + 2;
 int smallest = index;
 if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
 smallest = leftChild;
 }

 if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
 smallest = rightChild;
 }

 if (smallest != index) {
 std::swap(heap[index], heap[smallest]);
 heapifyDown(smallest);
 }
 }

public:
 void insert(int value) {
 heap.push_back(value);
 heapifyUp(heap.size() - 1);
 }

 void deleteValue(int value) {
int index = -1;
 for (int i = 0; i < heap.size(); i++) {
 if (heap[i] == value) {
 index = i;
 break;
 }
 }

 if (index != -1) {
 std::swap(heap[index], heap[heap.size() - 1]);
 heap.pop_back();
 heapifyDown(index);
 }
 }

 void print() {
      for (int value : heap) {
          std::cout << value << " ";
          }
      std::cout << std::endl;
      }
};
int main() {
     MinHeap minHeap;
     minHeap.insert(1);
     minHeap.insert(2);
     minHeap.insert(3);

     minHeap.print();

     minHeap.deleteValue(2);

     minHeap.print();

     return 0;
}