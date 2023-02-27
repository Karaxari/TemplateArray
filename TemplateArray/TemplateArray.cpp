#include "array.cpp"

int main()
{
    setlocale(LC_ALL, "rus");

    Array<int> arr_1(10);
    for (int i = 0; i < arr_1.getLength(); i++) {
        arr_1[i] = i;
    }
    arr_1.showArray();

    Array<double> arr_2(10);
    for (int i = 0; i < arr_1.getLength(); i++) {
        arr_2[i] = i * 3.14;
    }
    arr_2.showArray();
    

    Array<char> arr_3(10);
    for (int i = 0; i < arr_1.getLength(); i++) {
        arr_3[i] = i + 70;
    }
    arr_3.showArray();

    Array<char> arr_4(20);
    cout << "Размер arr_4: " << arr_4.getLength() << endl;
    arr_4 = arr_3;
    cout << "Размер arr_4 после присвоения arr_3: " << arr_4.getLength() << endl;
    arr_4.showArray();

    arr_4.remove(4);
    arr_4.remove(4);
    arr_4.remove(4);

    arr_4.showArray();
    arr_3.showArray();

    return 0;
}