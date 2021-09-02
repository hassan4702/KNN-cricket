#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
double Absolute(int x)
{
	if (x < 0)
	{
		x = x * -1;
		return x;
	}
	return x;

}
void display(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";		
	}
}
void displayf(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";				
	}
}
int minxm(double arr[], int end)
{
	int min = 1000, index = 0;
	for (int i = 0; i < end; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
			
		}
	}
	return index;
} 
int minx(float arr[], int end)
{
	int min = 1000, index = 0;
	for (int i = 0; i < end; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;

		}
	}
	return index;
}
float ed(int x, int x2, int y, int y2)
{
	return sqrt(pow((x2 - x), 2) + pow((y2 - y), 2));
}
double Mandis(int x1, int x2, int y1, int y2)
{
	double md = Absolute(x2 - x1) + Absolute(y2 - y1);
	return md;
}
void indexsort(float ed[], int order[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		 int f= minx(ed, size);
		 order[i] = f;
		 ed[f] = 10000;
	}
}
void indexsortm(double ed[], int order[], int size)
{

	for (int i = 0; i < size; i++)
	{
		int f = minxm(ed, size);
		order[i] = f;
		ed[f] = 10000;
	}
}
void chckorder(int arr[],int order[], int order2[],int label[])
{
	int index = 0,h=0;
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 15; i++)
		{//     index sort   5value
			if (order[i] == order2[j])
			{  //                  11
				arr[index] = label[i];
				index++;
			}
			
		}
	}

}
void labelname()
{
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t ______________________________________" << endl;
	cout << "\t\t\t\t| K   K    N         N      N        N |  " << endl;
	cout << "\t\t\t\t| K  K     N N       N      N N      N |  " << endl;
	cout << "\t\t\t\t| K K      N   N     N      N   N    N | " << endl;
	cout << "\t\t\t\t| KK       N     N   N      N     N  N | " << endl;
	cout << "\t\t\t\t| K  K     N       N N      N      N N |" << endl;
	cout << "\t\t\t\t| K   K    N         N      N        N |" << endl;
	cout << "\t\t\t\t|______________________________________|" << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void compare(int order[], int k,int label[])
{
	int bow = 0, bat = 0, all = 0; 
	for (int c = 0; c < k; c++)   
	{
		if (label[order[c]] == 0)
		{
			bow++;
		}
		else if (label[order[c]] == 1) 
		{
			bat++;
		}
		else if (label[order[c]] == 2)
		{
			all++;
		}
	}
	if (bow > bat && bow > all)  
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY EUCLEDIAN DISTANCE" << endl;
		cout << " Best Suited For BOWLER Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
	else if (bat > bow && bat > all)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY EUCLEDIAN DISTANCE" << endl;
		cout << " Best Suited For BATSMAN Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);

	}
	else if (all > bow && all > bat)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY EUCLEDIAN DISTANCE" << endl;
		cout <<  " Best Suited For ALL ROUNDER Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
}
void comparem(int order[], int k, int label[])
{
	int bow = 0, bat = 0, all = 0;
	for (int c = 0; c < k; c++)
	{
		if (label[order[c]] == 0)
		{
			bow++;
		}
		else if (label[order[c]] == 1)
		{
			bat++;
		}
		else if (label[order[c]] == 2)
		{
			all++;
		}
	}
	if (bow > bat && bow > all)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY MANHATTON DISTANCE" << endl;
		cout << " Best Suited For BOWLER Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
	else if (bat > bow && bat > all)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY MANHATTON DISTANCE" << endl;
		cout << " Best Suited For BATSMAN Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);

	}
	else if (all > bow && all > bat)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << " BY MANHATTON DISTANCE" << endl;
		cout << " Best Suited For ALL ROUNDER Position" << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
}
int main()
{
	int k = 0, batavg = 0, ballavg = 0;
	int ans2[15];
	int x2[15] = { 50,45,48,62,48,15,12,12,5,6,35,34,55,26,31 };//batoin avg
	int y2[15] = { 50,50,58,65,43,21,20,15,12,23,29,26,29,41,28 };//ball avg
	int index_sorted[15];
	float ans[15];
	int label[15] = { 1,1,1,1,1,0,0,0, 0, 0, 2,2,2,2,2 };
	double mand[15]; 
	int orderm[15]; 
	double copym[15]; 
	labelname();
	cout << endl;
	cout << "Enter the batting avg  ";
	cin >> batavg;
	cout << "Enter bowling avg  ";
	cin >> ballavg;
	cout << "Enter(K), With How Many Player's Averages Distance You Want To Check(1-15) : ";
	cin >> k;
	for (int i = 0; i < 15; i++)
	{
		ans[i] = ed(batavg, x2[i], ballavg, y2[i]);
	}
	cout << endl;
	indexsort(ans, index_sorted, 15);
	compare(index_sorted, k,label);
	cout << endl;
	for (int c = 0; c < 15; c++)
	{
		mand[c] = Mandis(batavg, x2[c], ballavg, y2[c]);
	}

	indexsortm(mand, orderm, 15);
	comparem(orderm, k,label);

	SetConsoleTextAttribute(hConsole, 11);
	cout << "\n\n\n\n";
	cout << "\t\t\t\t  ____________________________________" << endl;
	cout << "\t\t\t\t |         GROUP MEMBERS              | " << endl;
	cout << "\t\t\t\t |      1) ENTER YOUR NAME            |" << endl;
	cout << "\t\t\t\t |____________________________________|" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
}
