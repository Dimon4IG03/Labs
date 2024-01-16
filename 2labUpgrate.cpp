#include <iostream>

class BitStrings {
public:
    int size;
    unsigned char* result;
    unsigned char* Bitstring1;
    unsigned char* Bitstring2;

    BitStrings() {
        std::cin >> size;
        Bitstring1 = new unsigned char[size];
        Bitstring2 = new unsigned char[size];
        for (int i = 0; i < size; i++)
            std::cin >> Bitstring1[i];
        for (int i = 0; i < size; i++)
            std::cin >> Bitstring2[i];
        Output();
    }

    void Output() {
        OutputArr(Bitstring1, 1);
        Not(Bitstring1, 1);
        OutputArr(Bitstring2, 2);
        Not(Bitstring2, 2);
        Or();
        Xor();
        And();
    }

    void OutputArr(unsigned char* arr, int N) {
        std::cout << "Bitstring" << N << " =";
        for (int i = 0; i < size; i++)
            std::cout << ' ' << arr[i];
        std::cout << std::endl;
    }

    void And() {
        std::cout << "Bitstring1 and Bitstring2 =";
        result = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            if (Bitstring1[i] == '1' && Bitstring2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
            std::cout << ' ' << result[i];
        }
        std::cout << std::endl;
        delete[] result;
        result = nullptr;
    }

    void Or() {
        result = new unsigned char[size];
        std::cout << "Bitstring1 or Bitstring2 =";
        for (int i = 0; i < size; i++) {
            if (Bitstring1[i] == '1' || Bitstring2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
            std::cout << ' ' << result[i];
        }
        std::cout << std::endl;
        delete[] result;
        result = nullptr;
    }

    void Xor() {
        result = new unsigned char[size];
        std::cout << "Bitstring1 xor Bitstring2 =";
        for (int i = 0; i < size; i++) {
            if (Bitstring1[i] != Bitstring2[i])
                result[i] = '1';
            else
                result[i] = '0';
            std::cout << ' ' << result[i];
        }
        std::cout << std::endl;
        delete[] result;
        result = nullptr;
    }

    void sdvig(unsigned char* arr, int N) {
        int steps;
        std::cin >> steps;
        std::cout << "cycle sdvig " << steps << " Bitstring" << N << std::endl;
        steps = steps % size;
        result = new unsigned char[steps];
        for (int i = 0; i < steps; i++)
            result[i] = arr[size - steps + i];
        for (int i = size - 1; i >= steps; i--)
            arr[i] = arr[i - steps];
        for (int i = 0; i < steps; i++)
            arr[i] = result[i];
        delete[] result;
        result = nullptr;
    }

    void Not(unsigned char* arr, int N) {
        std::cout << "not Bitstring" << N << " =";
        result = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            if (arr[i] == '1')
                result[i] = '0';
            else
                result[i] = '1';
            std::cout << ' ' << result[i];
        }
        std::cout << std::endl;
        delete[] result;
        result = nullptr;
    }

    void f1() {
        sdvig(Bitstring1, 1);
        Output();
    }

    void f2() {
        sdvig(Bitstring2, 2);
        Output();
    }

    ~BitStrings() {
        delete[] Bitstring1;
        delete[] Bitstring2;
    }
};

int main() {
    BitStrings One;
    int input;
    std::cin >> input;
    while (input != 0) {
        switch (input) {
        case 1:
            One.f1();
            break;
        case 2:
            One.f2();
            break;
        }
        std::cin >> input;
    }
    return 0;
}