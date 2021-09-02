/******************************************************************************
* THIS IS A WORK IN PROGRESS.
*
* Author:   Thor Lang
* Email:    thorseph4@gmail.com
* Label:    A04
* Title:    Commenting Code
* Course:   CMPS 2043
* Semester: Fall 2021
*
* Description:
*   - Apply proper comments to the source code Dr. Griffin provided, using the
*       proper structure and procedures listed in the Comments resource in his
*       Resources repository. 
* 
* Usage:
*   - This assignment will serve as practice and another reference for future
*       assignments.
*
* Files:
*           main.cpp    : driver program
******************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class creates array queue that tracks its front and back.  It can
 *          track its size, including letting the user know when it fills up,
 *          be manually initialized as well as automatically initialized to a
 *          size of 10, and loads into its rear while popping from the front.
 * 
 * Public Methods:
 *              CircularArrayQue()
 *              CircularArrayQue(int size)
 *      void    Push(int item)
 *      int     Pop()
 * 
 * Private Methods:
 *      void    init(int size = 0)
 *      bool    Full()
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */


class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;

    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};


/**
* Public/Private/Protected : function_name
* 
* Description:
*      Describe the functions purpose
* 
* Params:
*      - list params
*      - one per line
*      - with return type
*      - and one line description
* 
* Returns:
*      - what does this function return (including the type)?
*/


ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */

int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}