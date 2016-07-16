#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    int unpaired = 0;
    for( int val : A)
        unpaired ^= val;

    return unpaired;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> myVec {9, 3, 9, 3, 9, 3, 7, 9, 3};

    cout << solution(myVec);

    return a.exec();
}

