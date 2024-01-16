#include <iostream>
#include <iomanip>

class Container {
public:
    double* array = nullptr;
    int p;
    double sum = 0;
    double digit;

    Container() {
        read();
    }

    ~Container() {
        delete[] array;
    }

    void read() {
        std::cin >> p;
        array = new double[p];
        for (int i = 0; i < p; ++i) {
            std::cin >> array[i];
        }
    }

    void calculateSumAndAverage() {
        sum = 0;
        for (int i = 0; i < p; ++i) {
            sum += array[i];
        }
        digit = sum / p;
    }

    void print(int f) {
        if (f == 0)
            std::cout << p << std::endl;
        for (int i = 0; i < p; ++i) {
            std::cout << std::fixed << std::setprecision(3) << array[i] << " ";
        }
        std::cout << std::endl;
        if (f == 1)
            std::cout << sum << " " << digit << std::endl << " ";
        else
            std::cout << std::endl << std::endl;
    }

    int findFirstOdd() {
        for (int i = 0; i < p; ++i) {
            if ((int)array[i] % 2 != 0) {
                return (int)array[i];
            }
        }
        return 0;
    }

    void addValue(int add) {
        for (int i = 0; i < p; ++i) {
            array[i] += add;
            std::cout << array[i] << " ";
        }
        digit += add;
        sum += add;
        std::cout << sum << " " << digit << std::endl;
    }

    void expandArray() {
        double* newArray = new double[p + 2];
        for (int i = 0; i < p; ++i) {
            newArray[i] = array[i];
        }
        newArray[p] = sum;
        newArray[p + 1] = digit;

        delete[] array;
        array = newArray;

        p = p + 2;
    }

    void addValueToDynamicArray() {
        double* newArray = new double[p + 1];
        for (int i = 0; i < p; ++i) {
            newArray[i] = array[i];
        }
        std::cin >> newArray[p];

        delete[] array;
        array = newArray;

        p = p + 1;
    }

    void removeValueFromDynamicArray() {
        double* newArray = new double[p - 1];
        for (int i = 0; i < p - 1; ++i) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;

        p = p - 1;
    }
};

int main() {
    Container container;
    char action;
    double flag = 1;
    container.print(0);
    container.calculateSumAndAverage();
    container.print(1);
    int add = container.findFirstOdd();
    container.addValue(add);
    container.expandArray();

    while (flag != 0) {
        std::cin >> action;
        switch (action) {
        case '1':
            container.addValueToDynamicArray();
            container.calculateSumAndAverage();
            std::cout << "+:" << ' ' << std::endl;
            container.print(0);
            container.print(1);
            add = container.findFirstOdd();
            container.addValue(add);
            container.expandArray();
            break;
        case '2':
            container.removeValueFromDynamicArray();
            container.calculateSumAndAverage();
            std::cout << "-:" << std::endl << ' ';
            container.print(0);
            container.print(1);
            add = container.findFirstOdd();
            container.addValue(add);
            container.expandArray();
            break;
        default:
            flag = 0;
        }
    }

    return 0;
}