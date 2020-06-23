#ifndef NODE_H
#define NODE_H

#include <string>
#include<vector>

using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

Node *listIntersection(Node *first, Node *second);

Node *listIntersection(Node *first, Node *second){
    if (first == NULL || second == NULL){
        return NULL;
    }
    Node *temp1, *temp2, *head, *tempret;
    head = NULL;
    tempret = head;
    temp1=first;
    temp2 = second;
    bool flag = true;
    int check;
    for (temp1 = first; temp1 != NULL; temp1 = temp1->next_)
    {
        for (temp2 = second; temp2 != NULL; temp2 = temp2->next_){
            if (temp2 ->data_ == temp1->data_){
                if (tempret == NULL){
                    tempret = new Node;
                    tempret->data_ = temp2->data_;
                    tempret->next_ = NULL;
                    head = tempret;
                }
                else
                {
                    if (tempret->data_ != temp2->data_){
                        tempret->next_ = new Node;
                        tempret = tempret->next_;
                        tempret->data_ = temp2->data_;
                        tempret->next_ = NULL;
                    }
                }
                
            }
        }
    }
    return head;
}

#endif
