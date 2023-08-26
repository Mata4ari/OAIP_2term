#include <iostream>
#include <string>
using namespace std;

void permutations(unsigned *A,unsigned n,int pos = 0)
{
    if (pos >= n-1)
    {
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << endl;
        return;
    }
    else
    {
        for (int i = pos; i < n; ++i)
        {
            swap(A[i], A[pos]);
            permutations(A,n, pos + 1);
            swap(A[i], A[pos]);
        }
    }
}

int main()
{
    unsigned n;
    cin >> n;
    unsigned* A = new unsigned[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    permutations(A,n);

    cout << endl;
    return 0;
}