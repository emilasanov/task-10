
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> 

using namespace std;

int checkError(int number) {
    cin >> number;
    while (cin.fail() == 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Введите число!" << endl;
        cin >> number;
    }
    while (number < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Число должно быть больше нуля!" << endl;
        cin >> number;
    }
    return number;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n = 0;
    cout << "Введите количество вещей: ";
    n = checkError(n);

    if (n % 2 != 0) {
        cout << "Число вещей должно быть чётным для равномерного распределения." << endl;
        return 1;
    }

    vector<int> weights(n);
    cout << "Введите веса каждой вещи: ";
    for (int i = 0; i < n; ++i) {
        weights[i] = checkError(weights[i]);
    }

    // Сортируем вещи по убыванию веса
    sort(weights.rbegin(), weights.rend());

    // Пытаемся сбалансировать рюкзаки
    vector<int> backpack1, backpack2;
    int weight1 = 0, weight2 = 0;
    for (int weight : weights) {
        // Кладём вещь в тот рюкзак, который сейчас легче
        if (weight1 <= weight2) {
            backpack1.push_back(weight);
            weight1 += weight;
        }
        else {
            backpack2.push_back(weight);
            weight2 += weight;
        }
    }

    cout << "Рюкзак 1 (вещи): ";
    for (int w : backpack1) cout << w << " ";
    cout << "\nВес первого рюкзака: " << weight1 << endl;

    cout << "Рюкзак 2 (вещи): ";
    for (int w : backpack2) cout << w << " ";
    cout << "\nВес второго рюкзака: " << weight2 << endl;

    return 0;
}