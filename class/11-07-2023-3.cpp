#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(string _name, int _numClasses, string *_classList)
    {
        name = _name;
        numClasses = _numClasses;
        classList = _classList;
    };

    Student()
    {
        name = "";
        numClasses = 0;
        classList = NULL;
    };

    void setName(string _name) { name = _name; };
    void setNumClasses(int _numClasses) { numClasses = _numClasses; };
    void setClassList(string *_classList) { classList = _classList; };

    const string getName() { return name; };
    const int getNumClasses() { return numClasses; };
    const string *getClassList() { return classList; };

    void outputCourses()
    {
        cout << "classes for " << name << ":" << endl;
        for (int i = 0; i < numClasses; i++)
        {
            cout << "class " << i << ": " << classList[i] << endl;
        }
    }

    void inputData()
    {
        cout << "name: ";
        cin >> name;
        cout << "class count: ";
        cin >> numClasses;
        classList = new string[numClasses];
        string *access_ptr = classList;
        for (int i = 0; i < numClasses; i++)
        {
            string className;
            cout << "class name: ";
            cin >> className;
            *(access_ptr + i) = className;
        }
    }

    void resetCourses()
    {
        delete classList;
        classList = NULL;
        numClasses = 0;
    }

    PFArrayD &PFArrayD::operator=(const PFArrayD &rightSide)
    {
        if (capacity != rightSide.capacity)
        {
            delete[] a;
            a = new double[rightSide.capacity];
        }

        capacity = rightSide.capacity;
        used = rightSide.used;
        for (int i = 0; i < used; i++)
            a[i] = rightSide.a[i];

        return *this;
    }
    Student Student::operator=(const Student &studentObject)
    {
        name = studentObject.getName();
        numClasses = studentObject.getNumClasses();
        classList =
    }

    ~Student()
    {
        delete classList;
        // delete numClasses;
    }

private:
    string name;
    int numClasses;
    string *classList;
};

int main(int argc, char *argv[])
{
    Student student1;
    student1.inputData();
    student1.outputCourses();
    return 0;
}
