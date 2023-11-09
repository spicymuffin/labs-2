#include <iostream>
using namespace std;

void reverse_cstring(char cstr[], int size);

int main(int argc, char *argv[])
{
    // int v1, v2, *p1, *p2, *p3;

    // v1 = 100;
    // v2 = 120;

    // int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // p1 = &arr[0];
    // p2 = &arr[9];

    // while (p1 != p2 && ++p1 != p2)
    // {
    //     cout << p1 << ' ' << p2 << endl;
    //     cout << *p1 << endl;
    //     p1++;
    //     cout << *p2 << endl;
    //     p2--;
    //     cout << p1 << ' ' << p2 << endl;
    // }

    char a[] = "abcdef";
    cout << a << endl;
    reverse_cstring(a, 6);
    cout << a << endl;
}

void reverse_cstring(char cstr[], int size)
{
    char *head, *tail;
    head = &cstr[0];
    cout << head << endl;
    tail = &cstr[size - 1];
    while (head != tail && ++head != tail)
    {
        char temp = *head;
        cout << (void *) head << ' ' << (void *) tail << endl;
        cout << *head << " " << *tail << endl;
        *head = *tail;
        *tail = temp;
        cout << *head << " " << *tail << endl;
        head++;
        tail--;
    }
}
