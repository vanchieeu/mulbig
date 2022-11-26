#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char a[1001], b[1001];

    cin >> a >> b;
    if (strcmp(a, "0") == 0 || strcmp(b, "0") == 0) {
        cout << 0;
        return 0;
    }

    char **mul = new char*[strlen(a)];
    for (int i = 0; i < strlen(a); i++)
        mul[i] = new char[strlen(a)+strlen(b)];

    for (int i = 0; i < strlen(a); i++)
        for (int j = 0; j < strlen(a)+strlen(b); j++)
            mul[i][j] = '0';

    int res = 0;
    for (int i = strlen(a)-1; i >= 0; i--) {
        int j;
        for (j = strlen(b)-1; j >= 0; j--) {
            int x = (int)(a[i]-48) * (int)(b[j]-48) + res;
            res = x/10;
            x %= 10;
            mul[i][j+i+1] = (char)(x + 48);
        }
        mul[i][j+1+i] = (char)(res+48);
        res = 0;
    }

    char *result = new char[strlen(a)+strlen(b)];
    for (int i = strlen(a)+strlen(b)-1; i >= 0; i--) {
        int x = 0;
        for (int j = 0; j < strlen(a); j++) {
            x += (int)(mul[j][i] - 48);
        }
        x += res;
        res = x/10;
        x %= 10;
        result[i] = (char)(x+48);
    }

    if (result[0] == '0') {
        for (int i = 1; i < strlen(a)+strlen(b); i++)
            cout << result[i];
            return 0;
    }
    cout << result;
    return 0;
}