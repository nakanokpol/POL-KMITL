#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
	gotoxy(x, y); setcolor(2, 4); printf("<-0->");
}

void delete_ship(int x, int y)
{
	gotoxy(x, y); setcolor(0, 0); printf("      ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void draw_ammo(int x, int y)
{
	gotoxy(x += 2, --y);
	setcolor(2, 0); 
	printf("*");
}

void delete_ammo(int x, int y)
{
	gotoxy(x += 2, --y);
	setcolor(0, 0);
	printf(" ");
}

int main()
{
	setcursor(0);
	int x1 = 38, x2[5], y1 = 20;
	int y2[5] = { 20,20,20,20,20 };
	int moving = 0, shoot[5] = { 0,0,0,0,0 }, count = -1;
	draw_ship(x1, y1);
	char ch = '.';
	do {
		for (int i = 0; i < 5; i++) { if (shoot[i] == 0) { x2[i] = x1; } }
		if (_kbhit()) 
		{
			ch = _getch();
			if (ch == 'a') { moving = 1; }
			if (ch == 'd') { moving = 2; }
			if (ch == 's') { moving = 0; }
			if (ch == ' ' && count < 4) 
			{ 
				++count; shoot[count] = 1;
			}
		}
		if (moving == 1 && x1 > 0)
		{ 
			delete_ship(x1, y1); draw_ship(--x1, y1); 
		}
		if (moving == 2 && x1 < 75) 
		{
			delete_ship(x1, y1); draw_ship(++x1, y1);
		}
		for (int j = 0; j <= 4; j++)
		{
			if (shoot[j] == 1 && y2[j] > 0) 
			{ 
				delete_ammo(x2[j], y2[j]); 
				draw_ammo(x2[j], --y2[j]);
			}
		}
		if (y2[0] == 1)
		{
			delete_ammo(x2[0], y2[0]); --count;
			for (int a = 1; a <= 4; a++) 
			{ 
				shoot[a - 1] = shoot[a]; y2[a - 1] = y2[a]; x2[a - 1] = x2[a]; 
			}
			shoot[4] = 0; y2[4] = y1; x2[4] = x1;
		}
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	return 0;
}