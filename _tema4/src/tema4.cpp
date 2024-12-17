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

    FExplorer(const FExplorer& other)
        : fileName(other.fileName), file(new fstream(other.fileName, ios::in | ios::out)) {
        if (!file->is_open()) {
            throw runtime_error("Fail in copy constructor: " + fileName);
        }
    }

    FExplorer& operator=(FExplorer other) {
        if (this != &other) {
            if (file->is_open()) {
                file->close();
            }
            file = std::move(other.file);
        }
        return *this;
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

        FExplorer file2 = file1;
        file2.writeToFile("3");
        file2.readFromFile();

        FExplorer file3("ex2.txt", ios::in);
        file3 = file1;
        file3.readFromFile();

    return 0;
}
