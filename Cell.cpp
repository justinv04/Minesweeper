#include "Cell.h"

Cell::Cell()
{
    keyValue = 0;
    boardValue = 0;
    correctValue = true;
    possibleValues = {};
    notedValues = {};
}

void Cell::setKeyVal(int val)
{
    keyValue = val;
}

void Cell::setBoardVal(int val)
{
    boardValue = val;
    boardValue == keyValue ? correctValue = true : correctValue = false;
}

int Cell::getKeyVal()
{
    return keyValue;
}

int Cell::getBoardVal()
{
    return boardValue;
}

vector<int> Cell::getPVals()
{
    return possibleValues;
}

vector<int> Cell::getNVals()
{
    return notedValues;
}

bool Cell::isCorrectValue()
{
    return correctValue;
}