// Вариант 10
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    cout << "Задание 1.1:" << endl;
    int m, n;
    cout << "Введите размерность матрицы: ";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n)); 
    for (int i = 0; i < m; i++ ) { // заполняем матрицу рандомными значениями [-50:50] и выводим её на экран
        for (int j = 0; j < n; j++ ) {   
            matrix[i][j] = -50 + rand() % 101;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    vector<int> nums; // массив неотрицательных элементов матрицы, стоящих в чётных строках, на нечётных местах
    int sum = 0;
    for (int i = 0; i < m; i++) { // Записываем подходящие элементы в массив и считаем их сумму
        for (int j = 0; j < n; j++) {
            if (((i+1) % 2 == 0) && ((j+1) % 2 != 0) && (matrix[i][j] >= 0)) {
                nums.push_back(matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    cout << "Массив неотрицательных элементов матрицы, стоящих в чётных строках, на нечётных местах: " << endl;
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl << "Сумма этих элементов: " << sum << endl;

    return 0;
}