/// Linked List: Inserting a node at nth position 

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int x, int n)
{
	Node* temp1 = new Node( );
	temp1->data = x;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return ;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	return ;
}

void Delete(int n)
{
	struct Node* temp1 = head;
	
	if (n == 1)
	{
		head = temp1->next;
		free(temp1);
		return ;
	}
	for (int i = 0; i < n - 2; i++)
	{
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
	return ;
}

void Reverse( )
{
	struct Node *next, *pre, *current;
	
	current = head;
	pre = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = pre;
		pre = current;		
		current = next;
	}
	head = pre;
	return;
}

void Print(struct Node* vl)
{
	if (vl == NULL)
	{
		printf("\n");
		return ;
	}
	printf(" %d", vl->data);
	Print(vl->next);
	return ;
}

void ReversePrint(struct Node* vl)
{
	if (vl == NULL)	return ;
	ReversePrint(vl->next);
	printf(" %d", vl->data);
	return ;
}

int main( )
{
	head = NULL; // empty list
	
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	Print(head);
	ReversePrint(head);
	
	return 0;
}