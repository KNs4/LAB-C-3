#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std; // Позволяет не писать std:: перед стандартными функциями и типами

// Класс для описания точки на двумерной плоскости
class Point {
private:
    double x; // Координата X
    double y; // Координата Y

public:
    // Конструктор по умолчанию
    Point() : x(0), y(0) {}

    // Конструктор с параметрами
    Point(double x, double y) : x(x), y(y) {}

    // Метод для получения координаты X
    double getX() const {
        return x;
    }

    // Метод для получения координаты Y
    double getY() const {
        return y;
    }

    // Метод для установки координаты X
    void setX(double x) {
        this->x = x;
    }

    // Метод для установки координаты Y
    void setY(double y) {
        this->y = y;
    }

    // Метод для получения текстового представления точки
    string toString() const {
        ostringstream oss;
        oss << "{" << x << ";" << y << "}";
        return oss.str();
    }

    // Метод для вывода информации о точке
    void print() const {
        cout << toString() << endl;
    }
};

// Класс для описания имени
class Name {
private:
    string surname;   // Фамилия
    string firstName; // Личное имя
    string patronymic; // Отчество

public:
    // Конструктор по умолчанию
    Name() : surname(""), firstName(""), patronymic("") {}

    // Конструктор с параметрами
    Name(const string& surname, const string& firstName, const string& patronymic = "")
        : surname(surname), firstName(firstName), patronymic(patronymic) {}

    // Метод для получения строкового представления имени
    string toString() const {
        stringstream ss;
        if (!surname.empty()) ss << surname;
        if (!firstName.empty()) {
            if (!surname.empty()) ss << " ";
            ss << firstName;
        }
        if (!patronymic.empty()) {
            if (!surname.empty() || !firstName.empty()) ss << " ";
            ss << patronymic;
        }
        return ss.str();
    }

    // Метод для вывода имени на экран
    void print() const {
        cout << toString() << endl;
    }
};

// Класс для описания линии
class Line {
private:
    Point* start; // Начальная точка
    Point* end;   // Конечная точка

public:
    // Конструктор с инициализацией начальной и конечной точек
    Line(Point* start, Point* end) : start(start), end(end) {}

    // Метод для получения текстового представления линии
    string toString() const {
        ostringstream oss;
        oss << "Линия от " << start->toString() << " до " << end->toString();
        return oss.str();
    }

    // Метод для вывода информации о линии
    void print() const {
        cout << toString() << endl;
    }

    // Методы для изменения начальной и конечной точек
    void setStart(Point* newStart) {
        start = newStart;
    }

    void setEnd(Point* newEnd) {
        end = newEnd;
    }

    // Метод для получения начальной и конечной точек
    Point* getStart() const {
        return start;
    }

    Point* getEnd() const {
        return end;
    }
};

// Структура для описания пути
struct Path {
    class City* destination; // Указатель на город назначения
    int cost; // Стоимость пути

    Path(City* destination, int cost) : destination(destination), cost(cost) {}
};

// Класс для описания города
class City {
private:
    string name; // Название города
    vector<Path> paths; // Вектор путей к другим городам

public:
    City(const string& name) : name(name) {}

    // Метод для добавления пути к другому городу с указанием стоимости
    void addPath(City* destination, int cost) {
        paths.push_back(Path(destination, cost));
    }

    // Метод для получения строкового представления города и его путей
    string toString() const {
        ostringstream oss;
        oss << "Город " << name << " связан с: ";
        for (const auto& path : paths) {
            oss << path.destination->name << ":" << path.cost << " ";
        }
        return oss.str();
    }

    // Метод для вывода информации о городе
    void print() const {
        cout << toString() << endl;
    }
};

// Функция для безопасного ввода числа с проверкой
double safeInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        // Проверка на корректность ввода
        if (cin.fail()) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка входного буфера
            cout << "Некорректный ввод. Пожалуйста, введите число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Функция для выбора задания
void displayMenu() {
    cout << "Выберите задание для вывода:\n";
    cout << "1. Показать точки на плоскости\n";
    cout << "2. Показать имена\n";
    cout << "3. Показать линии на плоскости\n";
    cout << "4. Показать города и их связи\n";
    cout << "5. Выход\n";
}

// Главная функция
int main() {
    int choice; // Переменная для выбора задания

    do {
        displayMenu(); // Отображение меню выбора задания
        choice = safeInput("Введите номер задания: "); // Ввод выбора

        switch (choice) {
            case 1: {
                // Демонстрация работы класса Point
                cout << "Точки на плоскости:\n";
                Point point1(1.5, 2.5);
                Point point2(3.0, 4.0);
                Point point3;

                // Пользовательский ввод для третьей точки
                double x = safeInput("Введите координату X для точки 3: ");
                double y = safeInput("Введите координату Y для точки 3: ");
                point3.setX(x);
                point3.setY(y);

                // Вывод точек
                cout << "Координаты точки 1: ";
                point1.print();
                cout << "Координаты точки 2: ";
                point2.print();
                cout << "Координаты точки 3: ";
                point3.print();
                break;
            }
            case 2: {
                // Демонстрация работы класса Name
                cout << "\nИмена:\n";
                Name name1("", "Клеопатра"); // Только личное имя
                Name name2("Пушкин", "Александр", "Сергеевич"); // Фамилия, имя и отчество
                Name name3("Маяковский", "Владимир"); // Фамилия и имя

                // Выводим полные имена
                cout << "Имя 1: ";
                name1.print();
                cout << "Имя 2: ";
                name2.print();
                cout << "Имя 3: ";
                name3.print();
                break;
            }
            case 3: {
                // Демонстрация работы класса Line
                cout << "\nЛинии на плоскости:\n";

                // Линия 1
                Point line1Start(1, 3);
                Point line1End(23, 8);
                Line line1(&line1Start, &line1End);
                cout << "Линия 1: ";
                line1.print();

                // Линия 2
                Point line2Start(5, 10);
                Point line2End(25, 10);
                Line line2(&line2Start, &line2End);
                cout << "Линия 2: ";
                line2.print();

                // Линия 3, начинается там же, где линия 1, и заканчивается там же, где линия 2
                Line line3(line1.getStart(), line2.getEnd());
                cout << "Линия 3: ";
                line3.print();

                // Изменяем координаты первой и второй линий
                line1Start.setX(2);
                line1Start.setY(4);
                line1End.setX(22);
                line1End.setY(7);

                line2Start.setX(6);
                line2End.setX(24);

                // Выводим измененные линии
                cout << "\nИзмененные линии:\n";
                cout << "Линия 1: ";
                line1.print();
                cout << "Линия 2: ";
                line2.print();
                cout << "Линия 3 (зависимая): ";
                line3.print();

                // Изменяем координаты первой линии так, чтобы не повлиять на линию 3
                line1.setStart(new Point(10, 10)); // Это создаёт новую начальную точку для line1

                // Вывод финальных изменений
                cout << "\nФинальные координаты:\n";
                cout << "Линия 1 (без влияния на линию 3): ";
                line1.print();
                cout << "Линия 3 (координаты не изменились): ";
                line3.print();
                break;
            }
            case 4: {
                // Демонстрация работы класса City и связи между городами
                cout << "\nГорода и их связи:\n";
                City* cityA = new City("A");
                City* cityB = new City("B");
                City* cityC = new City("C");
                City* cityD = new City("D");
                City* cityE = new City("E");
                City* cityF = new City("F");

                // Добавляем пути между городами
                cityA->addPath(cityB, 5); // A - B
                cityA->addPath(cityC, 1); // A - C
                cityA->addPath(cityF, 3); // A - F
                cityB->addPath(cityA, 5); // B - A
                cityB->addPath(cityC, 2); // B - C
                cityB->addPath(cityD, 4); // B - D
                cityC->addPath(cityA, 1); // C - A
                cityC->addPath(cityB, 2); // C - B
                cityC->addPath(cityE, 4); // C - E
                cityC->addPath(cityF, 2); // C - F
                cityD->addPath(cityB, 4); // D - B
                cityD->addPath(cityE, 1); // D - E
                cityE->addPath(cityC, 4); // E - C
                cityE->addPath(cityD, 1); // E - D
                cityE->addPath(cityF, 6); // E - F
                cityF->addPath(cityA, 3); // F - A
                cityF->addPath(cityC, 2); // F - C
                cityF->addPath(cityE, 6); // F - E

                // Выводим информацию о городах
                cityA->print();
                cityB->print();
                cityC->print();
                cityD->print();
                cityE->print();
                cityF->print();

                // Очистка памяти
                delete cityA;
                delete cityB;
                delete cityC;
                delete cityD;
                delete cityE;
                delete cityF;
                break;
            }
            case 5: {
                // Завершение программы
                cout << "Выход из программы.\n";
                break;
            }
            default:
                cout << "Некорректный выбор. Пожалуйста, выберите номер задания от 1 до 5.\n";
        }
    } while (choice != 5); // Повторяем, пока пользователь не выберет выход

    return 0;
}
