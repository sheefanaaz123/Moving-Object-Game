#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>  
#include <stdlib.h>

using namespace std;

static const int screenResolution = 15;
int centre = (screenResolution / 2) + 1;
char main_screen[screenResolution][screenResolution];

class Shape
{
  public:
  	
    int x = centre, y = centre;
    virtual int move() = 0;
    
    void info()
	{
     cout<<"----------KEYS FOR DIFFERENT COMMANDS----------\n\n";
	 cout<<"PRESS '1' to move the shape: UP\n";
	 cout<<"PRESS '2' to move the shape: DOWN\n";
	 cout<<"PRESS '3' to move the shape: LEFT\n";
	 cout<<"PRESS '4' to move the shape: RIGHT\n"; 
	 cout<<"PRESS '5' to Quit\n";
	}
	
    void screen()
    {
        for (int i = 0; i < screenResolution; i++)
        {
            for (int j = 0; j < screenResolution; j++)
            {
                if (i == x && j == y)
                {
                    main_screen[x][y] = '*';
                }
                else
                {
                    main_screen[i][j] = ' ';
                }
            }
        }
    }
    
    void display()
    {
    	
     
        for (int i = 0; i < screenResolution; i++)
        {
            for (int j = 0; j < screenResolution; j++)
            {
                cout << main_screen[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

class ComplexShape : public Shape
{
  public:
	
    int c_x = x, c_y = y;
    
    void create_complex_shape()
    {
    int i,o,j,n=6;
    for(i = 0; i <= n; i++)
    {
         for(o = n; o > i; o--){
          cout << " ";	
         }

        for(j=0; j<i; j++){
          main_screen[c_x + i][c_y + j] = '*';
          cout << "\n";
        }

    }
    
    for(i = 1; i < n; i++)
    {
      for(o = 0; o < i; o++){
        cout << " ";	
     }

    for(j = n; j > i; j--)
     main_screen[c_x + i][c_y + j] = '*';
     cout << "\n";
     }
    }
    int move()
    {
        int choice;
        while (choice != 5)
        {
            system("cls");
            screen();
            create_complex_shape();
            display();
            info();
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                c_x -= 1;
                break;
            case 2:
                c_x += 1;
                break;
            case 3:
                c_y -= 1;
                break;
            case 4:
                c_y += 1;
                break;
            case 5:
                cout << "---Thank You---";
                exit(0);
                break;
            default:
                cout << "Invalid input!";
                break;
            }
        }
    }
};

class SimpleShape : public Shape
{
public:
    int r_x = x, r_y = y;
    int t_x = x, t_y = y;
    int move() {}
};

class Box : public SimpleShape
{
public:
    void create_rectangle()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                main_screen[r_x + i][r_y + j] = '*';
            }
        }
    }
    
    int move()
    {
        int choice;
        while (choice != 5)
        {
            system("CLS");
            screen();
            create_rectangle();
            display();
            info();
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                r_x -= 1;
                break;
            case 2:
                r_x += 1;
                break;
            case 3:
                r_y -= 1;
                break;
            case 4:
                r_y += 1;
                break;
            case 5:
                cout << "--Thank You--";
                exit(0);
                break;
            default:
                cout << "Invalid Input!";
                break;
            }
        }
    }
};

class Tent : public SimpleShape
{
   public:
   	
    void create_triangle()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                main_screen[t_x + i][t_y + j] = '*';
            }
        }
    }
    
    int move()
    {
        int choice;
        while (choice != 5)
        {
            system("CLS");
            screen();
            create_triangle();
            display();
            info();
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                t_x -= 1;
                break;
            case 2:
                t_x += 1;
                break;
            case 3:
                t_y -= 1;
                break;
            case 4:
                t_y += 1;
                break;
            case 5:
                cout << "-----Thank You-----";
                exit(0);
                break;
            default:
                cout << "Invalid key";
                break;
            }
        }
    }
};


int main()
{
	
	 system("cls");
	 system("Color 0A");
	 system("Color E4");
	 
	 static CONSOLE_FONT_INFOEX  fontex;
     fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     GetCurrentConsoleFontEx(hOut, 0, &fontex);
     fontex.FontWeight = 300;
     fontex.dwFontSize.X = 25;
     fontex.dwFontSize.Y = 25;
     SetCurrentConsoleFontEx(hOut, NULL, &fontex);
     
     cout << "\n------------------------- OOP PROJECT -------------------------\n";
	 
    SimpleShape s;
    ComplexShape c;
    Box b;
    Tent t;

    char option;
    while (option != 5)
    {   
	    s.display();
        cout << "\n----- PRESS THE GIVEN OPTION FOR REQUIRED SHAPE -----\n\n";
        cout << "- PRESS B for Box.\n";
        cout << "- PRESS T for Tent.\n";
        cout << "- PRESS C for Complex Shape made with Simple Shape.\n";
        cout << "- PRESS E to Exit.\n";
        cout<<"\nEnter the option :: ";
        cin >> option;
        switch (option)
        {
        case 'B':b.move();
            break;
        case 'T':t.move();
            break;
        case 'C':c.move();
            break;
        case 'E':
            cout << "-----Thank You-----";
            exit(0);
            break;
        default:
            cout << "Invalid Input!";
            break;
        }
    }
    return 0;
}
