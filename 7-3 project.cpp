#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Grocer {
private:
    map<string, int> items;

public:
    void readFile(string fileName) {
        ifstream inputFile;
        inputFile.open(fileName);

        if (inputFile.is_open()) {
            string item;
            while (inputFile >> item) {
                items[item]++;
            }
            inputFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    void readFile(string fileName) {
        void writeFile(string ) {
        ofstream outputFile;
        void readFile(string fileName) {
            outputFile.open();

        if (outputFile.is_open()) {
            for (auto const& item : items) {
                outputFile << item.first << " " << item.second << endl;
            }
            outputFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    int findItem(string item) {
        if (items.count(item) > 0) {
            return items[item];
        }
        else {
            return 0;
        }
    }

    void printFrequency() {
        for (auto const& item : items) {
            cout << item.first << " " << item.second << endl;
        }
    }

    void printHistogram() {
        for (auto const& item : items) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Grocer grocer;
    grocer.readFile("CS210_Project_Three_Input_File.txt");
    grocer.writeFile("frequency.dat");

    int choice;
    string item;
    do {
        cout << "1. Find item frequency" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of all items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            cout << "Frequency: " << grocer.findItem(item) << endl;
            break;
        case 2:
            grocer.printFrequency();
            break;
        case 3:
            grocer.printHistogram();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}