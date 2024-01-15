#include <iostream>
#include <vector>

int minSum(const std::vector<int>& arr, int numRows) {

    int counter = 1;
    int minSum = 0; 
    int firstColIndex = 0;
    int currentIndex;
    int minInRow;

    for (int i = 0; i < numRows; i++) {
        //0,1,3,6,10
        
        minInRow = arr[firstColIndex];

        for (int j = 0; j < counter; j++) {

            currentIndex = firstColIndex + j;
            
            if (arr[currentIndex] < minInRow) {
                minInRow = arr[currentIndex];
            }
        }
        minSum += minInRow;
        firstColIndex += counter;
        counter++;
    }

    return minSum;
}


int main() {
    int numRows = 4;
    std::vector<int> arr = { 2, 3, 4, 6, 5, 7, 4, 1, 8, 3 };

    int minimumSum = minSum(arr, numRows);
    std::cout << "Minimum sum path: " << minimumSum << std::endl;

    return 0;
}


//int main() {
//    int numRows;
//    std::cout << "Enter the number of rows in the triangle: ";
//    std::cin >> numRows;
//
//    std::vector<int> arr;
//    std::cout << "Enter the flattened triangle elements:" << std::endl;
//    int element;
//    for (int i = 0; i < numRows; i++) {
//        for (int j = 0; j <= i; j++) {
//            std::cin >> element;
//            arr.push_back(element);
//        }
//    }
//
//    int minimumSum = minSum(arr, numRows);
//    std::cout << "Minimum sum path: " << minimumSum << std::endl;
//
//    return 0;
//}