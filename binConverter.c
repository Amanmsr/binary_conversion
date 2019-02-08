#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int digit;
	struct node *next;
} node; 		//this program takes decimal number of any size and converts to binary
node *start = NULL;
void display_num(node*); //display the binary number
node* free_list(node*);
int main(){
	int num,i,choice;
	node *newnode;
	do{
	printf("WELCOME to the binary converter!\n Press 0 to EXIT and 1 to PLAY.\n");
	scanf("%d",&choice);
	if(choice == 1){
	printf("Enter the number:\n");
	scanf("%d",&num);
	for(i=1;i<=num;i=2*i){
		newnode = malloc(sizeof(node));
		newnode->digit= (num%(2*i) > (i-1))? 1 : 0;
		if(start == NULL){
			start = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = start;
			start = newnode;
		}
	}
	printf("The binary representation is:\n");
	display_num(start);
	start = free_list(start);
}
	else
	printf("Thanks for playing.\n");
	}while(choice!= 0);
	return 0;
}
void display_num(node *start){
	node *temp = start;
	while(temp != NULL){
		printf("%d ",temp->digit);
		temp = temp->next;
	}
	printf("\n");
	return;
}
node* free_list(node *start){ //deletes the whole list
	node *ptr;
	while(start!= NULL){
		ptr = start;
		start = start->next;
		free(ptr);
	}
	return start;
}

