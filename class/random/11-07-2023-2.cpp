#include <iostream>
using namespace std;

void reverse_cstring(char cstr[], int size);

int main(int argc, char *argv[])
{
    int v1, v2, *p1, *p2, *p3;

    v1 = 100;
    v2 = 120;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int *entry;

    entry = new int[3];

    int *ptr = entry;

    for (int i = 0; i < 3; i++)
    {
        cin >> *ptr;
        ptr++;
    }

    cout << *(entry + 1) << endl;
}

void reverse_cstring(char cstr[], int size)
{
    char *head, *tail;
    head = &cstr[0];
    tail = &cstr[size - 1];
    while (head != tail || ++head != tail)
    {
        char temp = *head;
        cout << *head << " " << *tail << endl;
        *head = *tail;
        *tail = temp;
        cout << *head << " " << *tail << endl;
        head++;
        tail--;
    }
}
