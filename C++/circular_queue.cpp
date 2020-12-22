#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int arr[5];
        int front, rear, itemCount;
        N = sizeof(arr)/sizeof(arr[0]);
    public:
        CircularQueue(){
            int itemCount=0;
            int front=rear=-1;

            for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
                arr[i]=0;
            }
        }
            bool isEmpty(){
                if(front==-1 && rear==-1)
                    return true;
                else
                    return false;
            }
            
            bool isFull(){
                if((rear+1)%N==front)
                    return true;
                else
                    return false;
            }

            void enqueue(int val){
                if(isFull()){
                    cout<<"Queue is Full"<<endl;
                    return;
                }
                else if(isEmpty()){
                    front = rear = 0;
                    arr[rear] = val;
                }
                else{
                    rear=(rear+1)%N;
                    arr[rear] = val;
                }
                itemCount++;
            }

            int dequeue(){
                int x;
                if(isEmpty()){
                    cout<<"Queue is Empty"<<endl;
                    return 0;
                }
                else if(front==rear){
                    x=arr[rear];
                    front=rear=-1;
                    itemCount--;
                    return x;
                }
                else{
                    cout<<"Front Value ->> "<<front<<endl;
                    x=arr[front];
                    arr[front]=0;
                    front=(front+1)%N;
                    itemCount--;
                    return x;
                }
            }

            int count(){
                return itemCount;
            }

            void display(){
                cout<<"All values in the Queue are ->>"<<endl;
                for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
            }
};

int main(){
    CircularQueue q1;
    int option, value;
    do{
        cout<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. clear screen"<<endl;
        cout<<"0. Exit"<<endl<<endl;

        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enqueue operation \nEnter an item to enqueue in the Queue ->>"<<endl;
                cin>>value;
                q1.enqueue(value);
                break;
            case 2:
                cout<<"Dequeue operation\nDequeued Value ->> "<<q1.dequeue()<<endl;
                break;
            case 3:
                if(q1.isEmpty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<"Queue is not empty";
                break;
            case 4:
                if(q1.isFull())
                    cout<<"Queue is full"<<endl;
                else
                    cout<<"Queue is not full";
                break;                
            case 5:
                cout<<"Count operation\nCount of items in the Queue ->> "<<q1.count()<<endl;                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
            cout<<"Please choose the correct option"<<endl;
        }
    }while(option!=0);
    return 0;
}