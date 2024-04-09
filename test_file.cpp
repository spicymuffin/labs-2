#include <iostream>
#include <cstdlib>
#include <string>

#include "util.h"

using namespace std;

class Book
{
public:
    Book() = default;

    Book(string _name, string _author)
    {
        name = _name;
        author = _author;
    }

    const string getName() const
    {
        // return name
        return name;
    }

    const string getAuthor() const
    {
        // return author
        return author;
    }

private:
    string name;
    string author;
};

class Library
{
public:
    // print the books in the library
    // each line should be in format:
    // {index of book}. {name}, {author}
    // example:
    //
    // 0. War and Peace, Leo Tolstoy
    // 1. To kill a mockingbird, Harper Lee
    //
    // etc...
    void printLibrary()
    {
        for (int i = 0; i < book_cnt; i++)
        {
            cout << i << ". " << (books + i)->getName() << ", " << (books + i)->getAuthor() << endl;
        }
    }

    // make an library with capacity equal to size
    Library(const int _size)
    {
        book_cnt = 0;
        size = _size;
        books = new Book[_size];
    }

    // destroy a library object
    ~Library()
    {
        delete[] books;
    }

    // return a pointer to the _nth book
    const Book *getNthBook(const int _n) const
    {
        return (books + _n);
    }

    // insert book to _n if the books array has space left and return 0
    // otherwise return -1
    // hint: shift the books after index _n to the right
    const int insert(const int _n, const Book a)
    {
        // check whether the library is full
        if (book_cnt >= size)
        {
            return -1;
        }

        // shift filled book slots
        for (int i = _n; i < book_cnt; i++)
        {
            Book tmp = books[i];
            books[i] = books[i + 1];
            books[i + 1] = tmp;
        }

        // insert book
        books[_n] = a;
        book_cnt++;
        return 0;
    }

    // remove at _n if the book at the index is valid and return 0
    // otherwise return -1
    // make sure the array
    // call book deconstructor when done removing a book.
    const int remove(const int _n)
    {
        // check whether book is "valid"
        if (_n >= book_cnt)
        {
            return -1;
        }

        // shift filled book slots
        for (int i = _n; i < book_cnt; i++)
        {
            Book tmp = books[i];
            books[i] = books[i + 1];
            books[i + 1] = tmp;
        }

        // remove book
        book_cnt--;
        return 0;
    }

protected:
private:
    // array. stores book objects
    Book *books;
    // size of array
    int size;
    // # of books present in the array.
    int book_cnt;
};

int main(int argc, char *argv[])
{
    Library lib = Library(10);
    cout << "test 1" << endl;
    lib.printLibrary();
    lib.insert(0, Book("War and Peace", "Leo Tolstoy"));
    cout << "test 2" << endl;
    lib.printLibrary();
    lib.insert(0, Book("To kill a mockingbird", "Harper Lee"));
    cout << "test 3" << endl;
    lib.printLibrary();
    lib.remove(1);
    cout << "test 4" << endl;
    lib.printLibrary();
    cout << "test 5" << endl;
    cout << lib.remove(1) << endl;
    return 0;
}