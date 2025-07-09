#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateCode() {
    string code;
    code += 'A' + rand() % 26;
    code += 'A' + rand() % 26;
    code += '-';
    code += '0' + rand() % 10;
    code += '0' + rand() % 10;
    return code;
}

string generateSurname() {
    string surnames[] = {
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов", "Попов"
    };
    return surnames[rand() % (sizeof(surnames)/sizeof(surnames[0]))];
}

string generateTitle() {
    string titles[] = {
        "Искусственный интеллект", "Квантовые вычисления", "Генетика",
        "Биотехнологии", "Робототехника", "Нейросети"
    };
    return titles[rand() % (sizeof(titles)/sizeof(titles[0]))];
}

int generateID() {
    return 40000 + rand() % 10000;
}

void generateFiles(int count) {
    ofstream fileF("F.txt");
    ofstream fileG("G.txt");

    map<string, string> codeToTitle;

    for (int i = 0; i < count; i++) {
        int id = generateID();
        string surname = generateSurname();
        string code = generateCode();

        if (codeToTitle.find(code) == codeToTitle.end()) {
            string title = generateTitle();
            codeToTitle[code] = title;
            fileG << code << " " << title << "\n";
        }

        fileF << id << " " << surname << " " << code << "\n";
    }

    fileF.close();
    fileG.close();
}

void createHFile() {
    ifstream fileF("F.txt");
    ifstream fileG("G.txt");
    ofstream fileH("H.txt");

    if (!fileF || !fileG) {
        cout << "Не удалось открыть входные файлы." << endl;
        return;
    }

    map<string, string> codeToTitle;
    string code, titlePart, title;

    while (fileG >> code) {
        getline(fileG, titlePart); 
        codeToTitle[code] = titlePart.substr(1); 
    }

    string id, surname;
    while (fileF >> id >> surname >> code) {
        if (codeToTitle.find(code) != codeToTitle.end()) {
            title = codeToTitle[code];
            fileH << id << " " << surname << " " << code << " " << title << "\n";
        }
    }

    fileF.close();
    fileG.close();
    fileH.close();
}

void printFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    cout << "\nСодержимое файла " << filename << ":\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void run() {
    srand(time(0));
    int count;
    cout << "Введите количество студентов: ";
    cin >> count;

    generateFiles(count);
    createHFile();

    printFile("F.txt");
    printFile("G.txt");
    printFile("H.txt");
}

int main() {
    run();
    return 0;
}
