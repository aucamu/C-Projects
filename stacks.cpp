#include <iostream>
#include <conio.h>

using namespace std;


/******************************************************************************
/****	This program order the numbers member of array MAX to MIN			**/
/****	using a stacks														**/
/*****************************************************************************/


struct Node {

	int data;
	Node *next;
};

void AddElement(Node *&stack,int n)
{
	Node *newNode = new Node();
	
	newNode->data = n;
	newNode->next = stack;
	stack = newNode;
}

void DeleteElement(Node *&stack,int &n)
{
	Node *aux = stack;
	
	n = aux->data;
	stack = aux->next;
	delete aux;
}

int main(){
	
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int arrayOrder[10];
	int data;
	int j = 0;
	
	Node *stack = NULL;
	
	
	for (int i=0 ;i<10;i++)
	{
		AddElement(stack,array[i]);		
		printf("Insert data [%d]\n",array[i]);
	}	
	
	while(stack != NULL)
	{
		DeleteElement(stack,data);
		arrayOrder[j]=data;
		if(stack != NULL)
		{
			printf("Deleting data [%d]\n",data);	
		}else
		{
			printf("No more data\n");
		}
		
		j++;
		
	}
	
	printf("[");
	for(int k=0;k<10;k++)
	{
		printf("%d,",arrayOrder[k]);
	}
	
	printf("]\n");
	return 0;
}


