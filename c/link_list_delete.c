#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* reverseIteratively(struct Node* head){
	if (head->next==NULL || head==NULL){
		return head;		
	}	
	struct Node *temp,*temp2;
	temp=head;
	temp2=head->next;
	head=temp2;	
	temp->next=NULL;
	while(head->next!=NULL){
		head=temp2->next;
		temp2->next=temp;
		temp=temp2;
		temp2=head;
	}
	head->next=temp;
	return head;
	
}

struct Node* delete(struct Node* head, int pos){
	if (pos==0){
		return head->next;	
	}
	else{
		struct Node* temp, *temp2;
		temp=head;
		temp2=head->next;
		int i=0;
		while(i<pos-1 && temp->next!=NULL){
			temp=temp->next;
			temp2=temp2->next;
			i++;
		}
		temp->next=temp2->next;
		free(temp2);
		return head;

	}
}

struct Node* insert(struct Node* head,int data, int pos){
  struct Node* temp;
  
  temp=head;
  if (pos==0 || head==NULL){
    struct Node* temp2;
    temp2=(struct Node*) malloc(sizeof(struct Node));
    temp2->data=data;
    temp2->next=head;
    head=temp2;
    return head;
  }
  else{
    int i=0;
    while(i<pos-1 && temp->next!=NULL){   // there is a small position bug at below printf line which doesn't work when the LL size is below 2
      i++;
      temp=temp->next;
	  //if (i==pos-1 && temp->next!=NULL){
	    //printf("position entered is larger than the size of linked list so will insert in the end\n");
	  //}
    }
    struct Node* temp2;
    temp2=(struct Node*) malloc(sizeof(struct Node));
    temp2->data=data;
    temp2->next=temp->next;
    temp->next=temp2;
    return head;
  }
}
void 
void printLinkList(struct Node* head){
  if (head==NULL){
	printf("empty\n");
    return;
  }
  struct Node* temp;
  temp=(struct Node*) malloc(sizeof(struct Node));
  temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;

  }
  printf("\n");
}
int main(){
  
  
  struct Node* head=NULL;
  while(1){
	  printf("enter your choice 1. insert 2. delete 3.printLL 4.reverse 5. exit\n");
	  int n;
  	  int pos,data;
  	  scanf("%d",&n);
	  switch (n){
		case 1: 
		  printf("enter the data and pos\n");
		  scanf("%d%d",&data,&pos);
		  head=insert(head,data, pos);
		  break;
		case 2:
		  printf("enter the pos\n");
		  scanf("%d",&pos);
		  head=delete(head,pos);
		  break;
		case 3:
		  printLinkList(head);
		  break;
		case 4:
			head=reverseIteratively(head);
			break;
		case 5:
		  exit(0);
		  break;
		default:
		  printf("enter valid input\n");
	  }
  }
  return 0;
}
