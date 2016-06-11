#include "testreader.h"

static const string FileNameStr( "tests.txt");

TestReader::TestReader()
{
    m_TestFileExists = false;

    ReadTests();
}

vector< pair< int, int> > TestReader::GetTestVec() const
{
    return m_TestVec;
}

void TestReader::ReadTests()
{
    ifstream file;
    file.open( FileNameStr.c_str());

    if( file.good())
        m_TestFileExists = true;

    while( true)
    {
        int number, maxZeroBits;
        string dash;

        file >> number >> dash >> maxZeroBits;
        if( ! dash.empty())
        {
            pair<int, int> test;
            test.first = number;
            test.second = maxZeroBits;
            m_TestVec.push_back( test);
        }
        else
            break;
    }
}
