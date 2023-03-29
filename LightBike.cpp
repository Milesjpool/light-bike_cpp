#include <graphics.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define P1X_0 500
#define P1Y_0 250
#define P2X_0 200
#define P2Y_0 250
#define SCREEN_H 500
#define SCREEN_W 700
#define SPEED 5
#define MAX_FOOD 500


int speed;
int p1score = 0;
int p2score = 0;

struct P1_Data
{
 int head_x;
 int head_y;
 int head_dir;
 int futurex;
 int futurey;
 int futurepixel;
} Player1;

struct P2_Data
{
 int head_x;
 int head_y;
 int head_dir;
 int futurex;
 int futurey;
 int futurepixel;
} Player2;


int gamephysics ()
{
 int i, input;
 int winner = 0;
 Player1.futurepixel = 0;
 Player2.futurepixel = 0;
 
 Player1.futurex = Player1.head_x;
 Player1.futurey = Player1.head_y;
 
 Player2.futurex = Player2.head_x;
 Player2.futurey = Player2.head_y;
 
 if (Player1.head_dir == LEFT)
 {
  Player1.futurex --;           
 }
 
 if (Player1.head_dir == RIGHT)
 {
  Player1.futurex ++;           
 }
 
 if (Player1.head_dir == UP)
 {
  Player1.futurey --;           
 }
 
 if (Player1.head_dir == DOWN)
 {
  Player1.futurey ++;           
 }
 
 Player1.futurepixel = getpixel(Player1.futurex, Player1.futurey);
 
  if (Player2.head_dir == LEFT)
 {
  Player2.futurex --;           
 }
 
 if (Player2.head_dir == RIGHT)
 {
  Player2.futurex ++;           
 }
 
 if (Player2.head_dir == UP)
 {
  Player2.futurey --;           
 }
 
 if (Player2.head_dir == DOWN)
 {
  Player2.futurey ++;           
 }
 
 Player2.futurepixel = getpixel(Player2.futurex, Player2.futurey);
 
   if (Player1.futurepixel != 0 && Player2.futurepixel != 0)
 {
  setcolor (15);
  outtextxy(((SCREEN_W-50)/2), (SCREEN_H/2), "Draw!");
  winner = 3;
  delay (3000);
 }
 
  else if (Player1.futurepixel != 0)
 {
  setcolor (6);
  outtextxy(((SCREEN_W-100)/2), (SCREEN_H/2), "Player 1 wins!");
  winner = 1;
  delay (3000);
 }

  else if (Player2.futurepixel != 0)
 {
  setcolor (4);
  outtextxy(((SCREEN_W-100)/2), (SCREEN_H/2), "Player 2 wins!");
  winner = 2;
  delay (3000);
 }
 return (winner);
}


void userinput()
{
 char input, p1input, p2input;
 
 if (kbhit())
 {
  input = getch ();
  
  if(input == 72) p1input = UP;
    
  if(input == 80) p1input = DOWN;
    
  if(input == 75) p1input = LEFT;
    
  if(input == 77) p1input = RIGHT;
  
  if(input == 119 || input == 87) p2input = UP;
    
  if(input == 115 || input == 83) p2input = DOWN;
    
  if(input == 97 || input == 65) p2input = LEFT;
    
  if(input == 100 || input == 68) p2input = RIGHT;

  if (p1input == LEFT && Player1.head_dir != LEFT&& Player1.head_dir != RIGHT)
  {
   Player1.head_dir = LEFT;
  }
   
  if (p1input == RIGHT && Player1.head_dir != RIGHT && Player1.head_dir != LEFT)
  {
   Player1.head_dir = RIGHT;
  }
  
  if (p1input == UP && Player1.head_dir != UP && Player1.head_dir != DOWN)
  {
   Player1.head_dir = UP;
  }
  
  if (p1input == DOWN && Player1.head_dir != DOWN && Player1.head_dir != UP)
  {
   Player1.head_dir = DOWN;
  }

  if (p2input == LEFT && Player2.head_dir != LEFT&& Player2.head_dir != RIGHT)
  {
   Player2.head_dir = LEFT;
  }
   
  if (p2input == RIGHT && Player2.head_dir != RIGHT && Player2.head_dir != LEFT)
  {
   Player2.head_dir = RIGHT;
  }
  
  if (p2input == UP && Player2.head_dir != UP && Player2.head_dir != DOWN)
  {
   Player2.head_dir = UP;
  }
  
  if (p2input == DOWN && Player2.head_dir != DOWN && Player2.head_dir != UP)
  {
   Player2.head_dir = DOWN;
  } 
 }
}


void movesnake()
{
 if(Player1.head_dir == LEFT)
 {
  Player1.head_x --;
 } 
 if(Player1.head_dir == RIGHT)
 {
  Player1.head_x ++;
 } 
 if(Player1.head_dir == UP)
 {
  Player1.head_y --;
 }
 if(Player1.head_dir == DOWN)
 {
  Player1.head_y ++;
 } 
 putpixel(Player1.head_x, Player1.head_y, 4);
 
 
 if(Player2.head_dir == LEFT)
 {
  Player2.head_x --;
 } 
 if(Player2.head_dir == RIGHT)
 {
  Player2.head_x ++;
 } 
 if(Player2.head_dir == UP)
 {
  Player2.head_y --;
 }
 if(Player2.head_dir == DOWN)
 {
  Player2.head_y ++;
 } 
 putpixel(Player2.head_x, Player2.head_y, 6);
     
}


void initscreen()
{
 int i;
 char scorestring[100];
 
 setcolor(0);
 setfillstyle (0,0);
 bar (0, 0, SCREEN_W, SCREEN_H);
 setcolor(15);
 line (10, 10, 10, (SCREEN_H - 30));
 line ((SCREEN_W -10), 10, (SCREEN_W - 10), (SCREEN_H - 30));
 line (10, (SCREEN_H - 30), (SCREEN_W - 10), (SCREEN_H - 30));
 line (10, 10, (SCREEN_W - 10), 10);

 setcolor (6);
 sprintf(scorestring, "Player 1: %d", p1score);
 outtextxy (20, 475, scorestring);

 setcolor (4);
 sprintf(scorestring, "Player 2: %d", p2score);
 outtextxy (600, 475, scorestring); 

 putpixel(Player1.head_x, Player1.head_y, 4);
 putpixel(Player2.head_x, Player2.head_y, 6);
 
 setcolor (15);
 outtextxy (330, 150, "3");
 delay(700); 
 outtextxy (330, 150, "2");
 delay(700); 
 outtextxy (330, 150, "1");
 delay(700); 
 outtextxy (325, 150, "GO!");
 delay(700);
 setcolor(0);
 setfillstyle (0,0);
 bar (310, 140, 350, 170);
 delay(speed);
}     

void initgamedata()
{
 int i;
 
 Player1.head_x = P1X_0;
 Player1.head_y = P1Y_0;
 Player1.head_dir = LEFT;

 Player2.head_x = P2X_0;
 Player2.head_y = P2Y_0;
 Player2.head_dir = RIGHT;


 speed = SPEED;
 
}

void gameengine()
{
int again = 1;
int winner = 0;
int input, i;

 while (again == 1)
 {
  initgamedata();
  initscreen();
  winner = 0;
  while (winner == 0)
  {
   movesnake();
   userinput();
   winner = gamephysics();
   delay(speed);       
  }
  if (winner == 1)
  {
   p1score ++;
  }
  if (winner == 2)
  {
   p2score ++;
  }
  setcolor (15);
  outtextxy(((SCREEN_W-110)/2), (30+SCREEN_H/2), "Play again? y/n");
  input = 0;
  while (input != 121 && input != 89 && input != 110 && input != 78)
  {
   input = getch ();
   if(input == 121 || input == 89)
   {
    again = 1;
   }
   if(input == 110 || input == 78)
   {
    again = 0;
   }
  }
 }
}

int main()
{
 initwindow(SCREEN_W, SCREEN_H, "Light Bike 1.0");
 gameengine();
 
 return(0);
}

