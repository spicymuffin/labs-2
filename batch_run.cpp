#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <chrono>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    const string testCaseDirectory = "/home/luigi-linux/labs-2/lab_02/data/test2";
    const string outputDirectory = "/home/luigi-linux/labs-2/lab_02/src/problem2_outputs";
    const string executablePath = "/home/luigi-linux/labs-2/lab_02/src/problem2_cincout.exe";

    // cout << "test case directory: ";
    // cin >> testCaseDirectory;
    // cout << "output directory: ";
    // cin >> outputDirectory;
    // cout << "executable path: ";
    // cin >> executablePath;

    cout << "running test cases..." << endl;
    int i = 0;
    for (const auto &entry : fs::directory_iterator(testCaseDirectory))
    {
        string path = entry.path().string();
        cout << "running testcase #" << i << ": " << path << endl;
        string name = path.substr(testCaseDirectory.size() + 1);

        string testcaseInputPath = path;
        string testcaseOutputPath = outputDirectory + "/" + name;

        string executeCommand = executablePath + " <" + testcaseInputPath + " >" + testcaseOutputPath;
        cout << executeCommand << endl;

        ofstream outfile;
        outfile.open(testcaseOutputPath);
        outfile << "";
        outfile.close();

        const char *c = executeCommand.c_str();

        int code = system(c);

        cout << "CODE: " << code << endl;

        ++i;
    }

    return 0;
}