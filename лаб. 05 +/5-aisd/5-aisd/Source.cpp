#include <iostream>
#include <stack>
#define c1 stk.push(')'); break;
#define s1 stk.push(']'); break;
#define c2 stk.push('}'); break;
#define m1 stk.push('>'); break;

using namespace std;

bool skodichki(string s)
{
    stack <char> stk; // ���� ��e��
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
            if (stk.empty() || stk.top() != symbol) { //�������� 
                return false;
            }
            stk.pop(); //������� ������� 
            break;
        default:
            break;
        }
    }
    return stk.empty();
}

bool proverka(string s) { //�������� 
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
    cout << "������� ������: "; 
    cin >> s;
    proverka(s);
    if (proverka(s) == true)
    {
        skodichki(s);
        if (skodichki(s) == true)
        {
            cout << "\n �����";
        }
        else
        {
            cout << "\n ������";
        }
    }
    else
    {
        cout << "\n������";
    }
}