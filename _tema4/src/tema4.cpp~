#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FExplorer {
private:
    string fileName; 
    fstream* file;   

public:
    FExplorer(const string& fName, ios::openmode mode)
        : fileName(fName), file(new fstream(fName, mode)) {
        if (!file->is_open()) {
            throw runtime_error("Failed to open file: " + fileName);
        }
        cout << "FExplorer: Opened file \"" << fileName << "\"\n";
    }

    ~FExplorer() {
        if (file) {
            if (file->is_open()) {
                file->close();
                cout << "FExplorer: Closed file \"" << fileName << "\"\n";
            }
            delete file;
        }
    }

    void writeToFile(const string& data) {
        if (file && file->is_open()) {
            *file << data << "\n";
            cout << "FExplorer: Wrote in \"" << fileName << "\"\n";
        } else {
            throw std::runtime_error("Can't write");
        }
    }

    void readFromFile() {
        if (file && file->is_open()) {
            string line;
            cout << "FExplorer: Read file \"" << fileName << "\":\n";
            while (getline(*file, line)) {
                cout << line << "\n";
            }
            file->clear();
            file->seekg(0, ios::beg);
        } else {
            throw runtime_error("Can't read");
        }
    }
};

int main() {
        FExplorer file1("ex1.txt", ios::in);
        file1.writeToFile("1");
        file1.writeToFile("2");
        file1.readFromFile();

    return 0;
}
