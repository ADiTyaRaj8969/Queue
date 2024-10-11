#include<bits/stdc++.h>
using namespace std;
class Queue{
    int front,rear, size;
    int *arr;

    public:
    Queue(int s){
        arr = new int[s];
        front = -1;
        rear = -1;
        size = s;
    }
    void enqueue(int val){
    if(rear == size - 1){
        cout << "queue is full" << endl;
        return;
    }
    arr[++rear] = val;
    cout << "enqueued element: " << val << endl;
    if(front == -1){
        front++;
    }
}
bool isEmpty(){
if(front>rear|| front==-1){
    return true;
}
return false;
}
void dequeue(){
    if(isEmpty()){
     cout<<"Queue is Empty"<<endl;
     return;
    }
    cout<<"Dequeued the element:"<<arr[front]<<endl;
        front++;
}
void peek(){
    if(isEmpty()){
        cout<<"The queue is empty"<<endl;
        return ;
    }
    cout<<"The Front element is:"<<arr[front]<<endl;
}
};
int main(){
    Queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(10);
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(100);
    q.enqueue(200);
    return 0;
}