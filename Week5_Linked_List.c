#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct{
    int value;
    struct node_struct *next;
}node;

node *createNode(int v){
    //calloc: will initialized as 0;
    //malloc: will not initialize;
    node *p = (node *)calloc(1,sizeof(node));
    if(p == NULL){
        printf("couldn't create a node\n");
        return NULL;
    }
    p->value = v;
    p->next = NULL;
    return p;
}

node *insertAtHead(node *head, int v){
    node *p= createNode(v);
    p->next = head;
    return p;
}

node *insertAtTail(node *head, int v){
    node* p = createNode(v);
    if(head == NULL){
        return NULL;
    }
    node *tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = p;
    return head;
}

node *append(node *head, int v){
    //list is empty
    if(head == NULL){
        return createNode(v);
    }
    //code that appends v if the list is not empty
    node *p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = createNode(v);
    return head;
}


//deletes the first occurence of v in the list
//returns the head of the updated list
node *deleteElement(node *head, int v){
    if(head == NULL){
        return NULL;
    }
    
    if(head->value == v){
        node* tmp = head->next;
        free(head);
        return tmp;
    }

    //version 1:
    // node* cur = head->next;
    // node* pre = head;
    // while(cur!=NULL){
    //     if(cur->value==v){
    //         pre->next = cur->next;
    //         node* to_delete = cur;
    //         cur = cur->next;
    //         free(to_delete);
    //     }
    //     else{
    //         pre = cur;
    //         cur = cur->next;
    //     }
    // }

    //version 2:
    node *p= head;
    while(p->next!=NULL){
        if(p ->next->value == v){
            node *r = p->next->next;
            free(p->next);
            p->next = r;
        }
        else{
            p = p->next;
        }
    }

    return head;
}


node *search(node* head, int v){
    node *p = head;
    while(p!=NULL){
        if(p->value == v){
            return p;
        }
        p=p->next;
    }
}


void printList(node* head){
    if(head ==NULL){
        return;
    }
    node *tmp = head;
    while (tmp!=NULL)
    {
        if(tmp->next == NULL){
            printf("%d\n",tmp->value);
            return;
        }
        else{
            printf("%d->", tmp->value);
            tmp=tmp->next;
        }

    }
    
}
 

int main(){
    node *head_1 = NULL;
    head_1 = insertAtHead(head_1,20); //[20]
    head_1 = insertAtHead(head_1, 10); //[10 -> 20]
    head_1 = insertAtTail(head_1, 30); //[10 -> 20 -> 30]
    printList(head_1);
    
    node *head_2 = NULL;
    head_2 = append(head_2,10); //[10]
    head_2 = append(head_2, 20); //[10 -> 20]
    head_2 = append(head_2, 30); //[10 -> 20 -> 30]
    head_2 = deleteElement(head_2,10); //[20->30]
    printList(head_2);

    return 0;
}
