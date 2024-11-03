#include <iostream>
#include <iomanip> // For std::setw
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin() {
        cout << "Enter " << SIZE * SIZE << " values for the matrix:" << endl;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cin >> data[i][j];
            }
        }
    }

    // 2. Display a matrix
    void display() const {
        cout << "\n";
        // Print column headers
        cout << "      "; // Space to align with row labels
        for (int j = 0; j < SIZE; j++) {
            cout << "COLUMN " << setw(2) << j << " "; // Print column headers
        }
        cout << "\n";

        // Print each row
        for (int i = 0; i < SIZE; i++) {
            cout << "ROW " << setw(2) << i << " "; // Print row header
            for (int j = 0; j < SIZE; j++) {
                if (j == 0) {
                    cout << setw(4) << data[i][j]; // Align first value
                } else {
                    cout << setw(10) << data[i][j]; // Normal case
                }
            }
            cout << "\n\n"; // New line after each row
        }
    }

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = 0; // Initialize to 0
                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    void sumOfDiagonals() const {

        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i]; // Main diagonal
            sum2 += data[i][SIZE - 1 - i]; // Secondary diagonal
        }
        cout << "Sum of main diagonal of Matrix 1: " << sum << endl;
        cout << "Sum of secondary diagonal of Matrix 1: " << sum2 << endl;
        cout << "Sum of main and secondary diagonals of Matrix 1: " << sum + sum2 << endl;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        //Check if row values are invalid 
        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
            cout << "Invalid row indices!" << endl;
            return;
        }
        //Preform the swap
        for (int j = 0; j < SIZE; j++) {
            std::swap(data[row1][j], data[row2][j]);
        }
    }
};

int main() {
    //Take in the values for first matrix
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    //Print the first matrix
    cout << "Matrix 1:" << endl;
    mat1.display();

    //Take in the values for the second matrix
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    //Print the second matrix
    cout << "Matrix 2:" << endl;
    mat2.display();

    //Display the sum of the two matrix
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    //Display the product of the two matrix
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    //Give the sum of the main diagonal
    //Visual
    // - 0 0 0
    // 0 - 0 0
    // 0 0 - 0 
    // 0 0 0 -
    //Visual for secondary diagonal
    // 0 0 0 -
    // 0 0 - 0
    // 0 - 0 0
    // - 0 0 0
    mat1.sumOfDiagonals();
    cout << endl;

    //Ask the user for the rows to swap
    int row1, row2;
    cout << "Enter two row indices to swap (0-based): ";
    cout << endl;
    cin >> row1 >> row2;
    //Preform the swap
    mat1.swapRows(row1, row2);
    //Displays the swap
    //If the row index are out of range it displays the unchanged matrix
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
