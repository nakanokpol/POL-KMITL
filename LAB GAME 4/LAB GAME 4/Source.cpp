#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf("<-0->");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("     ");
}

void main()
{

	//----------------------Assignment 1----------------------
   //draw_ship(10, 5);  


   /* //----------------------Assignment 2----------------------
   /*for (int i = 1;i <= 80;i++)
   {
	   draw_ship(i, 20);
	   Sleep(500);
   }*/

   //----------------------Assignment 3----------------------
   /*char ch=' ';
   int x=38,y=20;
   draw_ship(x,y);
   do
   {
	   if (_kbhit())
	   {
		   ch= _getch();
		   if (ch == 'a' && x >= 2)
		   {
			   draw_ship(--x, y);
		   }
		   if (ch == 'd' && x <= 80)
		   {
			   draw_ship(++x, y);
		   }
		   if (ch == 'w')
		   {
			   draw_ship(x, --y);
		   }
		   if (ch == 's')
		   {
			   draw_ship(x, ++y);
		   }
		   fflush(stdin);
	   }
	   Sleep(100);
   }
   while (ch!='x');*/

   //----------------------Assignment 4----------------------
   char ch = ' ';
   int x = 40, y = 20;
   draw_ship(x, y);
   do
   {
	   if (_kbhit())
	   {
		   ch = _getch();
		   if (ch == 'a' && x >= 1)
		   {
			   erase_ship(x, y);
			   draw_ship(--x, y);
		   }
		   if (ch == 'd' && x <= 80)
		   {
			   erase_ship(x, y);
			   draw_ship(++x, y);
		   }
		   if (ch == 'w')
		   {
			   erase_ship(x, y);
			   draw_ship(x, --y);
		   }
		   if (ch == 's')
		   {
			   erase_ship(x, y);
			   draw_ship(x, ++y);
		   }
		   fflush(stdin);
	   }
	   Sleep(100);
   } while (ch != 'x');

}