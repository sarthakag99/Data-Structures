#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
} stack;

void print(stack *top)
{
	while (top != NULL)
	{
		printf("%d\n", top->data);
		top = top->next;
	}
}

void push(stack **start, int ele)
{
	stack *newnode = (stack *)malloc(sizeof(stack));
	newnode->data = ele;
	newnode->next = *start;
	*start = newnode;
	print(*start);
}

void pop(stack **start)
{
	if (*start == NULL)
	{
		printf("Stack is already empty!!\n");
	}
	else
	{
		*start = (*start)->next;
		print(*start);
	}
}

void top(stack **start)
{
	if (*start == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n", (*start)->data);
	}
}

void isempty(stack **start)
{
	if (*start == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack is not empty\n");
	}
}

int main()
{
	stack *start = NULL;
	int opt = 0;
	while (opt != 5)
	{
		printf("1. for push\n2. for pop\n3. for access to top element\n4. for check empty\n5. exit\n");
		printf("Enter your option:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("Enter element:");
			int ele;
			scanf("%d", &ele);
			push(&start, ele);
			printf("\n");
			break;
		case 2:
			pop(&start);
			printf("\n");
			break;
		case 3:
			top(&start);
			printf("\n");
			break;
		case 4:
			isempty(&start);
			printf("\n");
			break;
		case 5:
			exit(0);
			printf("\n");
			break;
		}
	}
	return 0;
}
