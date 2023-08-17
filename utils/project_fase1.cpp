#include <iostream>
#include <conio.h>
#include <cwchar>
#include <windows.h>
#include <math.h>
#include "utils.hpp"
using namespace std;
void main_menu(int n);
void print_info(int n);
void Exploring_image(int n);
void training(int n);
void test(int n);
//--------------------------------------------------------------------
int main()
{
    system("Color B0");
    int c;
    while (true)
    {
        system("CLS");
        HANDLE hOut;
     	SMALL_RECT DisplayArea = {0, 0, 0, 0};
     	//set x and y to whatever ye' want
     	int x = 50;
     	int y = 17;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     	DisplayArea.Right  = x;
     	DisplayArea.Bottom = y;
		SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
        CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = 24;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy(cfi.FaceName, L"Consolas");     //change font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        cout << endl << endl << endl ;
        cout << "\t ________________________________ " << endl;
        cout << "\t|      Enter your command:       |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|    1-Main menu                 |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|    2-Info                      |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|    3-Exit                      |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|________________________________|" << endl;
        cout << "\t               >>";

        cin >> c;
        switch (c)
        {
        case (1):
            main_menu(c);
            break;
        case (2):
            print_info(c);
            break;
        case (3):
            cout << "\tthank you for using this program!" << endl;
            exit(0);
            break;
        default:
            cout << "\tPlease check your command:";
            getch();
        }
    }
    main_menu(c);
    return 0;
}
//**********************************main menu*************************************
void main_menu(int n)
{
    while (1)
    {
        system("CLS");
        //system("Color 47");
        cout << endl << endl << endl ;
        cout << "\t ________________________________ " << endl;
        cout << "\t|     Enter your command:        |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|  1-Explore image from dataset  |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|  2-train                       |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|  3-Test                        |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|  4-Return                      |" << endl;
        cout << "\t|                                |" << endl;
        cout << "\t|________________________________|" << endl;
        cout << "\t              >>"                          ;
		cin >> n;
        switch (n)
        {
        case (1):
            Exploring_image(1);
            break;
        case (2):
            training(2);
            break;
        case (3):
            test(3);
            break;
        case (4):
            main();
            break;
        default:
            cout << "\tPlease check your command:" << endl;
            cout << "\t>>";
            getch();
            break;
        }
    }
}
//**************************Exploring image menu**********************************
void Exploring_image(int n)
{
    system("CLS");
    cout << endl << endl << endl ;
    cout << "\t ________________________________ " << endl;
    cout << "\t|         Exploring...           |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|     Enter your command:        |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|    1-back to main menu         |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|                                |" << endl;
    cout << "\t|________________________________|" << endl;
    cout << "\t              >>";
    int key = 0;
    while (key == 0)
    {
        cin >> key;
        switch (key)
        {
        case (1):
            main_menu(1);
            break;
        default:
            cout << "\t \tplease enter a valid numberâک¹ï¸ڈ:" << endl;
            break;
        }
    }
}
//********************************info print*********************************
void print_info(int n)
{
    system("cls");
    cout << endl << endl << endl ;
    cout << "\t**********************************" << endl;
    cout << "\t                                  " << endl;
    cout << "\t  Image classification with KNN   " << endl;
    cout << "\t                                  " << endl;
    //system("Color B6");
    cout << "\t         Erfan Abuei;)            " << endl;
    //system("Color B0");
	cout << "\t                                  " << endl;
    cout << "\t     erfan.abuee@outlook.com      " << endl;
    cout << "\t                                  " << endl;
	cout << "\t                                  " << endl;
	cout << "\t                                  " << endl;
    cout << "\t**********************************" << endl;
    //cout << "\t|________________________________|" << endl;
    system("pause");
    return;
}
//**********************************train************************************
void training(int n)
{
    system("cls");
    cout << endl << endl << endl ;
    cout << "\t \tTraining..." << endl;
    system("pause");
    return;
}
//*********************************test*********************************
void test(int n)
{
    system("cls");
    cout << endl << endl << endl ;
    cout << "\t \tTest..." << endl;
    system("pause");
    return;
}
//--------------------------------------------------------------------