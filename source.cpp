#include <iostream>
#include <string>
using namespace std;

void swap(string *a, string *b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    string a, b;

    cin >> a >> b;

    if (a.length() > b.length())
        swap(a, b);

    string **mul = new string*[a.length()];
    for (int i = 0; i < a.length(); i++)
        mul[i] = new string[a.length()+b.length()];

    for (int i = 0; i < a.length(); i++) 
        for (int j = 0; j < a.length()+b.length(); j++)
            mul[i][j] = '0';

    int res = 0;
    for (int i = a.length()-1; i >= 0; i--) {
        int j;
        for (j = b.length()-1; j >= 0; j--) {
            int x = (int)(a[i]-48) * (int)(b[j]-48) + res;
            res = x/10;
            x %= 10;
            mul[i][j+i+1] = (char)(x + 48);
        }
        mul[i][j+1+i] = (char)(res+48);
    }

    char result[a.length()+b.length()+1];
    for (int i = 0; i < a.length()+b.length(); i++)
        result[i] = '0';
    res = 0;
    for (int i = a.length()+b.length()-1; i >= 0; i++) {
        int x = 0;
        for (int j = 0; j < a.length(); j++) {
            string m = mul[i][j];
            char s = m[0];
            x += (int)(s - 48) + res;
        }
        res = x/10;
        x %= 10;
        result[i] = char(x+48);
    }
        
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < a.length()+b.length(); j++)
            cout << mul[i][j] << " ";
        cout << endl;
    }

    cout << endl << result;
    return 0;
}