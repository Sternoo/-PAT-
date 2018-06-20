#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int n, i, j;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < n - 1 && b[i] <= b[i+1]; i++);//注意判断小于等于！！开始漏了等于，查找了半天
    for (j = i + 1; j < n && a[j] == b[j]; j++);
    if (j == n) {
        printf("Insertion Sort\n");
        qsort(a, i + 2, sizeof(int), cmp);
    } else {
        printf("Merge Sort\n");
        int k = 2;
        for (i = 0; i < n && k <= n; k *= 2) {
            //若a和b相等时，i自然等于n，那么再进行一次排序就是所求结果
            for (i = 0; i < n && a[i] == b[i]; i++);
            for (j = 0; j < n / k; j ++)
                qsort(a + j * k, k, sizeof(int), cmp);
            qsort(a + j * k, n % k, sizeof(int), cmp);
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//
//void merge(int a[], int start, int mid, int end) {
//    int n1 = mid - start + 1;
//    int n2 = end - mid;
//    int left[n1], right[n2];
//    int i, j ,k;
//    
//    for (i = 0; i < n1; i++)
//        left[i] = a[start+i];
//    for (j = 0; j < n2; j++)
//        right[j] = a[mid+1+j];
//    
//    i = j = 0;
//    k = start;
//    while (i < n1 && j < n2)
//        if (left[i] < right[j])
//            a[k++] = left[i++];
//        else
//            a[k++] = right[j++];
//    
//    while (i < n1)
//        a[k++] = left[i++];
//    while (j < n2)
//        a[k++] = right[j++];
//}
//
//void merge_sort(int a[], int start, int end) {
//    int mid;
//    if (start < end) {
//        mid = (start + end) / 2;
//        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
//               start, mid, mid+1, end,
//               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
//        merge_sort(a, start, mid);
//        merge_sort(a, mid + 1, end);
//        merge(a, start, mid, end);
//        printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n",
//               start, mid, mid+1, end,
//               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    
//    int a[8] = { 5, 2, 4, 7, 1, 3, 2, 6 };
//    merge_sort(a, 0, 7);
//    
//    return 0;
//}
