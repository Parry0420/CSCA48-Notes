#include <stdio.h>
#include <string.h>

typedef struct student{
    char name[20];
    int id;
    float gpa;
}Student;
void foo(Student *s){
    strcpy(s->name,"john");
}


typedef struct node_struct{
  int value;
  struct node_struct *next;
}Node;

//wrong case
Node* addToList(Node *head, int v){  
  Node *new_node;
  new_node->value = v;
  new_node->next = head;
  return new_node;
}

Node *insertAtHead(Node *head, int v){
  Node* p=(Node*)calloc(1,sizeof(Node));
  p->value = v;
  p->next =head;
  return p;
}

int main(){
    Student x;
    Student students[1000];
    students[0].name;
    strcpy(x.name, "alex");
    x.gpa = 2.8;
    x.id = 1000;
    foo(&x);
    printf("The student's name is %s\n", x.name);


    //scanf()
    int x,y;
    float z;
    char c;
    scanf("%dxyz%dab%f",&x,&y,&z); //must follow the format "%dxyz%dab%f". ex:3xyz4ab5.6
    getchar(); 
    scanf("%c",&c);
    printf("c=%c\n",c);
    printf("%d, %d, %f\n",x,y,z);


    //fgets()
    char my_string[1024];
    printf("Please type one string\n");
    fgets(my_string,1024,stdin); //declare "my_string" as user's input
    printf("the input string is:%s\n",my_string); 


    Node n1,n2,n3;

    n3.value = 5;
    n3.next = NULL;

    n2.value = 1;
    n2.next = &n3;

    n1.value = 9;
    n1.next = &n2;

    Node *p = &n1;
    while(p!=NULL){
      printf("%d\n",p->value);
      p=p->next;
    }
}



