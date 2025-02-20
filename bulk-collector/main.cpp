#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string line, dateTime;
ifstream sourceFile, dateFile;
ofstream destinationFile;

void getDate(void) {
    system("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe Get-Date -Format 'yyyy-MM-dd HH:mm:ss' > C:\\tmp\\datetime.txt");
    dateFile.open("C:\\tmp\\datetime.txt");
    stringstream buffer;
    buffer << dateFile.rdbuf();
    dateTime = buffer.str();
    dateFile.close();
}

void extractSysInfo(void) {
    system("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe -NoLogo Get-Process > C:\\tmp\\log.txt");
}

void writeToFile(void) {
    sourceFile.open("C:\\tmp\\log.txt");
    destinationFile.open("extraction.log");
    destinationFile << "COLLECTED AT " << dateTime << endl << "------------------------------------------------------------------------" << endl;
    if (sourceFile && destinationFile) {
        while (getline(sourceFile, line)) {
            destinationFile << line << endl;
        }
    }
    sourceFile.close();
    destinationFile.close();
    cout << "Program run successful" << endl;
}

int main(void) {
    getDate(); // Get current date and time
    extractSysInfo(); // Extraction of current system running programs
    writeToFile(); // Writing of current system running programs to extraction.log
    cout << "Exiting...";
    cin.ignore(); // To keep window from closing
    return 0;
}
