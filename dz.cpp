
#include <iostream>
#include <windows.h>
using namespace std;

// Функция для вычисления факториала
double factorial(int n) {
    double f = 1; // Начальное значение факториала

    // Перемножаем числа от 1 до n
    for (int i = 1; i <= n; i++) {
        f = f * i;
    }

    return f; // Возвращаем факториал
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    char type;
    int n, k;
    double result;

    // Выводим меню
    cout << "A - Размещения " << "\n";
    cout << "C - Сочетания" << "\n";
    cout << "P - Перестановки" << "\n";

    // Вводим тип задачи
    cout << "Выберите тип задачи: ";
    cin >> type;

    // Вводим количество элементов
    cout << "Введите n: ";
    cin >> n;

    // Проверяем значение n
    if (n < 0 || n > 20) {
        cout << "Ощибка! n должно быть от 1 до 20.";
        return 0;
    }

    // Если выбраны перестановки
    if (type == 'P' || type == 'p') {
        result = factorial(n);
    }
    else {
        // Вводим количество выбираемых элементов
        cout << "Введите К: ";
        cin >> k;

        // Проверяем значение k
        if (k < 0 || k > n) {
            cout << "Ощибка! k должно быть от 0 до n.";
            return 0;
        }

        // Размещения: A(n,k) = n! / (n-k)!
        if (type == 'A' || type == 'a') {
            result = factorial(n) / factorial(n - k);
        }

        // Сочетания: C(n,k) = n! / (k! * (n-k)!)
        else if (type == 'C' || type == 'c') {
            result = factorial(n) /
                (factorial(k) * factorial(n - k));
        }

        // Проверяем правильность типа задачи
        else {
            cout << "Неправильный тип задачи!";
            return 0;
        }
    }

    // Выводим результат
    cout << "Результат: " << result << endl;

    return 0;

    //double хранит большие числа, но с ограниченной точностью. Для небольших значений n, например до 20
}