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
    const string getClassOfIndex(int _index) { return *(classList + _index); }

    void outputCourses()
    {
        cout << "classes for " << name << ":" << endl;
        for (int i = 0; i < numClasses; ++i)
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
        for (int i = 0; i < numClasses; ++i)
        {
            string className;
            cout << "class name: ";
            cin >> className;
            *(access_ptr + i) = className;
        }
    }

    void resetCourses()
    {
        delete[] classList;
        classList = NULL;
        numClasses = 0;
    }

    Student &operator=(Student &studentObject)
    {
        name = studentObject.getName();
        numClasses = studentObject.getNumClasses();
        delete[] classList;

        classList = new string[numClasses];
        for (int i = 0; i < numClasses; ++i)
        {
            classList[i] = studentObject.getClassOfIndex(i);
        }
        return *this;
    }

    ~Student()
    {
        // delete numClasses
        delete[] classList;
    }

private:
    string name;
    int numClasses;
    string *classList;
};

int main(int argc, char *argv[])
{
    Student st1, st2, st3;
    st1.inputData();
    cout << "initial:" << endl;
    st1.outputCourses();
    st2.outputCourses();
    st2 = st1;
    cout << "after assignment:" << endl;
    st2.outputCourses();
    st2.resetCourses();
    cout << "after reset:" << endl;
    st2.outputCourses();

    return 0;
}
