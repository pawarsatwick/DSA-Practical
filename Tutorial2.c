#include <stdio.h>

int BS(int arr[], int l, int r, int target);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int target;

    printf("Enter target number: \n");
    scanf("%d", &target);

    int result = BS(arr, 0, n - 1, target);

    if (result == 1) {
        printf("The target is found \n");
    } else {
        printf("The target is not found \n");
    }

    return 0;
}

int BS(int arr[], int l, int r, int target) {
    if (l > r)
        return 0;

    int mid = l + (r - l) / 2;

    if (arr[mid] == target)
        return 1;
    else if (arr[mid] > target)
        return BS(arr, l, mid - 1, target);
    else
        return BS(arr, mid + 1, r, target);
}
