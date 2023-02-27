#include "Array.h"

template <typename T>Array<T>::Array(int length) : _length{ length }
{
    if (length <= 0) {
        cout<<"Размер массива не может быть равным или меньше 0! \n";
    }
    if (length > 0)
        _array = new T[length] {};
}

template <typename T>Array<T>::Array(const Array& a)
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < _length; ++index)
        _array[index] = a._array[index];
}

template <typename T>Array<T>::~Array()
{
    //std::cout << "\nМассив удален!\n";
    delete[] _array;
}

template <typename T> void Array<T>::erase()
{
    delete[] _array;

    _array = nullptr;
    _length = 0;
}

template <typename T> T& Array<T>::operator[](int index)
{
    if (index < 0 || index >= _length)
        cout<<"Выход за пределы массива!, вы выбрали некорректный индекс \n";

    return _array[index];
}

template <typename T> void Array<T>::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    _array = new T[newLength];
    _length = newLength;
}

template <typename T> void Array<T>::resize(int newLength)
{
    if (newLength == _length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    T* data{ new T[newLength] };

    if (_length > 0)
    {
        int elementsToCopy{ (newLength > _length) ? _length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = _array[index];
    }

    delete[] _array;

    _array = data;
    _length = newLength;
}

template <typename T> Array<T>& Array<T>::operator=(const Array& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < _length; ++index)
        _array[index] = a._array[index];

    return *this;
}

template <typename T> void Array<T>::insertBefore(T value, int index)
{
    if (index < 0 || index > _length)
        cout << "Выход за пределы массива!, в массиве нет позиции с таким инексом \n";

    T* data{ new T[_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _array[before];

    data[index] = value;

    for (int after{ index }; after < _length; ++after)
        data[after + 1] = _array[after];

    delete[] _array;
    _array = data;
    ++_length;
}

template <typename T> void Array<T>::remove(int index)
{
    if (index < 0 || index >= _length)
        cout << "Выход за пределы массива!, в массиве отсутствует элемент с таким индексом \n";

    if (_length == 1)
    {
        erase();
        return;
    }

    T* data{ new T[_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _array[before];

    for (int after{ index + 1 }; after < _length; ++after)
        data[after - 1] = _array[after];

    delete[] _array;
    _array = data;
    --_length;
}

template <typename T> void Array<T>::showArray()
{
    cout << "\n";
    for (int i = 0; i < _length; i++) {
        if (i < _length - 1)
            cout << _array[i] << ",";
        else
            cout << _array[i] << ";\n";
    }
}

template <typename T> T Array<T>::findElement(T num)
{
    for (int i = 0; i < _length; i++) {
        if (_array[i] == num)
        {
            cout << "Элемент со значением: " << num << ", распологается по индексу: " << i << endl;
            return i;
        }
    }
    cout << "В массиве отсутствует элемент со значением: " << num << endl;
    return -1;
}