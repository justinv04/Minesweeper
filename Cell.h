#ifndef CELL_H
#define CELL_H

#include <vector>

using std::vector;

class Cell
{
    private:
        int keyValue, boardValue;
        vector<int> possibleValues, notedValues;
        bool correctValue;

    public:
        Cell();
        void setKeyVal(int val);
        void setBoardVal(int val);
        int getKeyVal();
        int getBoardVal();
        vector<int> getPVals();
        vector<int> getNVals();
        bool isCorrectValue();
};

#endif