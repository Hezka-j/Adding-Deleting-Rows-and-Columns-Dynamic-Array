#include <iostream>
using namespace std;

void AllocateMemoryFor2DArray(int**& ar, unsigned int width, unsigned int height)
{
    ar = new int* [height];
    for (int y = 0; y < height; y++)
    {
        ar[y] = new int[width];
    }
}

void FreeMemoryFor2DArray(int**& ar, unsigned int height)
{
    for (int y = 0; y < height; y++)
    {
        delete[] ar[y];
    }
    delete[] ar;
    ar = nullptr;
}

void AddRow(int**& ar, unsigned int& height, unsigned int width)
{
    int index;
    cout << "Enter index to add row - ";
    cin >> index;
    if (index < 0) index = 0;
    if (index > height - 1) index = height - 1;
    height++;

    int** temp = nullptr;
    AllocateMemoryFor2DArray(temp, width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y < index)
            {
                temp[y][x] = ar[y][x];
            }
            else if (y == index)
            {
                temp[y][x] = 0;
            }
            else
                temp[y][x] = ar[y - 1][x];
        }
    }

    FreeMemoryFor2DArray(ar, height - 1);

    ar = temp;
}

void DeleteRow(int**& ar, unsigned int& height, unsigned int width)
{
    int index;
    cout << "Enter index to delete row - ";
    cin >> index;

    if (index < 0) index = 0;
    if (index > height - 1) index = height - 1;

    int** temp = nullptr;
    AllocateMemoryFor2DArray(temp, width, height - 1);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y < index)
            {
                temp[y][x] = ar[y][x];
            }
            if (y > index)
            {
                temp[y - 1][x] = ar[y][x];
            }
        }
    }

    FreeMemoryFor2DArray(ar, height);

    ar = temp;

    height--;
}

void AddColumn(int**& ar, unsigned int height, unsigned int& width)
{
    int index;
    cout << "Enter index to add column - ";
    cin >> index;
    if (index < 0) index = 0;
    if (index > width - 1) index = width - 1;

    width++;

    int** temp = nullptr;
    AllocateMemoryFor2DArray(temp, width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x < index)
            {
                temp[y][x] = ar[y][x];
            }
            else if (x == index)
            {
                temp[y][x] = 0;
            }
            else
            {
                temp[y][x] = ar[y][x - 1];
            }
        }
    }
    FreeMemoryFor2DArray(ar, height);

    ar = temp;
}
void DeleteColumn(int**& ar, unsigned int height, unsigned int& width)
{
    
    int index;
    cout << "Enter index to delete column - ";
    cin >> index;

    if (index < 0) index = 0;
    if (index > width - 1) index = width - 1;

    int** temp = nullptr;
    AllocateMemoryFor2DArray(temp, width - 1, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x < index)
            {
                temp[y][x] = ar[y][x];
            }
            if (x > index)
            {
                temp[y][x - 1] = ar[y][x];
            }
        }
    }

    FreeMemoryFor2DArray(ar, height);

    ar = temp;

    width--;
}
void RandomFill2DArray(int** ar, unsigned int width, unsigned int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            ar[y][x] = rand() % 10;
        }
    }
}

void Print2DArray(int** ar, unsigned int width, unsigned int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << ar[y][x] << "\t";
        }
        cout << "\n\n";
    }
}

int main()
{
    unsigned int height;
    unsigned int width;
    cout << "Enter height - ";
    cin >> height;
    cout << "Enter width - ";
    cin >> width;
    int** ar = nullptr;

    AllocateMemoryFor2DArray(ar, width, height);
    RandomFill2DArray(ar, width, height);
    Print2DArray(ar, width, height);

    AddRow(ar, height, width);
    Print2DArray(ar, width, height);

    DeleteRow(ar, height, width);
    Print2DArray(ar, width, height);

    AddColumn(ar, height, width);
    Print2DArray(ar, width, height);

    DeleteColumn(ar, height, width);
    Print2DArray(ar, width, height);
   // FreeMemoryFor2DArray(ar, height);
}