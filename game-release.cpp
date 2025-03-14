//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
 //Main Canvas drawing function.
#include<unistd.h>
#include<sstream>
#include<cmath>      // for basic math functions such as cos, sin, sqrt
void DrawGrid();
void SnakeBody();
void SnakeMovement();
void CheckBoundary();
void Food();
void EatFood();
void Hurdle();
void HitHurdle();
void GameOver();
void MainMenu();
void StartMenu();
void StartGame();
void Display();
void SetCanvasSize(int width, int height);
void NonPrintableKeys(int key, int x, int y);
void PrintableKeys(unsigned char key, int x, int y);
void Timer(int m);
int foodX1 , foodY1;
int foodX2 , foodY2;
int foodX3 , foodY3;
int foodX4 , foodY4;
int foodX5 , foodY5;
int movement=2;
int previous_movement = 2;
int SquareX[100], SquareY[100];
int CircleX = 30 , CircleY = 10;
int length = 1;
int i=0;
char digit1=48;
char digit2=48;
int p =700;
int width = 650, height = 650; 
string score="score :  ";
int hurdleX[50];
int hurdleY[50];
using namespace std;

double startx=0,starty=0;


int main(int argc, char*argv[]) 
{
    score+=digit1;
    score+=digit2;
    score+=digit2;
    SquareX[0]=0;
    SquareY[0]=0;
    SquareX[1]=SquareX[0];
    SquareY[1]=SquareY[0];
    srand(time(NULL));
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...
    StartMenu();
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */


void DrawGrid()
{
	for(int i = 20; i<620 ; i+=20)
	{
		DrawLine( 0 , i ,  650 , i , 1 , colors[WHITE] );
	
	}
	for(int j= 20 ; j<650 ; j+=20)
	{
		DrawLine( j , 0 ,  j , 600 , 1 , colors[WHITE] );
	}
}

void SnakeBody()
{
    for(int b = 0 ; b<= length ; b++)
    {
      DrawSquare( SquareX[b] , SquareY[b] ,20,colors[5]);  
    }
    DrawCircle( CircleX , CircleY , 10 , colors[5]); 

}

void SnakeMovement()
{
	int tempX;
    int tempY;
	switch(movement)
	{
		case 1:                                 //left
            
			    CheckBoundary();
                for(int b = length ; b>=2 ; b--)
                {
                    tempX=SquareX[b-1];
                    tempY=SquareY[b-1];

                    SquareX[b]=tempX;
                    SquareY[b]=tempY;
                }
                    SquareX[1]=SquareX[0];
                    SquareY[1]=SquareY[0];
    			    SquareY[0] = CircleY-10;    
                    SquareX[0] = CircleX-10;
        	        CircleX-=20;

				
			break;
		case 2:									//right
                CheckBoundary();
                for(int b = length ; b>=2 ; b--)
                {
                    SquareX[b]=SquareX[b-1];
                    SquareY[b]=SquareY[b-1];
                }
                    SquareX[1]=SquareX[0];
                    SquareY[1]=SquareY[0];
    			    SquareX[0] = CircleX-10;
    			    SquareY[0] = CircleY-10;
    	            CircleX+=20;
                
			break;
		case 3:									//up
			    CheckBoundary();
                for(int b = length ; b>=2 ; b--)
                {
                    
                    SquareX[b]=SquareX[b-1];
                    SquareY[b]=SquareY[b-1];
                }  
                    SquareX[1]=SquareX[0];
                    SquareY[1]=SquareY[0];
    	            SquareY[0] = CircleY-10;
	                SquareX[0] = CircleX-10;
    	            CircleY+=20;

				break;
		case 4:					                //down
 			    CheckBoundary();
                for(int b = length ; b>=2 ; b--)
                {
                    SquareX[b]=SquareX[b-1];
                    SquareY[b]=SquareY[b-1];
                }  
                    SquareX[1]=SquareX[0];
                    SquareY[1]=SquareY[0];
    			    SquareY[0] = CircleY-10;
                    SquareX[0] = CircleX-10;   
                    CircleY-=20;
                        
				break;
        
	}
	
	
}

void CheckBoundary()
{
	if((CircleX == 630)&&(movement == 2))		//  boundary  from right movement
	{
		CircleX = 10;
	
	}
    else if((CircleY == 10)&&(movement == 4))  // boundary from down movement
    {
        CircleY = 590;
    }
	else if((CircleY==590)&&(movement == 3))				//boundary from up  movement
	{
        CircleY = 10;
	}
	else if((CircleX==10)&&(movement == 1))					//boundary from left movement
	{
		CircleX = 630;
	}
	else if((startx == 0)&&(starty == 600))				//top left corner
	{
		starty = 0;
	
	}


}

void Food()
{
    
        food:
        if(i%100==0)
        {
            
            foodX1 = 20+(rand()%500);
            foodX1/=20;
            foodX1*=20;
            foodX1+=10;

            foodY1 = 20+(rand()%500);
            foodY1/=20;
            foodY1*=20;
            foodY1+=10;

            foodX2 = 20+(rand()%500);
            foodX2/=20;
            foodX2*=20;
            foodX2+=10;

            foodY2 = 20+(rand()%500);
            foodY2/=20;
            foodY2*=20;
            foodY2+=10;

            foodX3 = 20+(rand()%500);
            foodX3/=20;
            foodX3*=20;
            foodX3+=10;            

            foodY3 = 20+(rand()%500);
            foodY3/=20;
            foodY3*=20;
            foodY3+=10;

            foodX4 = 20+(rand()%500);
            foodX4/=20;
            foodX4*=20;
            foodX4+=10;

            foodY4 = 20+(rand()%500);
            foodY4/=20;
            foodY4*=20;
            foodY4+=10;

            foodX5 = 20+(rand()%500);
            foodX5/=20;
            foodX5*=20;
            foodX5+=10;

            foodY5 = 20+(rand()%500);
            foodY5/=20;
            foodY5*=20;
            foodY5+=10;

        }    
                int sum1 = foodX1 + foodY1;
                int sum2 = foodX2 + foodY2;
                int sum3 = foodX3 + foodY3;
                int sum4 = foodX4 + foodY4;
                int sum5 = foodX5 + foodY5;
        if(
            //not in same column
        (foodX1!= foodX2)&&(foodX1 != foodX3)&&(foodX1 != foodX4)&&(foodX1 != foodX5)&&   // 1
        (foodX2 != foodX3)&&(foodX2 != foodX4)&&(foodX2 != foodX5)&&                        // 2
        (foodX3 != foodX4)&&(foodX3 != foodX5)&&                                            //3
        (foodX4 != foodX5)&&                                                                  //4
            //not in same row
            
        (foodY1!= foodX2)&&(foodY1 != foodY3)&&(foodY1 != foodY4)&&(foodY1 != foodY5)&&   // 1
        (foodY2 != foodY3)&&(foodY2 != foodY4)&&(foodY2 != foodY5)&&                        // 2
        (foodY3 != foodY4)&&(foodY3 != foodY5)&&                                            //3
        (foodY4 != foodY5)&&                                                                  //4
            //not in same diagonal
        (sum1!= sum2)&&(sum1 != sum3)&&(sum1 != sum4)&&(sum1 != sum5)&&   // 1
        (sum2 != sum3)&&(sum2 != sum4)&&(sum2 != sum5)&&                        // 2
        (sum3 != sum4)&&(sum3 != sum5)&&                                            //3
        (sum4 != sum5)                                                             //4          
        )                                                                  
        
        {
            DrawCircle(foodX1 ,foodY1 ,10 ,colors[GREEN]);
            DrawCircle(foodX2 ,foodY2 ,10 ,colors[YELLOW]);
            DrawCircle(foodX3 ,foodY3 ,10 ,colors[PINK]);
            DrawCircle(foodX4 ,foodY4 ,10 ,colors[ORANGE]);
            DrawCircle(foodX5 ,foodY5 ,10 ,colors[PALE_VIOLET_RED]);
        }
        else
        {
            goto food;
        }
    
            EatFood();
}

void Hurdle()
{
    //------------------Hurdle 1 {T} ------------------------------------------//

        for(int s =0 ; s<9 ; s++)
        {
            hurdleX[s] = 300;
            hurdleY[s] = 100+(s*20);
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }

        for(int s = 9 , k=0 ; s<12 ; k++,s++)
        {
            hurdleX[s] = 320+(k*20);
            hurdleY[s] = 260; 
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }

        for(int s = 12 , k=0 ; s<15 ; k++,s++)
        {
            hurdleX[s] = 280-(k*20);
            hurdleY[s] = 260; 
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }


    //------------------Hurdle 2 {L}----------------------------------------------//

        for(int s=15 , k=0; s<20 ; k++,s++)
        {
            hurdleX[s]= 400;
            hurdleY[s] = 500-(k*20);
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }


        for(int s=20 , k=0 ; s<24 ; k++,s++)
        {
            hurdleX[s] = 420+(k*20);
            hurdleY[s] = 420;
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }

    //-----------------Hurdle 3 {L}------------------------------------------------//

        for(int s=24 , k=0; s<29 ; k++,s++)
        {
            hurdleX[s]= 180;
            hurdleY[s] = 500-(k*20);
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);
        }    

  

        for(int s=29 , k=0 ; s<33 ; k++,s++)
        {
            hurdleX[s] = 160-(k*20);
            hurdleY[s] = 420;
            DrawSquare(hurdleX[s],hurdleY[s],20,colors[WHITE]);

        }


}

void EatFood()
{
        if((foodX1 == CircleX)&&(foodY1 == CircleY))
        {
                score="score : ";
                foodX1 = p;
                foodY1 = p;
                length++;
                if(digit2==57)
                {
                    digit1++;
                    digit2=48;
                    // score+=digit2
                    score+=digit1;
                    score+=digit2;
                }
                else
                {
                    digit2++;
                    score+=digit1;
                    score+=digit2;

                }
                
        }
        if((foodX2 == CircleX)&&(foodY2 == CircleY))
        {
                score ="score : ";
                foodX2 = p;
                foodY2 = p;
                length++;

                if(digit2==57)
                {
                    digit1++;
                    digit2=48;
                    // score+=digit2;
                    score+=digit1;
                    score+=digit2;
                }
                else
                {
                    digit2++;
                    score+=digit1;
                    score+=digit2;

                }
                
                
        }
        if((foodX3 == CircleX)&&(foodY3 == CircleY))
        {
                score = "score : ";
                foodX3 = p;
                foodY3 = p;
                length++;

                if(digit2==57)
                {
                    digit1++;
                    digit2=48;
                    // score+=digit2;
                    score+=digit1;
                    score+=digit2;
                }
                else
                {
                    digit2++;
                    score+=digit1;
                    score+=digit2;

                }

               
        }
        if((foodX4 == CircleX)&&(foodY4 == CircleY))
        {
                score = "score : ";
                foodX4 = p;              
                foodY4 = p;
                length++;

                if(digit2==57)
                {
                    digit1++;
                    digit2=48;
                    // score+=digit2;
                    score+=digit1;
                    score+=digit2;
                }
                else
                {
                    digit2++;
                    score+=digit1;
                    score+=digit2;

                }
        
                
        }
        if((foodX5 == CircleX)&&(foodY5 == CircleY))
        {
                score = "score : ";
                foodX5 = p;             
                foodY5 = p;
                length++;

                if(digit2==57)
                {
                    digit1++;
                    digit2=48;
                    // score+=digit2;
                    score+=digit1;
                    score+=digit2;
                }
                else
                {
                    digit2++;

                    score+=digit1;
                    score+=digit2;

                }

                
        }
        
}

void HitHurdle()
{
    
    for(int b = 0 ; b<=32 ; b++ )
    {
            if((hurdleX[b]+10== CircleX)&&(hurdleY[b]+10== CircleY))
            {
                    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
                    glutInitWindowPosition(50, 50); // set the initial position of our window
                    glutInitWindowSize(650, 650); // set the size of our window
                    glutCreateWindow("GAME OVER"); // set the title of our game window
                    SetCanvasSize(650, 650); // set the number of pixels...

                    glutDisplayFunc(GameOver); 
                    glutSpecialFunc(NonPrintableKeys); 
                    glutKeyboardFunc(PrintableKeys); 
                
                    

                
                                    
            }    
        
    }

    for(int i=0; i< length ; i++)
    {
        if((CircleX==(SquareX[i]+10))&&(CircleY==(SquareY[i]+10)))
        {
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
            glutInitWindowPosition(50, 50); // set the initial position of our window
            glutInitWindowSize(650, 650); // set the size of our window
            glutCreateWindow("GAME OVER"); // set the title of our game window
            SetCanvasSize(650, 650); // set the number of pixels...

            glutDisplayFunc(GameOver); 
            glutSpecialFunc(NonPrintableKeys); 
            glutKeyboardFunc(PrintableKeys); 
                
                          
        }
    }
                                     

}

void GameOver()
{

    glClearColor(1/*Red Component*/, 1/*Green Component*/,
            1/*Blue Component*/, 1 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors
    DrawSquare(30,30,600,colors[DARK_SLATE_GRAY]);

    DrawLine(130,500,430,500,10,colors[WHITE]);
    DrawLine(130,505,430,505,10,colors[WHITE]);
    DrawLine(130,510,430,510,10,colors[WHITE]);
    DrawLine(130,515,430,515,10,colors[WHITE]);
    DrawLine(130,520,430,520,10,colors[WHITE]);
    DrawString( 170, 500, "G A M E   O V E R !!!" , colors[RED]); 

    
    // ----------------------- SNAKE (BOTTOM) ------------------------------//
        DrawCircle(120,120,10,colors[RED]);
        DrawSquare(110,90,20,colors[RED]);
        DrawSquare(110,70,20,colors[RED]);
        DrawSquare(110,50,20,colors[RED]);
        DrawSquare(90,50,20,colors[RED]);
        DrawSquare(70,50,20,colors[RED]);
        DrawSquare(70,30,20,colors[RED]);
        DrawSquare(50,30,20,colors[RED]);
        DrawSquare(30,30,20,colors[RED]);
    //------------------------- FOOTER ------------------------------------//
        DrawString(200,100,"Made by : Hamda Shahid",colors[WHITE]);

    //------------------------- 2ND SNAKE --------------------------------//
        DrawSquare(610,300,20,colors[BLUE]);
        DrawSquare(610,320,20,colors[BLUE]);
        DrawSquare(610,340,20,colors[BLUE]);

        DrawSquare(590,340,20,colors[BLUE]);
        DrawSquare(570,340,20,colors[BLUE]);

        DrawSquare(570,320,20,colors[BLUE]);
        DrawSquare(570,300,20,colors[BLUE]);

        DrawSquare(570,280,20,colors[BLUE]);

        DrawSquare(550,280,20,colors[BLUE]);

        DrawSquare(530,280,20,colors[BLUE]);
        DrawSquare(510,280,20,colors[BLUE]);


        DrawSquare(510,300,20,colors[BLUE]);
        DrawSquare(510,320,20,colors[BLUE]);
        DrawSquare(510,340,20,colors[BLUE]);
        DrawSquare(510,360,20,colors[BLUE]);

        DrawSquare(490,360,20,colors[BLUE]);
        DrawSquare(470,360,20,colors[BLUE]);
        DrawSquare(450,360,20,colors[BLUE]);
        DrawSquare(430,360,20,colors[BLUE]);

        DrawCircle(420,370,10,colors[BLUE]);

    //<-----------------------------------DIFF CIRCLES-------------------------------------------->
        DrawCircle(100,200,10,colors[50]);

        DrawCircle(180,100,10,colors[40]);

        DrawCircle(300,300,10,colors[30]);
        
        DrawCircle(80,400,10,colors[20]);

        DrawCircle(300,400,10,colors[25]);

        DrawCircle(600,100,10,colors[60]);

        DrawCircle(500,150,10,colors[75]);

        DrawCircle(250,150,10,colors[90]);

        DrawCircle(350,200,10,colors[34]);

        DrawCircle(600,550,10,colors[45]);

        DrawCircle(250,570,10,colors[14]);

        DrawCircle(500,470,10,colors[95]);

        DrawCircle(480,590,10,colors[10]);

        DrawCircle(70,300,10,colors[67]);

    
    DrawString( 100, 400, score , colors[RED]);
    DrawString( 150, 350, "Press R for Main Menu" , colors[RED]); 
    DrawString( 250, 300, "Press esc for Exit" , colors[RED]); 
    DrawString( 300, 250, "Press A for New Game" , colors[RED]); 

   glutSwapBuffers(); // do not modify this line..
}

void StartMenu()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(650, 650); // set the size of our window
    glutCreateWindow("MAIN MENU"); // set the title of our game window
    SetCanvasSize(650, 650); // set the number of pixels...

    glutDisplayFunc(MainMenu); 
    glutSpecialFunc(NonPrintableKeys);    
    glutKeyboardFunc(PrintableKeys); 
                
    // glutTimerFunc(5.0 / FPS, Timer, 0);

}

void MainMenu()
{

   glClearColor(1/*Red Component*/, 1/*Green Component*/,
            1/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors
    DrawSquare(30,30,600,colors[DARK_SLATE_GRAY]);

    DrawLine(130,315,370,315,400,colors[WHITE]);
    DrawLine(130,320,370,320,400,colors[WHITE]);
    DrawLine(130,325,370,325,400,colors[WHITE]);
    DrawLine(130,330,370,330,400,colors[WHITE]);
    DrawLine(130,335,370,335,400,colors[WHITE]);
    DrawLine(130,340,370,340,400,colors[WHITE]);
    DrawString( 150, 320, "A : Start New Game" , colors[DARK_SLATE_GRAY]); 
    
    DrawLine(280,245,420,245,400,colors[WHITE]);
    DrawLine(280,250,420,250,400,colors[WHITE]);
    DrawLine(280,255,420,255,400,colors[WHITE]);
    DrawLine(280,260,420,260,400,colors[WHITE]);
    DrawLine(280,265,420,265,400,colors[WHITE]);
    DrawLine(280,270,420,270,400,colors[WHITE]);
    DrawString( 300, 250, "esc : Exit " , colors[DARK_SLATE_GRAY]);

    // ----------------------- SNAKE (BOTTOM) ------------------------------//
        DrawCircle(120,120,10,colors[RED]);
        DrawSquare(110,90,20,colors[RED]);
        DrawSquare(110,70,20,colors[RED]);
        DrawSquare(110,50,20,colors[RED]);
        DrawSquare(90,50,20,colors[RED]);
        DrawSquare(70,50,20,colors[RED]);
        DrawSquare(70,30,20,colors[RED]);
        DrawSquare(50,30,20,colors[RED]);
        DrawSquare(30,30,20,colors[RED]);

    //------------------------ TOP HEADING {SNAKE}  -------------------------------//
    //<---------------------- Letter {S} ---------------------------------->//
        DrawCircle(100,600,10,colors[RED]);
        DrawSquare(70,590,20,colors[RED]);

        DrawSquare(50,580,20,colors[RED]);
        DrawSquare(50,560,20,colors[RED]);
        DrawSquare(50,540,20,colors[RED]);
        DrawSquare(50,520,20,colors[RED]);
        
        DrawSquare(70,520,20,colors[RED]);
        
        DrawSquare(90,520,20,colors[RED]);
        DrawSquare(90,500,20,colors[RED]);
        DrawSquare(90,480,20,colors[RED]);
        DrawSquare(90,460,20,colors[RED]);
        
        DrawSquare(70,460,20,colors[RED]);
        DrawSquare(50,460,20,colors[RED]);

    //<---------------------------Letter {N}------------------------------->//
        DrawSquare(120,520,20,colors[WHITE]);    
        DrawSquare(120,500,20,colors[WHITE]);    
        DrawSquare(120,480,20,colors[WHITE]);
        DrawSquare(120,460,20,colors[WHITE]);

        DrawSquare(140,520,20,colors[WHITE]);    
        DrawSquare(160,520,20,colors[WHITE]); 
        DrawSquare(180,520,20,colors[WHITE]); 

        DrawSquare(180,500,20,colors[WHITE]);  
        DrawSquare(180,480,20,colors[WHITE]);  
        DrawSquare(180,460,20,colors[WHITE]);  

    //<--------------------------Letter{A} -------------------------------->//
        DrawSquare(210,520,20,colors[RED]);
        DrawSquare(210,500,20,colors[RED]);
        DrawSquare(210,480,20,colors[RED]);
        DrawSquare(210,460,20,colors[RED]);

        DrawSquare(230,520,20,colors[RED]);
        DrawSquare(250,520,20,colors[RED]);
        

        DrawSquare(250,500,20,colors[RED]);
        DrawSquare(250,480,20,colors[RED]);
        DrawSquare(250,460,20,colors[RED]);

        DrawSquare(230,460,20,colors[RED]);
        DrawSquare(250,460,20,colors[RED]);

        DrawSquare(270,460,20,colors[RED]);

    //<------------------------Letter{K} ------------------------------->//
        DrawSquare(300,520,20,colors[WHITE]);
        DrawSquare(300,500,20,colors[WHITE]);
        DrawSquare(300,480,20,colors[WHITE]);
        DrawSquare(300,460,20,colors[WHITE]);

        DrawSquare(320,490,20,colors[WHITE]);

        DrawSquare(338,510,15,colors[WHITE]);
        DrawSquare(350,520,20,colors[WHITE]);

        DrawSquare(340,474,15,colors[WHITE]);
        DrawSquare(350,460,20,colors[WHITE]);


    // <-------------------------Letter{E} --------------------------->//
        DrawSquare(380,520,20,colors[RED]);
        DrawSquare(380,500,20,colors[RED]);
        DrawSquare(380,480,20,colors[RED]);
        DrawSquare(380,460,20,colors[RED]);
        
        DrawSquare(400,520,20,colors[RED]);
        DrawSquare(420,520,20,colors[RED]);

        DrawSquare(400,490,20,colors[RED]);
        DrawSquare(420,490,20,colors[RED]);

        DrawSquare(400,460,20,colors[RED]);
        DrawSquare(420,460,20,colors[RED]);


    //------------------------- FOOTER ------------------------------------//
        DrawString(200,100,"Made by : Hamda Shahid",colors[WHITE]);

    //------------------------- 2ND SNAKE --------------------------------//
        DrawSquare(610,300,20,colors[BLUE]);
        DrawSquare(610,320,20,colors[BLUE]);
        DrawSquare(610,340,20,colors[BLUE]);

        DrawSquare(590,340,20,colors[BLUE]);
        DrawSquare(570,340,20,colors[BLUE]);

        DrawSquare(570,320,20,colors[BLUE]);
        DrawSquare(570,300,20,colors[BLUE]);

        DrawSquare(570,280,20,colors[BLUE]);

        DrawSquare(550,280,20,colors[BLUE]);

        DrawSquare(530,280,20,colors[BLUE]);
        DrawSquare(510,280,20,colors[BLUE]);


        DrawSquare(510,300,20,colors[BLUE]);
        DrawSquare(510,320,20,colors[BLUE]);
        DrawSquare(510,340,20,colors[BLUE]);
        DrawSquare(510,360,20,colors[BLUE]);

        DrawSquare(490,360,20,colors[BLUE]);
        DrawSquare(470,360,20,colors[BLUE]);
        DrawSquare(450,360,20,colors[BLUE]);
        DrawSquare(430,360,20,colors[BLUE]);

        DrawCircle(420,370,10,colors[BLUE]);

    //<-----------------------------------DIFF CIRCLES-------------------------------------------->
        DrawCircle(100,200,10,colors[50]);

        DrawCircle(180,100,10,colors[40]);

        DrawCircle(300,300,10,colors[30]);
        
        DrawCircle(80,400,10,colors[20]);

        DrawCircle(300,400,10,colors[25]);

        DrawCircle(600,100,10,colors[60]);

        DrawCircle(500,150,10,colors[75]);

        DrawCircle(250,150,10,colors[90]);

        DrawCircle(350,200,10,colors[34]);

        DrawCircle(600,550,10,colors[45]);

        DrawCircle(250,570,10,colors[14]);

        DrawCircle(500,470,10,colors[95]);

        DrawCircle(480,590,10,colors[10]);

        DrawCircle(70,300,10,colors[67]);

   glutSwapBuffers(); // do not modify this line..
}

void StartGame()
{
    score = "score : ";
    digit1 = 48;
    digit2 = 48; 
    score = score+ digit1 + digit2;
    

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(50, 50); 
    glutInitWindowSize(width, height); 
    glutCreateWindow("Hamda's Game"); 
    SetCanvasSize(width, height); 

    glutDisplayFunc(Display); 
    glutSpecialFunc(NonPrintableKeys); 
    glutKeyboardFunc(PrintableKeys); 
    glutTimerFunc(5.0 / FPS, Timer, 0);
}

void Display()
{
    glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   
    DrawString( 50, 620, score , colors[MISTY_ROSE]); 

    DrawLine( 0 , 600 ,  650 , 600 , 20 , colors[MISTY_ROSE] );
    DrawGrid();         
    Food();
	SnakeMovement();
	SnakeBody();
    // score+= digit;
        i++;
    Hurdle();    
    p+=30;
    HitHurdle();
    

   glutSwapBuffers(); // do not modify this line..
}

void SetCanvasSize(int width, int height) 
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


void NonPrintableKeys(int key, int x, int y)
{
    previous_movement=movement;
    if (key == GLUT_KEY_LEFT   /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
    {
											// what to do when left key is pressed...
        if(previous_movement!=2)
        {
            movement = 1; 

        }
        else
        {
            movement = 2;
        }
      
    } 
    else if (key == GLUT_KEY_RIGHT  /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
    {
       if(previous_movement!=1)
        {
            movement = 2; 

        }
        else
        {
            movement = 1;
        }
 	
		
    }
    else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/ 
    {
       if(previous_movement!=4)
        {
            movement = 3; 

        }
        else
        {
            movement = 4;
        }
    
    }
    else if (key == GLUT_KEY_DOWN)   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/ 
    {
       if(previous_movement!=3)
        {
            movement = 4; 

        }
        else
        {
            movement = 3;
        }
 
    }
    

    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y)
{
    if (key == KEY_ESC/* Escape key ASCII*/) {
        exit(1); // exit the program when escape key is pressed.
    }
    if (key == 'R' || key=='r'/* Escape key ASCII*/) 
    {
        StartMenu();  

    }
    
    if (key == 'A' || key == 'a')
    {
       StartGame(); 
	}
    
    glutPostRedisplay();
}


void Timer(int m) 
{

// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1000.0 / FPS, Timer, 0);
}

