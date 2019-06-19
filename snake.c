#include<time.h>
#include<stdlib.h>
int m,n,a;
void boundary();
int snake(int x[1500],int y[1500],char d[1500])
{
int i;
long score=(a-5)*100;
if(x[0]==m&&y[0]==n)
{
take:
gotoxy(m,n);
printf(" ");
m=rand()%71+3;
n=rand()%17+4;
for(i=0;i<a;i++)
if(x[i]==m&&y[i]==n)
goto take;
a++;
}
if(a>=1406)
{
gotoxy(30,12);
printf("Congratulation You Won The Game");
gotoxy(32,12);
printf("Your Score : %ld",score);
getch();
return 1;
}
gotoxy(m,n);
printf("%c",5);
for(i=0;i<a;i++)
{
gotoxy(x[i],y[i]);
printf("%c",d[i]);
}
gotoxy(x[i],y[i]);
printf(" ");
gotoxy(3,23);
printf(" Your Score : %ld",score);
for(i=1;i<a;i++)
if(x[0]==x[i]&&y[0]==y[i])
goto out;
if(x[0]<3||x[0]>75||y[0]<4||y[0]>21)
{
out:
gotoxy(34,10);
printf("GAME OVER");
gotoxy(32,12);
printf("Your Score : %ld",score);
delay(1000);
getch();
return 1;
}
return 0;
}
void boundary()
{
int i,ab=3,de=22,cd=2,dc=1;
gotoxy(35,2);
printf("SNAKE GAME");
gotoxy(2,1);
printf("%c",201);
gotoxy(76,1);
printf("%c",187);
gotoxy(2,25);
printf("%c",200);
gotoxy(76,25);
printf("%c",188);
for(i=0;i<=72;i++,ab++)
{
gotoxy(ab,dc);
printf("%c",205);
gotoxy(ab,dc+2);
printf("%c",205);
gotoxy(ab,dc+21);
printf("%c",205);
gotoxy(ab,dc+24);
printf("%c",205);
}
de=76,ab=2;
gotoxy(33,23);
printf("BkSp Pause\t\t Esc Quit") ;
printf("\n made by:mohammed ujjain wala");
for(i=0;i<23;i++,cd++)
{
gotoxy(ab,cd);
printf("%c",186);
gotoxy(de,cd);
printf("%c",186);
}
gotoxy(2,3);
printf("%c",204);
gotoxy(2,22);
printf("%c",204);
gotoxy(76,3);
printf("%c",185);
gotoxy(76,22);
printf("%c",185);
}
void main()
{
int i,key,set,max=1406,x[1500],y[1500],speed=200,select;
char d[1500];
randomize();
m=rand()%71+2;
n=rand()%17+2;
clrscr();
printf("\n\n\n\n\n\t\t\t MOHAMMED UJJAIN WALA\n\n\t\t\t\t PRESENTS");
printf("\n\n\n\t\t\t\tSNAKE GAME");
printf("\n\n\n\npress any key to continue");
getch();
while(1)
{
phir:
clrscr();
printf("\n\n\t\t\tSNAKE GAME");
printf("\n\n\n\t1.) START\t\t\tpress 1\n\n\t2.) INSTRUCTIONS\t\tpress 2\n\n\t3.) SETTINGS\t\t\tpress 3\n\n\t4.) EXIT\t\t\tpress 4 ");
scanf("%d",&select);
clrscr();
boundary();
switch(select)
{
case 1:
for(i=0;i<max;i++)
d[i]='*',x[i]=i+40,y[i]=10;
d[0]=2,key=75,a=5;
while(1)
{
if(kbhit())
{
key=getch();
if(!key)
key=getch();
}
switch(key)
{
case 75:
if(x[0]-1==x[1])
goto same;
for(i=a;i>0;i--)
y[i]=y[i-1],x[i]=x[i-1];
x[0]-=1,set=1;
if(snake(x,y,d))
goto phir;
break;
case 77:
if(x[0]+1==x[1])
goto same;
for(i=a;i>0;i--)
y[i]=y[i-1],x[i]=x[i-1];
x[0]++,set=2;
if(snake(x,y,d))
goto phir;
break;
case 72:
if(y[0]-1==y[1])
goto same;
for(i=a;i>0;i--)
y[i]=y[i-1],x[i]=x[i-1];
y[0]--,set=3;
if(snake(x,y,d))
goto phir;
break;
case 80:
if(y[0]+1==y[1])
goto same;
for(i=a;i>0;i--)
y[i]=y[i-1],x[i]=x[i-1];
y[0]++,set=4;
if(snake(x,y,d))
goto phir;
break;
case 27:
goto phir;
case 32:
snake(x,y,d);
gotoxy(30,12);
printf("press any key to continue...");
getch();
clrscr();
boundary();
default:
same:
printf("\a");
if(set==1)
key=75;
else if(set==2)
key=77;
else if(set==3)
key=72;
else
key=80;
break;
}
if(kbhit())
delay(40);
else
delay(speed);
}
case 2:
clrscr();
printf("\t\t\t\tHOW TO PLAY\n\nOur snake is hungry and you have to direct it toward its food ,more the snake will eat more it will grow .Remember snake should not collide with walls or itself or game will be over.\nUse arrow key to move the snake");
printf("\n\n\n\t\t\t ****ENJOY THE GAME****\n\n\n press any key to continue..............");
getch();
goto phir;
case 3:
clrscr();
printf("\t\t\t\tSETTINGS\nEnter the speed level (1-5): ");
spee:
scanf("%d",&speed);
if(speed==5)
speed=100;
else if(speed==4)
speed=200;
else if(speed==2)
speed=400;
else if(speed==1)
speed=500;
else if(speed==3)
speed=300;
else
{
clrscr();
printf("\t\t\t\tSETTINGS\nPlease enter the no.between 1-5 :");
goto spee;
}
printf("\nYour speed level has been set\npress any key to continue");
getch();
goto phir;
case 4:
exit(0);
}
}
}


