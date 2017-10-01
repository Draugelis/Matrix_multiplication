#include <iostream>
using namespace std;
const int max_xy = 20;
struct matrix
{
    int m;
    int n;
    int numbers[max_xy][max_xy];
} A_mac, B_mac, C_mac;
bool match(matrix A_mac, matrix B_mac)
{
    if(A_mac.n == B_mac.m) return true;
    else return false;
}
matrix C_calculation(matrix A_mac, matrix B_mac)
{
    int i_max = A_mac.n;
    C_mac.m = A_mac.m;
    C_mac.n = B_mac.n;
    for(int y = 0; y < C_mac.m; y++)
    {
        for(int x = 0; x < C_mac.n; x++)
        {
            int temp(0);
            for(int i = 0; i < i_max; i++)
            {
                temp += (A_mac.numbers[y][i] * B_mac.numbers[i][x]);
            }
            C_mac.numbers[y][x] = temp;
        }
    }
}
void input()
{
    cout << "A matrix:\n";
    for(int y = 0; y < A_mac.m; y++)
    {
        for(int x = 0; x < A_mac.n; x++)
        {
            cout << "a( "<< y + 1 << " ; " << x + 1 << " )\n> ";
            cin >> A_mac.numbers[y][x];
        }
    }
    cout << "\nB matrix:\n";
    for(int y = 0; y < B_mac.m; y++)
    {
        for(int x = 0; x < B_mac.n; x++)
        {
            cout << "b( "<< y + 1 << " ; " << x + 1 << " )\n> ";
            cin >> B_mac.numbers[y][x];
        }
    }
}
void output()
{
    for(int y = 0; y < C_mac.m; y++)
    {
        for(int x = 0; x < C_mac.n; x++)
        {
            cout << C_mac.numbers[y][x] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    start_of_code:
    cout << "A matrix:\nm: ";
    cin >> A_mac.m;
    cout << "n: ";
    cin >> A_mac.n;
    cout << "\nB matrix:\nm: ";
    cin >> B_mac.m;
    cout << "n: ";
    cin >> B_mac.n;
    char progress;
    if(match(A_mac, B_mac) == true)
    {
        magic:
        input();
        C_calculation(A_mac, B_mac);
        cout << endl;
        output();
        cout << "\nWant to continue working? [Y/N]\n> ";
        cin >> progress;
        if(progress == 'Y' || progress == 'y')
                goto start_of_code;
    }
    else
    {
        cout << "\nERROR";
        cout << "\nWant to continue working? [Y/N]\n> ";
        cin >> progress;
        if(progress == 'Y' || progress == 'y')
                goto start_of_code;
    }
    cout << "\n\nBye!\n";
    return 0;
}
