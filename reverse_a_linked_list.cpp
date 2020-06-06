#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node *next;
        Node(int val){
            value=val;
            next=NULL;
        }
};
class LinkedList{
    Node *head;
    Node *tail;
    public:
        LinkedList(){
            head=tail=NULL;
        }
        void addNode(int val){
            if (head==NULL){
                head=new Node(val);
                tail=head;
            }
            else{
                tail->next=new Node(val);
                tail=tail->next;
            }
        }
        void printList(){
            Node *temp=head;
            while(temp!=NULL){
                cout<<temp->value<<" -> ";
                temp=temp->next;
            }
        }
        void reverseList(){
            Node *curr,*prev,*nxt;
            //intialise prev and curr
            prev=head;
            curr=head->next;
            ///build a loop 
            while (curr!=NULL){
                nxt=curr->next;
                curr->next=prev;
                if (prev==head){
                    tail=head;
                    prev->next=NULL;
                }
                prev=curr;
                curr=nxt;
            }

            //make changes to tail
            head=prev;
        }
};
int main(){
    LinkedList l;
    for (int i=0;i<10;i++)
        l.addNode(i);
    l.printList();
    l.reverseList();
    cout<<endl;
    l.printList();
    
    return 0;

}
