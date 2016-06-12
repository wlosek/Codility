#include <QCoreApplication>

#include <vector>
#include <cstddef>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    if( A.size() > 0)
        for( int i = 0; i < K; i ++)
        {
            int lastVal = A.at( A.size() - 1);

            for( int j = A.size() - 2; j >= 0; j --)
                A.at( j + 1) = A.at( j);

            A.at( 0) = lastVal;
        }

    return A;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> vec = { 3, 5, 22 ,9};
    const int iter = 3;

    cout << "Start vector: ";
    for( int elem : vec)
        cout << elem << " ";

    cout << "- rotation times: " << iter << " ";
    solution( vec, 3);
    cout << "- result vector: ";
    for( int elem : vec)
        cout << elem << " ";

    return a.exec();
}

