#include<stdio.h>
#include<stdlib.h>
#include"3.3.2 栈的数组实现 Stack.h"
#include"../Library/General.h"

Stack
CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize)
		Error("Stack size is too small");

	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		FatalError("Out of space!!!");

	S->Array = malloc(sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
		FatalError("Out of space!!!");
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void
DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

int
IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->Capacity - 1 == S->TopOfStack;
}

void
MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		Error("Full Stack");
	else
		S->Array[++(S->TopOfStack)] = X;
}

ElementType
Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	Error("Empty stack");

	return 0;	/* Return value used to avoid warning */
}

void
Pop(Stack S)
{
	if (IsEmpty(S))
		Error("Empty stack");
	else
		S->TopOfStack--;
}

ElementType
TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	Error("Empty Stack");

	return 0;	/* Return value used to avoid warning */
}