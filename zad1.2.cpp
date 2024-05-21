#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int m;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> m;
    vector<vector<int>> matrix(m, vector<int> (m));
    for (int i = 0; i < m; i++ ) { // заполняем квадратную матрицу рандомными значениями [100:200] и выводим её на экран
        for (int j = 0; j < m; j++ ) {   
            matrix[i][j] = 100 + rand() % 101;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    vector<int> sums; // массив для хранения сумм элементов строк квадратной матрицы
    for (int i = 0; i < m; i++ ) { // заполняем массив сумм элементов строк кв. матрицы
        sum = 0;
        for (int j = 0; j < m; j++ ) {
            sum += matrix[i][j];
        }
        sums.push_back(sum);
    }
    cout << "Массив сумм элементов строк квадратной матрицы: ";
    for (auto i : sums) {
        cout << i << " ";
    }
    int maxsumindex = distance(sums.begin(), max_element(sums.begin(), sums.end())); // находим индекс строки с максимальной суммой элементов
    sums[maxsumindex] = 0; // обнуляем максимальную сумму
    maxsumindex = distance(sums.begin(), max_element(sums.begin(), sums.end())); // ещё раз находим индекс макс. суммы элементов
    cout << endl << "Строка со второй максимальной суммой элементов строк квадратной матрицы: ";
    for (auto i : matrix[maxsumindex]) {
        cout << i << " ";
    }

    return 0;
}