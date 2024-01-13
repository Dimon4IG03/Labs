#include <iostream>

using namespace std;

class BitStrings {
public:
    int size;
    unsigned char* result;
    unsigned char* Bitstring1;
    unsigned char* Bitstring2;

    BitStrings() // Инициализация массивов
    {
        cin >> size;
        Bitstring1 = new unsigned char[size];
        Bitstring2 = new unsigned char[size];
        for (int i = 0; i < size; i++)
            cin >> Bitstring1[i];
        for (int i = 0; i < size; i++)
            cin >> Bitstring2[i];
        Output();
    }

    void Output() // Вывод результатов всех функций
    {
        OutputArr(Bitstring1, 1);
        Not(Bitstring1, 1);
        OutputArr(Bitstring2, 2);
        Not(Bitstring2, 2);
        Or();
        Xor();
        And();
    }

    void OutputArr(unsigned char* arr, int N) // Вывод массива
    {
        cout << "Bitstring" << N << " =";
        for (int i = 0; i < size; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }

    void And() // Операция И
    {
        cout << "Bitstring1 and Bitstring2 =";
        result = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            if (Bitstring1[i] == '1' && Bitstring2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
            cout << ' ' << result[i];
        }
        cout << endl;
        delete[] result;
        result = NULL;
    }

    void Or() // Операция Или
    {
        result = new unsigned char[size];
        cout << "Bitstring1 or Bitstring2 =";
        for (int i = 0; i < size; i++)
        {
            if (Bitstring1[i] == '1' || Bitstring2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
            cout << ' ' << result[i];
        }
        cout << endl;
        delete[] result;
        result = NULL;
    }

    void Xor() // Операция Исключающее Или
    {
        result = new unsigned char[size];
        cout << "Bitstring1 xor Bitstring2 =";
        for (int i = 0; i < size; i++)
        {
            if (Bitstring1[i] != Bitstring2[i])
                result[i] = '1';
            else
                result[i] = '0';
            cout << ' ' << result[i];
        }
        cout << endl;
        delete[] result;
        result = NULL;
    }

    void sdvig(unsigned char* arr, int N) // Сдвиг массива
    {
        int steps;
        cin >> steps;
        cout << "cycle sdvig " << steps << " Bitstring" << N << endl;
        steps = steps % size;
        result = new unsigned char[steps];
        for (int i = 0; i < steps; i++)
            result[i] = arr[size - steps + i];
        for (int i = size - 1; i >= steps; i--)
            arr[i] = arr[i - steps];
        for (int i = 0; i < steps; i++)
            arr[i] = result[i];
        delete[] result;
        result = NULL;
    }

    void Not(unsigned char* arr, int N) // Операция НЕ
    {
        cout << "not Bitstring" << N << " =";
        result = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == '1')
                result[i] = '0';
            else
                result[i] = '1';
            cout << ' ' << result[i];
        }
        cout << endl;
        delete[] result;
        result = NULL;
    }

    void f1()
    {
        sdvig(Bitstring1, 1);
        Output();
    }

    void f2()
    {
        sdvig(Bitstring2, 2);
        Output();
    }

    ~BitStrings()
    {
        delete[] Bitstring1;
        delete[] Bitstring2;
    }
};

int main()
{
    BitStrings One;
    int input;
    cin >> input;
    while (input != 0)
    {
        switch (input)
        {
        case 1:
            One.f1();
            break;
        case 2:
            One.f2();
            break;
        }
        cin >> input;
    }
    return 0;
}