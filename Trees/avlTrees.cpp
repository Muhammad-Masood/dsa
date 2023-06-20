#include <iostream>
using namespace std;
#define COUNT 10;
class Node{
    public:
    Node *leftChild;
    Node *rightChild;
    int data;

    Node(int data){
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->data = data;
    }
};

class AvlTree
{
private:
    Node *root;

public:
    AvlTree(){
			int rV;
			cout<<"Enter Root Value\n";
			cin>>rV;
			root = new Node(rV);	
		}

        void insert(int d){
            if(root == NULL){
                root = new Node(d);
            }
            else{
                Node *temp = root;
                while(temp!=NULL){
                if(d<temp->data && temp->leftChild == NULL){
                    temp->leftChild = new Node(d);
                    cout<<"Inserted "<<d<<" at the left of data "<< temp->data<<endl;
                }
                else if(d<temp->data){
                    temp = temp->leftChild;
                }
                else if(d>temp->data && temp->rightChild == NULL){
                    temp->rightChild = new Node(d);
                }
                else if(d>temp->data){
                    temp = temp->rightChild;
                }
                }
            }
        }

        void printTree(){
            
        }

        int height(Node *temp){
            if(root == NULL){
                return 0;
            }
            else{
                int left = height(temp->leftChild);
                int right = height(temp->rightChild);
                return 1+max(left,right);
            }
        }

        int getBalanceFactor(Node *temp){
            if(temp == NULL){
                return 0;
            }
            else{
                return (height(temp->leftChild) - height(temp->rightChild));
            }
        }



};



int main(){
    AvlTree avl;
    while(true){
		cout<<"1) Insert Data\n2) Print Tree\nn0) Exit\n";
		int val;
		cin>>val;
		if(val==1){
			int data = 1;
			while(data>0){
				cout<<"Enter Data\n";
				cin>>data;
				if(data<=0){
					break;
				}
				avl.insert(data);
			}
		}
		else if (val == 2){
			avl.printTree();
		}
}
}