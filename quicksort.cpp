#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
// partition: dùng để chia 1 dãy thành 2 nửa: nửa bên trái pivot nhỏ hơn pivot, nửa bên phải lớn hơn pivot

int partition(int arr[], int low, int high) {
    // lấy pivot là phần tử cuối cùng của dãy
    int pivot = arr[high];
    // biến i dùng để kiểm tra vị trí tiếp theo đặt phần tử nhỏ hơn vừa đặt vào
    int i = low-1;
    for(int j=low;j<high;j++) {
        // nếu tìm thấy một thằng nhỏ hơn pivot
        if(arr[j]<pivot) {
            // thì tăng biến i lên (để tìm chỗ đặt arr[j] vào), rồi đổi chỗ 2 thằng với nhau
            // tại sao? vì rõ ràng sau i chắc chắn là 1 thằng lớn hơn pivot, đổi chỗ nó với thằng nhỏ hơn
            // vừa tìm được
            // có thể hiểu i+1 là vị trí thằng đầu tiên lớn hơn pivot
            swap(arr[++i],arr[j]);
        }

    }
    // đổi chỗ thằng đầu tiên lớn hơn pivot với pivot để ra dãy đã chia chuẩn
    swap(arr[i+1],arr[high]);
    // trả về vị trí của pivot
    return i+1;
}

void quickSort(int arr[],int low, int high) {
    // quicksort chẳng qua là việc partition liên tục dãy đến khi chỉ còn 2 phần tử trong 1 dãy con
    if(low<high) {
        // chia dãy đã cho thành 2 nửa, pivot lưu vị trí của pivot lúc này
        int pivot = partition(arr,low,high);
        cout << endl << pivot << endl;
        // chia thành nửa trái và nửa phải để chia nhỏ tiếp
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
int main() {
    int arr[8] = {12, 2, 8, 5, 1, 6, 4, 15};
    int n = 8;

    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}