#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int inputArray(int arr[]) {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

void printArray(int arr[], int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int countPerfectNumbers(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j <= arr[i] / 2; j++) {
            if (arr[i] % j == 0) sum += j;
        }
        if (sum == arr[i]) count++;
    }
    return count;
}

int findSecondSmallest(int arr[], int n) {
    int min1 = __INT_MAX__, min2 = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    return min2;
}

int addElement(int arr[], int n, int x, int pos) {
    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le!\n");
        return n;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    return n + 1;
}


int deleteElement(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}


int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 1; // Tra ve gia tri de bao ham hoan thanh
}

// Ham kiem tra mang tang dan
bool isAscendingArray(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

// Ham tim kiem tuyen tinh
bool linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

// Ham chinh
int main() {
    int arr[MAX], n = 0, choice, x, pos;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so hoan hao trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri bat ky\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang tang dan\n");
        printf("8. Tim kiem mot phan tu trong mang\n");
        printf("9. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = inputArray(arr);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("So luong so hoan hao: %d\n", countPerfectNumbers(arr, n));
                break;
            case 4:
                printf("Gia tri nho thu 2: %d\n", findSecondSmallest(arr, n));
                break;
            case 5:
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                n = addElement(arr, n, x, pos);
                break;
            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                n = deleteElement(arr, n, pos);
                break;
            case 7:
                bubbleSort(arr, n);
                printf("Mang sau khi sap xep: ");
                printArray(arr, n);
                break;
            case 8:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (linearSearch(arr, n, x)) {
                    printf("Tim thay %d trong mang.\n", x);
                } else {
                    printf("Khong tim thay %d trong mang.\n", x);
                }
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

