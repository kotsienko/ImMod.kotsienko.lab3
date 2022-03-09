#include <iostream>

using namespace std;

const int cell = 120; //количество клеток в поколении
const int iters = 60; //количество поколений
const char ON = '#'; //живая клетка
const char OFF = ' '; //мертвая клетка

void printline(int line[])
{
    for (int i = 0; i < cell; i++)
    {
        putchar(line[i] ? ON : OFF);
    }
    cout << endl; 
}

void changeline(int line[],int rule[])
{   
    int newline[cell], index = 0;

    for (int i = 0; i < cell; i++) newline[i] = line[i];

    for (int i = 0; i < cell - 2; i++)
    {
        int temp[3] = { line[i],line[i + 1],line[i + 2] };
        index = 0;
        for (int j = 3, k = 0; j > 0; j--, k++) 
            index += temp[k] * pow(2, j - 1);
        newline[i] = rule[index];
    }

    for (int i = 0; i < cell; i++) line[i] = newline[i];
}

int main()
{
    srand(time(NULL));
    int line[cell];
    int rule[8] = { 0, 1, 1, 1, 1, 1, 1, 0 }; //правило 126

    for (int i = 0; i < cell; i++) line[i] = rand() % 2;

    for (int i = 0; i < iters; i++) 
    { 
        printline(line);
        changeline(line,rule);
    }
}
