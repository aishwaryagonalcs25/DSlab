#include<stdio.h>
#define Max 5
int queue[Max];
int front=-1;
int rear=-1;
//insert
void insert(){
    int value;
    if(rear==Max-1){
        printf("queue overflow\n");
        return;
    }
    printf("enter the ele to insert:");
    scanf("%d",&value);
    if(front==-1){
        front=0;
    }
    rear++;
    queue[rear]=value;
    printf("\n%d inserted in queue\n",value);
}
//delete
void delete(){
    if(front==-1||front>rear){
        printf("queue is empty\n");
        return;
    }
    printf("%d is deleted from queue\n",queue[front]);
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }

}
//display
void display(){
    int i;
    if(front==-1){
        printf("quqeue is empty\n");
        return;
    }
    printf("queue elements are:\n");
    for(i=front;i<=rear;i++){
        printf("%d",queue[i]);
        printf("\n");
    }
    printf("\n");
}
int main(){
    int choice;
    printf("\n--Queue menu---\n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.exit\n");
    while(1){
        printf("entr ur choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("invalid choice\n");
        }
    }
    return 0;

}