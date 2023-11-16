/*!
 *
 * \file problem2.cpp
 * \brief Implement Mini-Vim
 *
 * Mini-Vim
 *
 * Implement Mini-Vim that works on given commands.
 *
 * Like real Vim, Mini-Vim also has three different modes: Normal, Insert and EX-mode.
 * Switching between modes is done using specific commands that allow files to be written and saved.
 * See the pdf for more details.
 *
 * In the input file, the first row is the number of iterations.
 * Starting from the second row, each line represents the command to be executed.
 *
 * The types of commands are as follows.
 * "i", "a", "o" - Switch from "Normal Mode" to "Insert mode"
 * ":"           - Switch from "Normal Mode" to "EX-mode"
 * "\esc"        - Switch from "Insert Mode" to "Normal mode"
 * "\enter"      - Switch from "EX-mode" to "Normal mode"
 * "w"           - Save the buffer to the disk when in "EX-mode" (hint: FileManager::save())
 * "q"           - Clear the buffer of the file and return to the most recent saved state
 *                 when in "EX-mode" (hint: FileManager::clear())
 * Some Words... - Write these words into the buffer when in "Insert" mode (hint: FileManager::write())
 *
 * The output file should be the final result of the file.
 *
 * It is recommended that you write your own code on the lines provided,
 * but you are free to do so by modifying the skeleton code.
 */

#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const string InputFilePath = "input2.txt";
const string OutputFilePath = "output2.txt";
//---------------------------------------------------------------------------
class FileManager
{
private:
    /// The output file's name
    ofstream &Ofs;
    /// The buffer of the output file to be saved.
    string Buffer = "";

public:
    /// The constructor
    explicit FileManager(ofstream &InOfs) : Ofs{InOfs} {}

    /// Write new content to file manager's buffer
    void write(const string &Content);
    /// Save the contents to the disk (create "output2.txt")
    void save();
    /// Clear the current buffer
    void clear();
};
//---------------------------------------------------------------------------
class MiniVimEditor
{
private:
    /// The Normal mode state of Mini-Vim
    static const int NORMAL_MODE = 0;
    /// The Insert mode state of Mini-Vim
    static const int INSERT_MODE = 1;
    /// The Ex-mode state of Mini-Vim
    static const int EX_MODE = 2;

    /// The File manager to deal with
    FileManager &FMgr;
    /// The current mode state
    int Mode = NORMAL_MODE;
    /// The previous mode state
    int LastMode = NORMAL_MODE;

public:
    /// The constructor
    explicit MiniVimEditor(FileManager &InFMgr) : FMgr{InFMgr} {}
    /// Run editor by parsing given command
    void run(const string &Command);

    void SwitchMode(int TargetMode)
    {
        LastMode = Mode;
        Mode = TargetMode;
    }
};
//---------------------------------------------------------------------------
int main()
{
    ifstream Ifs{InputFilePath};
    if (Ifs.fail())
    {
        cerr << "Failed to open input file.\n";
        return 0;
    }
    ofstream Ofs{OutputFilePath};

    // Get the number of iterations
    int IterCount;
    Ifs >> IterCount;

    // There's still '\n' left, so to use getline() this code is needed.
    string Tmp;
    getline(Ifs, Tmp);

    FileManager FMgr{Ofs};
    MiniVimEditor Editor{FMgr};

    // Run Mini-Vim editor
    for (int I = 0; I < IterCount; ++I)
    {
        string Command;
        getline(Ifs, Command);
        cout << "command: " << Command << endl;
        Editor.run(Command);
    }

    return 0;
}
//---------------------------------------------------------------------------
void FileManager::write(const string &Content)
{
    Buffer += Content;
}
//---------------------------------------------------------------------------
void FileManager::save()
{
    Ofs << Buffer;
}
//---------------------------------------------------------------------------
void FileManager::clear()
{
    Buffer = "";
}
//---------------------------------------------------------------------------
void MiniVimEditor::run(const string &Command)
{
    if (Mode == NORMAL_MODE)
    {
        if (Command == "i" || Command == "o" || Command == "a")
        {
            SwitchMode(INSERT_MODE);
        }
        else if (Command == ":")
        {
            SwitchMode(EX_MODE);
        }
        else
        {
            // ignore.
        }
    }
    else if (Mode == INSERT_MODE)
    {
        if (Command == "\\esc")
        {
            SwitchMode(NORMAL_MODE);
        }
        else
        {
            // write "command" to buffer
            this->FMgr.write(Command);
        }
    }
    else if (Mode == EX_MODE)
    {
        if (Command == "\\enter")
        {
            SwitchMode(NORMAL_MODE);
        }
        else if (Command == "w")
        {
            // save file to disk as output2.txt
            this->FMgr.save();
        }
        else if (Command == "q")
        {
            this->FMgr.clear();
            SwitchMode(LastMode);
        }
    }
}
//---------------------------------------------------------------------------
