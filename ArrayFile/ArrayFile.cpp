#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

double* L = NULL;

vector<double> Vec;
int fl;

typedef double* pDouble;

int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << "Введіть розмір масиву: ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}

int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }


    return size;
}

void Task1(int size, double A[]) {
    double min = 9999999999999999999;
    int flag = 0;
    if (fl) {
        for (int i = 0; i < size; i++) {
            if (Vec[i] <= min && Vec[i] > 0) {
                min = Vec[i];
                flag = i;
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (A[i] <= min && A[i] > 0) {
                min = A[i];
                flag = i;
            }
        }
    }


    cout << "\nМінімальне число: " << min;
    cout << "\nІндекс мінімального числа: " << flag << "\n";
}

void Task2(int size, double A[], double T) {
    double min = 0;
    int prapor = 0;
    int flag = 0;

    if (fl) {
        for (int i = 0; i < size; i++) {
            if (!prapor)
                if (Vec[i] > T)
                    prapor = i;
            for (int j = 0; j < prapor; j++) {
                if (Vec[j] < min && Vec[j] < 0) {
                    min = Vec[j];
                    flag = i;
                }
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (!prapor)
                if (A[i] > T)
                    prapor = i;

            for (int j = 0; j < prapor; j++) {
                if (A[j] < min && A[j] < 0) {
                    min = A[j];
                    flag = i;
                }
            }
        }
    }
    cout << "\nМаксимально від'ємне число: " << min;
    cout << "\n";
}

void Task3(int n, int m, double A[100][10]) {

    double* p;
    p = new double[n];

    for (int i = 0; i < m; i++) { // n - collum   m - row
        p[i] = A[i][0];
        for (int j = 0; j < n; j++) {
            if (p[i] > A[i][j]) p[i] = A[i][j];
        }
        cout << i + 1 << ") min = " << p[i] << " \n";
    }

    double max;
    max = p[0];
    //
    for (int i = 0; i < m; i++) {
        if (max < p[i]) max = p[i];
    }
    cout << "max = " << max;

}

////////////////////////////////////////////////////////////////////////

void ConsoleInputDoubleArray(int n, int m, double A[100][10]) {
    cout << "Масив А: \n";
    for (int i = 0; i < m; i++, cout << "\n") {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            cout << A[i][j] << " ";
        }
    }
}

void RndInputDoubleArray(int n, int m, double A[100][10]) {

    int r1 = 0, r2 = 0, r3 = 0;
    srand(time(NULL));

    cout << "Масив А: \n";

    for (int i = 0; i < m; i++, cout << "\n") {
        for (int j = 0; j < n; j++) {
            r1 = rand();
            r2 = rand();
            r3 = rand();
            A[i][j] = 100.0 * r1;
            A[i][j] = A[i][j] / (1.0 + r2);
            if (r3 % 3 == 0) A[i][j] = -A[i][j];
            std::cout << " Array[ " << i+1 << "] " << A[i][j] << " \n";
        }
    }
}

////////////////////////////////////////////////////////////////////////

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    L = pA;
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    L = pA;
    return size;
}

int ConsoleInputVector(int sizeMax)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; Vec.push_back(d);
    }
    fl = 1;
    return size;
}

int ReadArrayTextFile(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    ifstream fin;
    fin.open("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file1.txt");
    if (fin.fail()) return 0;
    if (size <= 0) return 0;

    for (int i = 0; i < size; i++)
    {
        fin >> pA[i];
        cout << i + 1 << ") Element arrays:"  << pA[i] << "\n";
    }
    fin.close();
    L = pA;

    return size;
}

int ReadDynamicArray_callocTextFile(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    ifstream fin;
    fin.open("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file1.txt");
    if (fin.fail()) return 0;
    if (size <= 0) return 0;

    pA = (double*)calloc(size, sizeof(double));
    if (pA == nullptr) { return 0; }

    for (int i = 0; i < size; i++)
    {
        fin >> pA[i];
        cout << i + 1 << ") Element arrays:" << pA[i] << "\n";
    }
    fin.close();
    L = pA;

    return size;
}

int ReadDynamicArrayNewTextFile(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    ifstream fin;
    fin.open("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file1.txt");
    if (fin.fail()) return 0;
    if (size <= 0) return 0;

    pA = new double[size];
    if (pA == nullptr) { return 0; }

    for (int i = 0; i < size; i++)
    {
        fin >> pA[i];
        cout << i + 1 << ") Element arrays:" << pA[i] << "\n";
    }
    fin.close();
    L = pA;

    return size;
}

int ReadVectorTextFile(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    ifstream fin;
    fin.open("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file1.txt");
    if (fin.fail()) return 0;
    if (size <= 0) return 0;

    for (int i = 0; i < size; i++){
        fin >> d;
        cout << i + 1 << ") Element arrays:" << d << " \n";
        Vec.push_back(d);
    }
    fl = 1;
    fin.close();

    return size;
}

int WriteArrayTextFile1(int size, pDouble pA){
    double min = 9999999999999999999;
    int flag = 0;

    if (fl) {
        for (int i = 0; i < size; i++) {
            if (Vec[i] <= min && Vec[i] > 0) {
                min = Vec[i];
                flag = i;
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (pA[i] <= min && pA[i] > 0) {
                min = pA[i];
                flag = i;
            }
        }
    }

    ofstream fout("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file2.txt");
    if (!fout) cout << "Erorr";

    if (fl) {
        for (int i = 0; i < size; i++){
            fout << i + 1 << ") Element arrays:" << Vec[i] << "\n";
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            fout << i + 1 << ") Element arrays:" << pA[i] << "\n";
        }
    }
    cout << "\nМінімальне число: " << min;
    cout << "\nІндекс мінімального числа: " << flag + 1 << "\n";

    fout << "Мінімальне число: " << min;
    fout << "\nІндекс мінімального числа: " << flag + 1 << "\n";

    fout.close(); 

    return 0;
}

int WriteArrayTextFile2(int size, pDouble pA, double T) {
    double min = 0;
    int prapor = 0;
    int flag = 0;

    if (fl) {
        for (int i = 0; i < size; i++) {
            if (!prapor)
                if (Vec[i] > T)
                    prapor = i;
            for (int j = 0; j < prapor; j++) {
                if (Vec[j] < min && Vec[j] < 0) {
                    min = Vec[j];
                    flag = i;
                }
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (!prapor)
                if (pA[i] > T)
                    prapor = i;

            for (int j = 0; j < prapor; j++) {
                if (pA[j] < min && pA[j] < 0) {
                    min = pA[j];
                    flag = i;
                }
            }
        }
    }

    ofstream fout("C:\\Users\\Admin\\Documents\\GitHub\\lab_01_2022-VasyaSuper\\file3.txt");
    if (!fout) cout << "Erorr";

    if (fl) {
        for (int i = 0; i < size; i++) {
            fout << i + 1 << ") Element arrays:" << Vec[i] << "\n";
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            fout << i + 1 << ") Element arrays:" << pA[i] << "\n";
        }
    }

    cout << "\nМаксимально від'ємне число: " << min;
    cout << "\n";

    fout << "\nМаксимально від'ємне число: " << min;

    fout.close();

    return 0;
}

int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, r3 = 0;
    srand(time(NULL));

    std::cout << "  ";
    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        r3 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        if (r3 % 3 == 0) A[i] = -A[i];
        std::cout << " Array[ " << i << "] " << A[i] << " \n";
    }
    return size;
}

int RndInputDynamicArray_calloc(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, r3 = 0;
    srand(time(NULL));

    pA = (double*)calloc(size, sizeof(double));
    if (pA == nullptr) { return 0; }

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        r3 = rand();
        pA[i] = 100.0 * r1;
        pA[i] = pA[i] / (1.0 + r2);
        if (r3 % 3 == 0) pA[i] = -pA[i];
        cout << " Array[ " << i << "] " << pA[i] << " \n";
   
    }
    L = pA;
    return size;
}

int RndInputDynamicArrayNew(int sizeMax, pDouble pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, r3 = 0;
    srand(time(NULL));
    
    pA = new double[size];
    if (pA == nullptr) { return 0; }

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        r3 = rand();
        pA[i] = 100.0 * r1;
        pA[i] = pA[i] / (1.0 + r2);
        if (r3 % 3 == 0) pA[i] = -pA[i];
        cout << " Array[ " << i << "] " << pA[i] << " \n";
    }
    L = pA;
    return size;
}

int RndInputVector(int sizeMax)
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, r3 = 0;
    srand(time(NULL));

    double d;

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        r3 = rand();
        d = 100.0 * r1;
        d = d / (1.0 + r2);
        if (r3 % 3 == 0) d = -d;
        cout << " Array[ " << i << "] " << d << " \n";
        Vec.push_back(d);
    }
    fl = 1;
    return size;
}

void ShowMainMenu()
{
    cout << "                                                       Завдання   \n";
    cout << " 1. Задано одновимірний масив А розміру N. Знайти серед всіх додатних мінімальний елемент масиву та його індекс.  \n";
    cout << " 2. Знайти номер першого максимального елемента серед від’ємних елементів,  розташованих до першого елемента, більшого заданого числа Т.  \n";
    cout << " 3. Задано масив дійсних чисел A(n x m), n<=100, m<=10. Розробити програму, яка обчислює  \n";
    cout << "         Z = max(min(A(1),...,A(m)),min(A(m+1),...,A(2m)),...,min(A(m(n-1)+1),...,A(n*m))).  \n";
}

void TaskT1()
{
    int a1, n;
    double A[560];

    cout << "    1.  З консолі (локально)  \n";
    cout << "    2.  З консолі (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    3.  З консолі (динамічно за допомогою new або new[]) \n";
    cout << "    4.  З консолі (з використанням vector, valarray або array) \n";
    cout << "    5.  З файлу (локально) \n";
    cout << "    6.  З файлу (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    7.  З файлу (динамічно за допомогою new або new[]) \n";
    cout << "    8.  З файлу (з використанням vector, valarray або array) \n";
    cout << "    9.  З використанням датчика випадкових чисел (локально) \n";
    cout << "    10.  З використанням датчика випадкових чисел (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    11.  З використанням датчика випадкових чисел (динамічно за допомогою new або new[]) \n";
    cout << "    12.  З використанням датчика випадкових чисел (з використанням vector, valarray або array) \n";
    cout << "Виберіть як будуть вводитись дані:  ";


    cin >> a1;

    if (a1 < 1 || a1 > 12) {
        cout << "\n Неправильний символ \n";
        TaskT1();
    }

    switch (a1) {
    case 1:
        n = ConsoleInputArray(560, A);
        Task1(n, A);
        break;
    case 2:
        n = ConsoleInputDynamicArray_calloc(560, A);
        Task1(n, L);
        break;
    case 3:
        n = ConsoleInputDynamicArrayNew(560, A);
        Task1(n, L);
        break;
    case 4:
        n = ConsoleInputVector(560);
        Task1(n, A);
        break;
    case 5:
        n = ReadArrayTextFile(560, A);
        WriteArrayTextFile1(n, L);
        break;
    case 6: 
        n = ReadDynamicArray_callocTextFile(560, A);
        WriteArrayTextFile1(n, L);
        break;
    case 7:
        n = ReadDynamicArrayNewTextFile(560, A);
        WriteArrayTextFile1(n, L);
        break;
    case 8:
        n = ReadVectorTextFile(560, A);
        WriteArrayTextFile1(n, A);
        break;
    case 9:
        n = RndInputArray(560, A);
        Task1(n, A);
        break;
    case 10:
        n = RndInputDynamicArray_calloc(560, A);
        Task1(n, L);
        break;
    case 11:
        n = RndInputDynamicArrayNew(560, A);
        Task1(n, L);
        break;
    case 12:
        n = RndInputVector(560);
        Task1(n, A);
        break;
    default:
        break;
    }
}

void TaskT2()
{
    int a1, n;
    double A[560];
    double T = 0;

    cout << "    1.  З консолі (локально)  \n";
    cout << "    2.  З консолі (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    3.  З консолі (динамічно за допомогою new або new[]) \n";
    cout << "    4.  З консолі (з використанням vector, valarray або array) \n";
    cout << "    5.  З файлу (локально) \n";
    cout << "    6.  З файлу (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    7.  З файлу (динамічно за допомогою new або new[]) \n";
    cout << "    8.  З файлу (з використанням vector, valarray або array) \n";
    cout << "    9.  З використанням датчика випадкових чисел (локально) \n";
    cout << "    10.  З використанням датчика випадкових чисел (динамічно за допомогою malloc(), calloc() та realloc()) \n";
    cout << "    11.  З використанням датчика випадкових чисел (динамічно за допомогою new або new[]) \n";
    cout << "    12.  З використанням датчика випадкових чисел (з використанням vector, valarray або array) \n";
    cout << "Виберіть як будуть вводитись дані:  ";

    cin >> a1;

    if (a1 < 1 || a1 > 12) {
        cout << "\n Неправильний символ \n";
        TaskT2();
    }

    cout << "Введіть букву Т: ";
    cin >> T;

    switch (a1) {
    case 1:
        n = ConsoleInputArray(560, A);
        Task2(n, A, T);
        break;
    case 2:
        n = ConsoleInputDynamicArray_calloc(560, A);
        Task2(n, L, T);
        break;
    case 3:
        n = ConsoleInputDynamicArrayNew(560, A);
        Task2(n, L, T);
        break;
    case 4:
        n = ConsoleInputVector(560);
        Task2(n, A, T);
        break;
    case 5:
        n = ReadArrayTextFile(560, A);
        WriteArrayTextFile2(n, L, T);
        break;
    case 6:
        n = ReadDynamicArray_callocTextFile(560, A);
        WriteArrayTextFile2(n, L, T);
        break;
    case 7:
        n = ReadDynamicArrayNewTextFile(560, A);
        WriteArrayTextFile2(n, L, T);
        break;
    case 8:
        n = ReadVectorTextFile(560, A);
        WriteArrayTextFile2(n, A, T);
        break;
    case 9:
        n = RndInputArray(560, A);
        Task2(n, A, T);
        break;
    case 10:
        n = RndInputDynamicArray_calloc(560, A);
        Task2(n, L, T);
        break;
    case 11:
        n = RndInputDynamicArrayNew(560, A);
        Task2(n, L, T);
        break;
    case 12:
        n = RndInputVector(560);
        Task2(n, A, T);
    default:
        break;
    }
}

void TaskT3()
{
    int a1;
    int n = 100, m = 10;
    double A[100][10];

    cout << "    1.  З консолі (локально)  \n";
    cout << "    2.  З використанням датчика випадкових чисел (локально) \n";

    cout << "Виберіть як будуть вводитись дані:  ";

    cin >> a1;

    if (a1 < 1 || a1 > 12) {
        cout << "\n Неправильний символ \n";
        TaskT3();
    }

    cout << "Введіть N: ";
    cin >> n;
    cout << "Введіть M: ";
    cin >> m;

    switch (a1) {
    case 1:
        ConsoleInputDoubleArray(n,m,A);
        Task3(n,m,A);
        break;
    case 2:
        RndInputDoubleArray(n, m, A);
        Task3(n, m, A);
        break;
    default:
        break;
    }
}

void Tasks() {

    int a;
    cout << "\n\n Оберіть завдання : ";
    cin >> a;

    if (a < 1 || a > 3) {
        cout << "\n Неправильний символ \n";
        Tasks();
    }

    switch (a) {
    case 1:
        TaskT1();
        break;
    case 2:
        TaskT2();
        break;
    case 3:
        TaskT3();
        break;
    default:
        break;
    }

}

int main()
{
    system("chcp 1251");
    system("cls");

    ShowMainMenu();

    Tasks();

    return 0;          
}