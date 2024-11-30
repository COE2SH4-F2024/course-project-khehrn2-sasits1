#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0; // initialize listSize
    arrayCapacity = ARRAY_MAX_CAP; // initialize the number of array elements to 200

    aList = new objPos[ARRAY_MAX_CAP]; // allocate an array list on the heap
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // deallocate heap member (an array, need square brackets!)
}

int objPosArrayList::getSize() const
{
    return listSize; // returns the size of the list
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1]; // shifting towards the tail, can do this because of copy assignment operator!
    }
    aList[0].setObjPos(thisPos);

    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }
    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{

    if(listSize > 0)
    {
        for(int i = 0; i < listSize - 1; i++)
        {
            aList[i] = aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if(listSize > 0)
    {
        listSize--; // remove the last element of the list (e.g. the tail) aka lazy deletion
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0]; // return the head element
}

objPos objPosArrayList::getTailElement() const
{   
    return aList[listSize - 1]; // return the tail element
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0) // index cannot be negative
    {
        index = 0;
    }

    if(index > listSize)
    {
        return aList[listSize];
    }

    return aList[index]; // return the element at the specified index  
}