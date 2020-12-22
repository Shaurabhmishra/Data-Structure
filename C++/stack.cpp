#include<iostream>
#include<string>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top = -1;
            for(int i=0; i<5; i++){
                arr[i]=0;
            }
        }
        
        bool isEmpty(){
            if(top==-1)
                return true;
            else
                return false;
        }

        bool isFull(){
            // int size = *(arr+1)-arr;
            int size = sizeof(arr)/sizeof(arr[0]);
            if(top == size-1)
                return true;
            else
                return false;
        }

        void push(int val){
            if(isFull()){
                cout<<"Stack Overflow (Full)"<<endl;
            }
            else{
                top++;
                arr[top]=val;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow (Empty)"<<endl;
                return 0;
            }
            else{
                int popVal = arr[top];
                arr[top]=0;
                top--;
                return popVal;
            }
        }

        int count(){
            return (top+1);
        }

        int peek(int pos){
            if(isEmpty()){
                cout<<"Stack Underflow (Empty)"<<endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }

        void change(int pos, int val){
            arr[pos] = val;
            cout<<"Value "<<val<<" is inserted at "<<pos<<"th position."<<endl;
        }

        void display(){
            cout<<"All values in the stack are ->> "<<endl;
            for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
    Stack s1;
    int option, position, value;
    do{
        cout<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. peek()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. change()"<<endl;
        cout<<"8. display()"<<endl;
        cout<<"9. clear screen"<<endl;
        cout<<"0. Exit"<<endl<<endl;

        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter the value to push in the stack"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"Pop function called - Pop value ->> "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else
                    cout<<"Stack is not empty";
                break;
            case 4:
                if(s1.isFull())
                    cout<<"Stack is full"<<endl;
                else
                    cout<<"Stack is not full";
                break;                
            case 5:
                cout<<"Enter the position of item you want to peek ->>"<<endl;
                cin>>position;
                cout<<"Peek function called - Value at position "<<position<<" is "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<"Count Fucntion called - Number of items in the stack are ->> "<<s1.count()<<endl;
                break;
            case 7:
                cout<<"Change function called ->> "<<endl;
                cout<<"Enter position of item you want to change ->>";
                cin>>position;
                cout<<"Enter value of item you want to change ->>";
                cin>>value;
                s1.change(position, value);
                break;
            case 8:
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
            cout<<"Please choose the correct option"<<endl;
        }
    }while(option!=0);
    return 0;
}