#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING_100

#define FALSE 0
#define TRUE 1 

typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택이 포화됐습니다/n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러/n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러가 났습니다/n");
		exit(1);
	}
	else return s->stack[(s->top)];
}

int palindrome(char in_str[])
{
	StackType s;
	int i;
	char ch, chs;
	int len = strlen(in_str);
	init(&s);

	for (i = 0; i < len; i++) {
		ch = in_str[i];
		if (ch == ' ' || ch == ',') continue;
		ch = tolower(ch);
		push(&s, ch);
	}

	for (i = 0; i < len; i++) {
		ch = in_str[i];
		if (ch == ' ' || ch == ',') continue;
		ch = tolower(ch);
		chs = pop(&s);
		if (ch != chs) return FALSE;
	}
	return TRUE;
}


int main(void)
{
	StackType s;
	char str[MAX_STACK_SIZE];
	int check;

	printf("문자열을 입력하시오.");
	gets(str);

	check = palindrome(str);

	if (check)
		printf("회문입니다");
	else
		printf("회문이 아닙니다.");
}