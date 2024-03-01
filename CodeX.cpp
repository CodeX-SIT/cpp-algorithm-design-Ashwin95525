#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    
    vector<vector<double>> coefficients(n, vector<double>(n));
    vector<double> constants(n);

   
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        coefficients[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> coefficients[i][j];
        }
        cin >> constants[i];
    }

    
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = coefficients[k][i] / coefficients[i][i];
            for (int j = i; j < n; j++) {
                coefficients[k][j] -= factor * coefficients[i][j];
            }
            constants[k] -= factor * constants[i];
        }
    }

    
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = constants[i] / coefficients[i][i];
        for (int j = i - 1; j >= 0; j--) {
            constants[j] -= coefficients[j][i] * solution[i];
        }
    }

    cout << "YES" << endl;
    cout << fixed << setprecision(2);
    for (double val : solution) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

