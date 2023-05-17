#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;
class hashTable {
public:
    struct hashNode {
        int phone{};
        string name{};

        hashNode(int ph, string* nm)
            : phone{ ph }, name{ *nm }
        {}

    private:
        hashNode* next{};
        friend hashTable;
    };
private:
    size_t m_length{};
    vector<hashNode*> m_data{};

    int hashIndex(int phone) {
        return phone % m_length;
    }
public:
    hashTable(size_t length) : m_length{ length } {
        m_data.resize(length);
    }

    void resize(size_t length) {
        m_length = length;
        m_data.resize(length);
    }

    void addhash(int phone, string name) {
        int id = hashIndex(phone);
        hashNode* p = m_data[id];
        if (!p) {
            m_data[id] = new hashNode{ phone, &name };
            return;
        }

        while (p->next) p = p->next;
        p->next = new hashNode{ phone, &name };

        return;
    }

    void deletehash(int phone) {
        int id = hashIndex(phone);
        auto el = m_data[id];

        if (el->phone == phone) {
            m_data[id] = el->next;
            delete el;
            return;
        }

        while (el->next && el->next->phone != phone) el = el->next;
        if (el->next) {
            auto temp{ el->next };
            el->next = el->next->next;
            delete temp;
        }
        cout << "удалено";
    }

    void searchhash(int phone) {
        int start_time = clock();

        int id = hashIndex(phone);
        hashNode* p = m_data[id];

        while (p && p->phone != phone)
            p = p->next;
        int end_time = clock();
        cout << "найдено: " << p->name << " время: " << end_time - start_time << "мс\n";
    }

    void outputtable() {
        int counter = 0;
        for (auto el : m_data) {
            counter++;
            if (!el)
                continue;

            cout << counter << " - " << el->phone << " имя: " << el->name << '\n';
            while ((el = el->next))
                cout << "<" << el->phone << " имя: " << el->name << ">\n";
        }
    }
};

int menu() {
    setlocale(LC_ALL, "rus");
    int choice;
    cout << "1. добавить\n";
    cout << "2. удалить\n";
    cout << "3. найти\n";
    cout << "4. вывести\n";
    cout << "5. выйти\n";
    cout << "ваш выбор: ";
    cin >> choice;
    return choice;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    cout << "выберите размер: 16 или 32 \n";
    size_t size;
    cin >> size;
    hashTable table = size;

    for (;;) {
        int phone;
        int choice = menu();

        if (choice < 0 || choice > 5) { cout << "ошибка!!!!!!!!!!!!!!!!!!!!!!!!"; continue; }

        switch (choice) {
        case 1: {
            int phone;
            cout << "\nтелефон: ";
            cin >> phone;
            cin.ignore();
            cout << "\nимя: ";
            string name;
            getline(cin, name);
            table.addhash(phone, name);
            break;
        }
        case 2:
            cin >> phone;
            table.deletehash(phone);
            break;
        case 3:
            cin >> phone;
            table.searchhash(phone);
            break;
        case 4:
            table.outputtable();
            break;
        case 5:
            return 0;
        }
    }
}