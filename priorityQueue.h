#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class priorityQueue{
    private:
        /*
        left child at position: 2p + 1
        right child at position: 2p + 2
        parent at position: floor(p - 1 / 2)
        */
        vector<string> items;
        
    public:
        //will be implementing max heap, so first element is the highest priority one
        priorityQueue(){}
        bool isEmpty();
        int size();
        string front();
        void insert(string item);
        void heapifyUp();
        void heapifyDown();
        string deleteMax();
        void print();
};

bool priorityQueue::isEmpty(){
    return items.empty(); 
}

int priorityQueue::size(){ 
    return items.size();
}

string priorityQueue::front(){
    return items[0];
}

void priorityQueue::insert(string item){
    items.push_back(item);
    heapifyUp();
}

void priorityQueue::heapifyUp(){

}

string priorityQueue::deleteMax(){
    //deleting the first element and returning it
    string temp = items[0];
    items.erase(items.begin());
    heapifyDown();
    return temp;
}

void priorityQueue::heapifyDown(){

}

void priorityQueue::print(){

}
