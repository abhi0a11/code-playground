#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
       size = k;
       arr= new int[size];
       front = -1;
       rear = -1;
    }
    
    bool enQueue(int value) {
        if((rear == (front-1) % (size)) || (front == 0 && rear == size-1)){
            return false;
        }
        else if( front == -1){
            front = rear = 0;
        }
        else if( rear == size -1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }
        
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }

        else if(front == size -1){
            front = 0;
        }
        else{ 
            front++;
        }
        return true;

    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        else    return arr[front];
    }

    
    int Rear() {
         if(rear == -1){
            return -1;
        }
        else    return arr[rear];
    }
    
    bool isEmpty() {
        if( front == -1 ){
            return true;
        }  
        else    return false;
    }
    
    bool isFull() {
        if((rear == (front-1) % (size)) || (front == 0 && rear == size-1)){
            return true;
        }
        else    return false;
    }
};

int main()
{

    return 0;
}