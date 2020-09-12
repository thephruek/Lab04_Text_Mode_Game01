#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship(int x,int y)
{	
	gotoxy(x,y);
	printf("<--0-->");
}
void erase_ship(int x,int y)
{
	gotoxy(x, y);
	printf("       ");
}
int main()
{
	setcursor(0);
	char ch = ' ';
	int x = 32, y = 20;
	draw_ship(x, y);
	setcolor(2, 4);
	setcolor(2, 0);
	do {

		if (_kbhit()) {
		ch = _getch();
		if (ch == 'a' && x > 0) {
			erase_ship(x, y);
			setcolor(2, 4);
			draw_ship(--x, y);
			setcolor(2, 0);
		}
		if (ch == 'd' && x < 73) {
			erase_ship(x, y);
			setcolor(2, 4);
			draw_ship(++x, y);
			setcolor(2, 0);
		}
		if (ch == 'w' && y > 0) {
			erase_ship(x, y);
			setcolor(2, 4);
			draw_ship(x, --y);
			setcolor(2, 0);
		}
		if (ch == 's') {
			erase_ship(x, y);

			setcolor(2, 4);
			draw_ship(x, ++y);
		}
		setcolor(2, 0);
		fflush(stdin);
	}
	Sleep(100);
  } while (ch != 'x');
	return 0;
}

