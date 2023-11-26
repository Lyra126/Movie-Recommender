#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct movieNode{
    string movie;
    int rank;

    public:
        //constructors
        movieNode(): movie(""), rank(0){}
        movieNode(string movie, int rank){
            this->movie = movie;
            this->rank = rank;
        }

        string getMovie() const
            {return movie;}

        int getRank() const
            {return rank;}

        void setMovie(string movie)
            {this->movie = movie;}

        void setRank(int rank)
            {this->rank = rank;}
};

class priorityQueue{
    private:
        /*
        left child at position: 2p + 1
        right child at position: 2p + 2
        parent at position: floor(p - 1 / 2)
        */
        vector<movieNode> items;
        
    public:
        //will be implementing max heap, so first element is the highest priority one
        priorityQueue(){}
        bool isEmpty();
        int getSize();
        movieNode front();
        void insert(string item, int rank);
        void heapifyUp(int index);
        void heapifyDown(int index);
        movieNode deleteMax();
        void print();
};

bool priorityQueue::isEmpty(){
    return items.empty(); 
}

int priorityQueue::getSize(){ 
    return items.size();
}

movieNode priorityQueue::front(){
    return items[0];
}

void priorityQueue::insert(string item, int rank){
    movieNode newMovie(item, rank);
    items.push_back(newMovie);
    heapifyUp(getSize()-1);
}

void priorityQueue::heapifyUp(int index){
    // Continuously compare the inserted node with the parent node and move it up if it is of higher rank
    while (index > 0) {
        int parentIndex = (index - 1) / 2;

        // If the rank of the child is greater than the parent, swap their positions
        if (items[index].getRank() > items[parentIndex].getRank()) {
            swap(items[index], items[parentIndex]);
            index = parentIndex; // Update index as well
        } else {
            break; // Break the loop if the heap property is satisfied
        }
    }
}

movieNode priorityQueue::deleteMax(){
    //deleting the first element and returning it
    movieNode temp = items[0];
    items.erase(items.begin());
    heapifyDown(0);
    return temp;
}

void priorityQueue::heapifyDown(int index){
    int size = getSize();
    int maxIndex = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    //check if left child exists and had higher rank than the current rank
    if(leftChild < size && items[leftChild].getRank() > items[maxIndex].getRank())
        maxIndex = leftChild;

    //check if right child exists and had higher rank than the current rank
    if(rightChild < size && items[rightChild].getRank() > items[maxIndex].getRank())
        maxIndex = rightChild;

    //if max index is different from current, swap and continue
    if(maxIndex != index){
        swap(items[index], items[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void priorityQueue::print(){
    for(const auto& movie : items)
        cout << movie.getMovie() << ": " << movie.getRank() << endl;
}
