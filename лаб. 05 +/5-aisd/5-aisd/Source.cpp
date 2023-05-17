#include <iostream>
#include <stack>
#define c1 stk.push(')'); break;
#define s1 stk.push(']'); break;
#define c2 stk.push('}'); break;
#define m1 stk.push('>'); break;

using namespace std;

bool skodichki(string s)
{
    stack <char> stk; // созд стeка
    for (char symbol : s) {
        switch (symbol) {
           
        case '(': c1;
        case '[': s1;
        case '{': c2;
        case '<': m1;
        case ')':
        case ']':
        case '}':
        case '>':
            if (stk.empty() || stk.top() != symbol) { //проверка 
                return false;
            }
            stk.pop(); //удал€ем верхний 
            break;
        default:
            break;
        }
    }
    return stk.empty();
}

bool proverka(string s) { //проверка 
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '<' || s[i] == '>')
        {
            return true;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    string s;
    cout << "¬ведите строку: "; 
    cin >> s;
    proverka(s);
    if (proverka(s) == true)
    {
        skodichki(s);
        if (skodichki(s) == true)
        {
            cout << "\n верно";
        }
        else
        {
            cout << "\n ошибка";
        }
    }
    else
    {
        cout << "\nошибка";
    }
}