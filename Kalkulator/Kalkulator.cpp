#include <iostream>

/*int main()
{
    system("chcp 1251"); // кодировка "Windows 1251" - русская кодировка;
    system("color 1C");
    std::cout << "Привет мир!\n";
    system("pause"); // пауза между очисткой и выводом текста
    system("cls");//очистка предыдущего;

        std::cout << "Текст текст текст \n";
        system("color B"); 
}*/

using namespace std; // Функция для выполнения операций
double calculate(double num1, double num2, char operation) {

#define COL2 "\x1B[31m"
#define COL0 "\x1B[0m"

    switch (operation) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << COL2 << "Ошибка! Деление на ноль невозможно." << COL0;
            return NAN; // Возвращаем специальное значение NaN ("не число")
        }
    default:
        cout << COL2 << "Ошибка!!!" << COL0;
        return NAN; // Возвращаем специальное значение NaN ("не число")
    }
}

int main() {
    system("chcp 1251");

    double firstNumber, secondNumber;//число с плавающей точкой
    char op; //одиночный символ

    // Запрашиваем ввод чисел и оператора от пользователя

#define COL1 "\x1B[33m" // задается цвет текста
#define COL0 "\x1B[0m" // стандартные настройки цвета

        cout << COL1 << "Калькулятор\n" << COL0;
    

    cout << "Введите первое число: ";
    cin >> firstNumber; //команда ввода
    cout << "Выберите операцию (+,-,*,/): ";
    cin >> op;
    cout << "Введите второе число: ";
    cin >> secondNumber;

    // Вычисление результата
    double result = calculate(firstNumber, secondNumber, op);

    // Проверка на ошибку вычисления (NaN означает наличие ошибки)
    if (!isnan(result)) { // Печатаем результат только если вычисление прошло успешно
        cout << "Результат: " << result << endl;
    }

    return 0;
}
