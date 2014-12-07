/* 
 * File:   Sort.h
 * Author: Kevin Vo
 *
 * Created on December 6, 2014, 11:16 AM
 */

#ifndef SORT_H
#define	SORT_H
using namespace std;
//******************************************************************************
//Template + Dynamic Array Example
//Accepts value to sort it and then display
//******************************************************************************

template <class T>
class SortableVector{
    private:
        T *ptrArray;//Points to the array
        int arraySize;
        void memError();//Handles memory allocation errors
        void subError();//Handles subscripts that are out of range
        void quickSort(T *, int, int);//Uses quicksort algorithm to sort
        //Obtains mid. value so that # can be sorted around it
        int partition(T *, int, int);
    public:
        SortableVector(){ptrArray = 0; arraySize = 0;}
        SortableVector(int);
        SortableVector(const SortableVector &);
        ~SortableVector();
        int size() const{return arraySize;}
        T getValue(int position);
        void sorter();
        T &operator[] (const int &);
};

    
template <class T>
//Defines the size of array and allocates memory while checking for neg. values
SortableVector<T>::SortableVector(int size){
    //set array size and allocate memory
    arraySize = size;
    try{
        ptrArray = new T[size];
    }
    catch (bad_alloc){
        memError();
    }

    for(int count = 0; count < arraySize; count++){
        *(ptrArray + count) = 0;
    }
}

template <class T>
SortableVector<T>::SortableVector(const SortableVector &c){
    arraySize = c.arraySize;
    ptrArray = new T [arraySize];
    if(ptrArray == 0){memError();}
    for(int count = 0; count < arraySize; count++){
        *(ptrArray + count) = *(c.ptrArray + count);
    }
}

template <class T>
    SortableVector<T>::~SortableVector(){
        if(arraySize > 0){delete [] ptrArray;}
}

template <class T>
//Displays and ends the program when there's a negative value
void SortableVector<T>::memError(){
    cout<<"Error: The amount entered must be a positive.\n";
    exit(EXIT_FAILURE);}

//Displays and ends the program when the subscript is out of range
template <class T>
void SortableVector<T>::subError(){
    cout<<"Error: The subscript is out of range.\n";
    exit(EXIT_FAILURE);}

//Gives the array values and checks if the subscript is in range.
template <class T>
T SortableVector<T>::getValue(int elem){
    if(elem < 0 || elem >= arraySize){subError();}
return ptrArray[elem];}

template <class T>
T &SortableVector<T>::operator[](const int &elem){
    if(elem < 0 || elem >= arraySize){subError();}
return ptrArray[elem];}

template <class T>
void SortableVector<T>::sorter(){ quickSort(ptrArray, 0, arraySize); }

//quicksort uses quicksort algorithm to sort the values
template <class T>
void SortableVector<T>::quickSort(T *ptrArray, int start, int end){
    int middle;
    if(start < end){
        middle = partition(ptrArray, start, end);
        quickSort(ptrArray, start, middle);
        quickSort(ptrArray, middle+1, end);
    }
return;}

    //Selects and return the middle value
    template <class T>
    int SortableVector<T>::partition(T *ptrArray, int start, int end){
        T arrStart = ptrArray[start], holder;
        int com = (start - 1), mid = (end + 1);

        do{
            do{ mid--; }while (arrStart > ptrArray[mid]);
            do{ com++; }while (arrStart < ptrArray[com]);
            if(com < mid){
                holder = ptrArray[com];
                ptrArray[com] = ptrArray[mid];
                ptrArray[mid] = holder;
            }
        }while(com < mid);
return mid;}

#endif	/* SORT_H */