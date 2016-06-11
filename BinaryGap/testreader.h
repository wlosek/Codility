#ifndef TESTREADER_H
#define TESTREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class TestReader
{
public:
    TestReader();

    bool                        m_TestFileExists;
    vector< pair< int, int> >      GetTestVec() const;

private:
    vector< pair< int, int> >      m_TestVec;

    void                        ReadTests();
};

#endif // TESTREADER_H
