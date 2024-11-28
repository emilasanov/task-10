
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
        cout << "������. ������� �����!" << endl;
        cin >> number;
    }
    while (number < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������. ����� ������ ���� ������ ����!" << endl;
        cin >> number;
    }
    return number;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n = 0;
    cout << "������� ���������� �����: ";
    n = checkError(n);

    if (n % 2 != 0) {
        cout << "����� ����� ������ ���� ������ ��� ������������ �������������." << endl;
        return 1;
    }

    vector<int> weights(n);
    cout << "������� ���� ������ ����: ";
    for (int i = 0; i < n; ++i) {
        weights[i] = checkError(weights[i]);
    }

    // ��������� ���� �� �������� ����
    sort(weights.rbegin(), weights.rend());

    // �������� �������������� �������
    vector<int> backpack1, backpack2;
    int weight1 = 0, weight2 = 0;
    for (int weight : weights) {
        // ����� ���� � ��� ������, ������� ������ �����
        if (weight1 <= weight2) {
            backpack1.push_back(weight);
            weight1 += weight;
        }
        else {
            backpack2.push_back(weight);
            weight2 += weight;
        }
    }

    cout << "������ 1 (����): ";
    for (int w : backpack1) cout << w << " ";
    cout << "\n��� ������� �������: " << weight1 << endl;

    cout << "������ 2 (����): ";
    for (int w : backpack2) cout << w << " ";
    cout << "\n��� ������� �������: " << weight2 << endl;

    return 0;
}