#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable : 4996)
#define NOS 16 //the Number of Stack

int Stack[NOS];
int top = -1;
char command[16] = { '\0', };

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void STACK() {
	for (int i = 0; i < top + 1; i++) {
		gotoxy(25, top + 1 - i);

		if (i == top)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

		printf("[%d] : %d", i + 1, Stack[i]);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(0, 0);
}

int IsPUSH(char s[]) {
	return (s[0] == 'p') && (s[1] == 'u') && (s[2] == 's') && (s[3] == 'h');
}

int IsPOP(char s[]) {
	return (s[0] == 'p') && (s[1] == 'o') && (s[2] == 'p');
}

int main() {
	system("title STACK[C LANG] - https://blog.naver.com/gmail2012");
	void* P;

	for (;;) {
		scanf(" %[^\n]s", command);

		system("cls");

		if (IsPUSH(command) == 1) {
			if (top > NOS - 2) {
				gotoxy(0, 5);
				puts("스택이 가득 찼습니다.");
			}
			else {
				P = &command[5];
				Stack[++top] = atoi(P);
			}
		}
		else if (IsPOP(command) == 1) {
			if (top < 0) {
				gotoxy(0, 5);
				puts("스택이 비어있습니다.");
			}
			else {
				top--;
			}
		}

		STACK();
	}
	return 0;
}