#include <QCoreApplication>
#include <bitset>
#include <iostream>
#include <cstddef>
#include <testreader.h>

using namespace std;

int solution(int N)
{
    bitset<32> bs(N);
    string bits = bs.to_string();

    bool bitStart = false;
    int tempMax = 0;
    int maxZeroBit = 0;
    for( size_t pos = 0; pos < bits.length(); pos ++)
    {
        char bit = bits.at( pos);

        if( ! bitStart && bit != '0')
            bitStart = true;

        if( bitStart)
        {
            if( bit == '0')
                tempMax ++;
            else
            {
                if( maxZeroBit < tempMax)
                    maxZeroBit = tempMax;

                tempMax = 0;
            }
        }
    }

    return maxZeroBit;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestReader tr;
    if( tr.m_TestFileExists)
    {
        vector< pair< int, int> > testsVec = tr.GetTestVec();

        for( size_t i = 0; i < testsVec.size(); i ++)
        {
            const pair< int, int> test = testsVec.at( i);
            const int maxZeros = solution( test.first);
            const string isGoodStr = maxZeros == test.second ? "Good" : "Bad";

            cout << "Test " << i << ": " << isGoodStr << " " << test.first << " - " << maxZeros << endl;
        }
    }

    return a.exec();
}

