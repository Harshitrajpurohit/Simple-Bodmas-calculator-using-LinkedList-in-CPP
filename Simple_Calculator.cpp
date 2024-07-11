
/*

This mobile calculator program accepts input using only the addition (+), subtraction (-), multiplication (*), and division (/) operators.
The calculation is triggered by pressing the "=" button.
It supports multiple operations chained together.

Input
20 + 30 * 40 - 10 / 5 = 
Output
1218


Input
2 + 3 - 4 * 2 / 6 + 4 - 9 + 10 - 9 =
Output
-0.333334

*/


#include<iostream>
using namespace std;

struct Node1{ //Node1 for values
    float  data;
    Node1 *next;
    Node1 *prev;
    Node1(float val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
struct Node2{ // Node2 for Operation
    char data;
    Node2 *next;
    Node2 *prev;
    Node2(char val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class Calculation{
    public:

    void division(Node1 *n,Node2 *k){

        Node2 *temp2=k;
        Node1 *temp1=n;
        // division
        while(temp2!=NULL){
            if(temp2->data=='/'){
                temp1->data/=temp1->next->data;
                temp1->next=temp1->next->next;
                temp2=temp2->next;
            }else{
            temp2=temp2->next;
            temp1=temp1->next;
            }
        }

        // delete "/" from LinkedList k
        temp2=k;
        while (temp2 != nullptr) {
            if (temp2->data == '/') {
                Node2* to_delete = temp2;
                if (temp2->prev != nullptr) {
                    temp2->prev->next = temp2->next;
                } else {
                    k = temp2->next; 
                }
                if (temp2->next != nullptr) {
                    temp2->next->prev = temp2->prev;
                }
                temp2 = temp2->next; 
                delete to_delete;
            } else {
                temp2 = temp2->next;
            }
        }
    }

    void multiplication(Node1 *n,Node2 *k){

        Node2 *temp2=k;
        Node1 *temp1=n;
        while(temp2!=NULL){
            if(temp2->data=='*'){
                temp1->data*=temp1->next->data;
                temp1->next=temp1->next->next;
                temp2=temp2->next;
            }else{
            temp2=temp2->next;
            temp1=temp1->next;
            }
        }
        temp2=k;
        // delete "*" from LinkedList k
        while (temp2 != nullptr) {
            if (temp2->data == '*') {
                Node2* to_delete = temp2;
                if (temp2->prev != nullptr) {
                    temp2->prev->next = temp2->next;
                } else {
                    k = temp2->next; 
                }
                if (temp2->next != nullptr) {
                    temp2->next->prev = temp2->prev;
                }
                temp2 = temp2->next;
                delete to_delete;
            } else {
                temp2 = temp2->next;
            }
        }
    }

    void add_sub(Node1 *n,Node2 *k){
        Node2 *temp2=k;
        Node1 *temp1=n;
        while(temp2!=NULL){
            if(temp2->data=='+'){
                temp1->data+=temp1->next->data;
                temp1->next=temp1->next->next;
                temp2=temp2->next;
            }else if(temp2->data=='-'){
                temp1->data-=temp1->next->data;
                temp1->next=temp1->next->next;
                temp2=temp2->next;            
            }else{
            temp2=temp2->next;
            temp1=temp1->next;
            }
        }
        temp2=k;
        while (temp2 != nullptr) {
            if (temp2->data == '+' || temp2->data == '-') {
                Node2* to_delete = temp2;
                if (temp2->prev != nullptr) {
                    temp2->prev->next = temp2->next;
                } else {
                    k = temp2->next; 
                }
                if (temp2->next != nullptr) {
                    temp2->next->prev = temp2->prev;
                }
                temp2 = temp2->next; 
                delete to_delete; 
            } else {
                temp2 = temp2->next;
            }
        }

    }
};

int main(){

    cout<<"\n|------------|------------|-------------|--------------|"<<endl;
    cout<<"| 1. +       | 2. -       | 3. *        | 4. /         |"<<endl;
    cout<<"|------------|------------|-------------|--------------|"<<endl;
    
    struct Node1 *n=0,*newnode1,*temp1;
    struct Node2 *k=0,*newnode2,*temp2;
    float num;
    cin>>num;
    newnode1=new Node1(num);
    n=temp1=newnode1;
    while(1){
        char key;
        cin>>key;
        
        if(key=='='){
            break;
        }
        newnode2=new Node2(key);
        if(k==0){
            k=temp2=newnode2;
        }else{
            temp2->next=newnode2;
            newnode2->prev=temp2;
            temp2=newnode2;
        }

        float num_input;
        cin >> num_input;
        newnode1 = new Node1(num_input);
        temp1->next = newnode1;
        newnode1 -> prev = temp1;
        temp1 = newnode1;

    }

    Calculation s;
    s.division(n,k);
    s.multiplication(n,k);
    s.add_sub(n,k);

    cout<<n->data;
}
