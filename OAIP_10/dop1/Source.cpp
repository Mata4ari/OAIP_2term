#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void permutations(unsigned* A, unsigned n,ofstream &f, int pos = 0)
{
    if (pos >= n - 1)
    {
        if(A[1]!=0)
        {
            for (int i = 1; i < n; i++)
            {
                f << A[i];
            }
            f << endl;
        }
        return;
    }
    else
    {
        for (int i = pos; i < n; ++i)
        {
            swap(A[i], A[pos]);
            permutations(A, n,f, pos + 1);
            swap(A[i], A[pos]);
        }
    }
}

int main()
{
    unsigned n;
    cin >> n;
    unsigned* A = new unsigned[n];
    for (int i = 0; i <= n; i++)
        A[i] = i;

    ofstream f("A.txt");
    permutations(A, n+1,f);
    f.close();
    cout << endl;
    return 0;
}