#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Array {
public:
    T* A;
    int size;
    int length;

    Array(int size);
    void display();
    void append(T x);
    void insert(int index, T x);
    T deleteElement(int index);
    int linearSearch(T key);
    ~Array();
};

template <class T>
Array<T>::Array(int size) {
    A = new T[size];
    this->size = size;
    length = 0;
}

template <class T>
Array<T>::~Array() {
    delete []A;
}

template <class T>
void Array<T>::display() {
    cout << "\nElements are\n";
    for (int i = 0; i < length; ++i) {
        cout << A[i] << " ";
    }
}

template <class T>
void Array<T>::append(T x) {
    if (length < size)
        A[length++] = x;
}

template <class T>
void Array<T>::insert(int index, T x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; --i)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::deleteElement(int index) {
    T temp = 0;
    if (index >= 0 && index < length) {
        temp = A[index];
        for (int i = index; i < length - 1; ++i) {
            A[i] = A[i + 1];
        }
        length--;
    }
    return temp;
}

template <class T>
int Array<T>::linearSearch(T key) {
    for (int i = 0; i < length; ++i) {
        if (key == A[i]) {
            if (i == 0)
                return 0;
            swap(A[i], A[i - 1]);
            return i-1;
        }
    }
    return -1;
}
int main()
{
    int size{};
    cout << "Enter size of an array" << endl;
    cin >> size;
    Array<int> arr(size);
    int n{};
    cout << "Enter number of numbers" << endl;
    cin >> n;
    cout << "Enter all elements" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr.A[i];
    }
    arr.length = n;
    arr.display();
    arr.append(5);
    arr.display();
    arr.insert(0, 10);
    arr.display();
    arr.deleteElement(0);
    arr.display();
    cout << arr.linearSearch(5) << endl;
    return 0;
}
