#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX_SIZE 100
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define HEAP_SORT 5
#define MERGE_SORT 6
#define MAX_VERTICES 100// 그래프의 최대 정점 수

#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#define black SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#define yellow SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int keyControl();
void titleDraw();
void gotoxy(int, int);
int menuDraw();// 정렬 알고리즘 그래프 트리
int sortmenu();//정렬 메뉴
int menu3();//메인으로 돌아가기 및 다시 실행
void selectsort(); //선택 정렬
void bubblesort(); // 버블정렬
void selectionSort(int arr[], int n); //선택정렬
void insertionsort(); //삽입정렬
void merge(int arr[], int left, int mid, int right);//합병정렬
void mergeSort(int arr[], int left, int right);//합병정렬
void mergeSortWrapper();//합병정렬
void quickSort(int arr[], int low, int high);//퀵정렬
int partition(int arr[], int low, int high);//퀵정렬
void quickSortWrapper();//퀵정렬
void radixSort(int arr[], int n);//기수정렬
int getMax(int arr[], int n);//기수정렬
void countSort(int arr[], int n, int exp);//기수정렬
void radixSortWrapper();//기수정렬
void heapify(int arr[], int n, int i);//힙정렬
void heapSort(int arr[], int n); //힙정렬
void heapSortWrapper();//힙정렬
int grapemenu();
void kruskalMST(struct Edge edges[], int numVertices, int numEdges);
int find(int parent[], int i);
void unionSets(int parent[], int rank[], int x, int y);
void printGraph(int graph[][MAX_VERTICES], int numVertices);
int grapemenu();
int treemenu();


void swap(int a, int b, int* arr);
void mergeswap(int a, int b, int* arr);
void SWAP(int* a, int* b, int* arr);

struct Edge {
    int src, dest, weight;
};

void init() {
    system("mode con cols=150 lines=50 | title 알고리즘");
}

int main() {
    init();
    titleDraw();

    while (1) {
        int menuCode = menuDraw();
        if (menuCode == 0) {
            int menuCode = sortmenu();
            if (menuCode == 0) {
                selectsort();
            }
            else if (menuCode == 2) {
                bubblesort();
            }
            else if (menuCode == 4) {
                insertionsort();
            }
            else if (menuCode == 6) {
                mergeSortWrapper();
            }
            else if (menuCode == 8) {
                quickSortWrapper();
            }
            else if (menuCode == 10) {
                radixSortWrapper();
            }
            else if (menuCode == 12) {
                 heapSortWrapper();
        }
    }   
        else if (menuCode == 1) {
            int menuCode = grapemenu();
            if (menuCode == 0) {
                int numVertices = 0;
                int numEdges=0;
                struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
                kruskalMST(edges, numVertices, numEdges);


            }

        }

        else if (menuCode == 2) {
            int menuCode = treemenu();
      
        }

 }
    return 0;


}
int menu3() {
    int x = 0;
    int y = 0;
    red;
    gotoxy(x + 30, y + 9);
    printf(">");
    gotoxy(x + 32, y + 9);
    black;
    printf("메인으로 돌아가기");
    gotoxy(x + 50, y + 9);
    printf(" 다시 실행");
    int x1 = x;
    while (1) {
        int n = keyControl();
        switch (n) {
        case RIGHT: {
            if (x < x1 + 20) {
                gotoxy(x + 30, y + 9);
                printf(" ");
                red;
                x = x + 20;
                gotoxy(x + 30, y + 9);
                printf(">");
                black;
            }
            break;
        }
        case LEFT: {
            if (x >= x1 + 20) {
                gotoxy(x + 30, y + 9);
                printf(" ");
                red;
                x = x - 20;
                gotoxy(x + 30, y + 9);
                printf(">");
                black;
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return x - x1;
        }
        }
    }
}
int sortmenu() {
    int x = 65;
    int y = 15;
    gotoxy(x - 1, y);
    printf("> 선택정렬");
    gotoxy(x, y + 2);
    printf(" 버블정렬 ");
    gotoxy(x, y + 4);
    printf(" 삽입정렬");
    gotoxy(x, y + 6);
    printf(" 합병정렬");
    gotoxy(x, y + 8);
    printf(" 퀵정렬");
    gotoxy(x, y + 10);
    printf(" 기수정렬");
    gotoxy(x, y + 12);
    printf(" 힙정렬");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 1, y);
                printf("  ");
                y--;
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 29) {
                gotoxy(x - 1, y);
                printf(" ");
                y++;
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 15;
        }

                   break;
        }
    }
}

int grapemenu() {
    int x = 65;
    int y = 15;
    gotoxy(x - 1, y);
    printf("> 크루스칼");
    gotoxy(x, y + 2);
    printf(" 프림");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 1, y);
                printf("  ");
                y--;
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 29) {
                gotoxy(x - 1, y);
                printf(" ");
                y++;
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 15;
        }

                   break;
        }
    }
}

int treemenu() {
    int x = 65;
    int y = 15;
    gotoxy(x - 1, y);
    printf("> 이진 탐색 트리");
   

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 1, y);
                printf("  ");
                y--;
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 29) {
                gotoxy(x - 1, y);
                printf(" ");
                y++;
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 15;
        }

                   break;
        }
    }
}

void titleDraw() {
    int x = 20, y = 5;
    gotoxy(x, y);
    printf("     #     #      ####    ####     #####    #####   #####   #   #    #       #\n");
    gotoxy(x, y + 1);
    printf("    # #    #     #       #    #    #    #     #       #     #   #    ##     ##\n");
    gotoxy(x, y + 2);
    printf("   #####   #     #   ##  #    #    ####       #       #     #####    # #   # #\n");
    gotoxy(x, y + 3);
    printf("   #   #   #     #    #  #    #    #   #      #       #     #   #    #  # #  #\n");
    gotoxy(x, y + 4);
    printf("   #   #   ####   ####    ####     #    #   #####     #     #   #    #   #   #\n");
}
void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W' || temp == 72) {
        return UP;
    }
    else if (temp == 'a' || temp == 'A' || temp == 75) {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S' || temp == 80) {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D' || temp == 77) {
        return RIGHT;
    }
    else if (temp == ' ' || temp == 13) {
        return SUBMIT;
    }
}
int menuDraw() {
    int x = 48;
    int y = 15;
    gotoxy(x - 1, y);
    printf("> 정 렬");
    gotoxy(x, y + 1);
    printf(" 그 래 프 ");
    gotoxy(x, y + 2);
    printf(" 트 리 ");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 1, y);
                printf("  ");
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 18) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 15;
        }
        }
    }
}


void swap(int a, int b, int* arr) {
    for (int j = 0; j < 5; j++) {
        if (j == a || j == b) {
            red;
            printf("%d ", arr[j]);
            black;
        }
        else {
            printf("%d ", arr[j]);
        }
    }
    if (a == b) {
        printf("\n");
    }
    else {
        printf("swap %d,%d\n", arr[a], arr[b]);
    }



}
void mergeswap(int a, int b, int* arr) {
    for (int j = 0; j < 5; j++) {
        if (j >= a && j <= b) {
            red;
            printf("%d ", arr[j]);
            black;
        }
        else {
            printf("%d ", arr[j]);
        }

    }
    printf("\n");

}



    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            // pivot을 기준으로 배열을 나누고, pivot의 위치를 찾음
            int pivotIndex = partition(arr, low, high);

            // pivot을 기준으로 나눈 두 부분 배열에 대해 재귀적으로 정렬
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    int partition(int arr[], int low, int high) {
        // pivot을 배열의 가장 오른쪽 요소로 선택
        int pivot = arr[high];

        // pivot을 기준으로 작은 값은 왼쪽으로, 큰 값은 오른쪽으로 이동
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                // 현재 요소와 i 위치의 요소를 교환
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap(i, j, arr);
            }
        }

        // pivot의 최종 위치를 찾아서 교환
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swap(i + 1, high, arr);

        return i + 1;
    }

    void quickSortWrapper() {
        system("cls");
        int arr[5];
        int n = 5;
        printf("5개의 정수를 입력하십시오: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        quickSort(arr, 0, n - 1);

        printf("정렬된 값: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        _getch(); // 화면을 유지하기 위해 사용
        while (1) {
            int menuCode = menu3();
            if (menuCode == 20) {
                selectsort();
            }
            else if (menuCode == 0) {
                main();
            }
        }
    }

    void radixSort(int arr[], int n) {
        int max = getMax(arr, n);

        // 자리수(exp)에 따라 순차적으로 정렬
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countSort(arr, n, exp);
        }
    }

    int getMax(int arr[], int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    void countSort(int arr[], int n, int exp) {
        const int BASE = 10;
        int* output = (int*)malloc(n * sizeof(int*));
        int count[BASE];
        for (int i = 0; i < BASE; i++) {
            count[i] = 0;
        }

        // 현재 자리수에 따라 count 배열에 빈도수 저장
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % BASE]++;
        }

        // count 배열 업데이트
        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        // output 배열에 정렬된 순서대로 값 저장
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
            count[(arr[i] / exp) % BASE]--;
        }

        // output 배열을 원래 배열로 복사
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void radixSortWrapper() {
        system("cls");
        int arr[5];
        int n = 5;
        printf("5개의 정수를 입력하십시오: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        radixSort(arr, n);

        printf("기수 정렬 후: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        _getch(); // 화면을 유지하기 위해 사용
        while (1) {
            int menuCode = menu3();
            if (menuCode == 20) {
                selectsort();
            }

            else if (menuCode == 0) {
                main();
            }
        }
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;


        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            //SWAP(&i, &largest, arr);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            //SWAP(0, &i, arr);
            heapify(arr, i, 0);
        }
    }

    void heapSortWrapper() {
        system("cls");
        int arr[5];
        int n = 5;
        printf("5개의 정수를 입력하십시오: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        heapSort(arr, n);

        printf("힙 정렬 후: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        _getch();
        while (1) {
            int menuCode = menu3();
            if (menuCode == 20) {
                selectsort();
            }
            else if (menuCode == 0) {
                main();
            }
        }
    }

    // Kruskal 알고리즘 수행 함수
    void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
        system("cls");
        // 간선을 가중치 기준으로 오름차순 정렬
        for (int i = 0; i < numEdges - 1; i++) {
            for (int j = 0; j < numEdges - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    // 간선 교환
                    struct Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        // 부모와 rank 배열을 위한 메모리 할당
        int* parent = (int*)malloc(numVertices * sizeof(int));
        int* rank = (int*)malloc(numVertices * sizeof(int));

        // 부모와 rank 배열 초기화
        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // MST 간선을 저장할 배열 초기화
        struct Edge* resultEdges = (struct Edge*)malloc((numVertices - 1) * sizeof(struct Edge));

        int resultIndex = 0; // resultEdges 배열의 인덱스

        // 정렬된 순서로 모든 간선을 순회
        for (int i = 0; i < numEdges; i++) {
            int rootX = find(parent, edges[i].src);
            int rootY = find(parent, edges[i].dest);

            // 이 간선을 포함했을 때 사이클이 형성되는지 확인
            if (rootX != rootY) {
                // 결과에 간선 추가하고 부모와 rank 배열 업데이트
                resultEdges[resultIndex++] = edges[i];
                unionSets(parent, rank, rootX, rootY);
            }
        }

        // MST 출력
        printf("\n최소 신장 트리 (MST):\n");
        for (int i = 0; i < numVertices - 1; i++) {
            printf("간선 %d-%d 가중치: %d\n", resultEdges[i].src, resultEdges[i].dest, resultEdges[i].weight);
        }

        // 할당된 메모리 해제
        free(parent);
        free(rank);
        free(resultEdges);
        while (1) {

        }
    }

    // 원소가 속한 집합의 루트를 찾는 보조 함수
    int find(int parent[], int i) {
        if (parent[i] != i) {
            // 경로 압축
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    // 두 집합을 합치는 보조 함수
    void unionSets(int parent[], int rank[], int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        // 더 낮은 rank의 집합을 더 높은 rank의 집합에 합침
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            // rank가 같으면 한 쪽을 선택하고 rank 증가
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // 배열의 정렬되지 않은 부분에서 최소 요소의 인덱스를 찾습니다
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 찾은 최소 요소를 첫 번째 요소와 바꿉니다
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swap(i, minIndex, arr);

    }
}
void selectsort() {
    system("cls"); // 화면 지우기
    int arr[5];
    printf("5개의 정수를 입력하십시오: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }

    selectionSort(arr, 5);
    printf("정렬된 값: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    _getch();
    while (1) {
        int menuCode = menu3();
        if (menuCode == 20) {
            selectsort();
        }
        else if (menuCode == 0) {
            main();
        }
    }
}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 두 원소를 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap(j, j + 1, arr);
            }
        }
    }
}
void bubblesort() {
    system("cls"); // 화면 지우기
    int arr[5];
    printf("5개의 정수를 입력하십시오: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }
    bubbleSort(arr, 5);
    printf("정렬된 값: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    _getch();
    while (1) {
        int menuCode = menu3();
        if (menuCode == 20) {
            bubblesort();
        }
        else if (menuCode == 0) {
            main();
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // key보다 큰 원소들을 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // key를 올바른 위치에 삽입
        arr[j + 1] = key;
        swap(j + 1, j + 1, arr);
    }
}
void insertionsort() {
    system("cls"); // 화면 지우기
    int arr[5];
    printf("5개의 정수를 입력하십시오: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }
    insertionSort(arr, 5);
    printf("정렬된 값: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    _getch();
    while (1) {
        int menuCode = menu3();
        if (menuCode == 20) {
            insertionsort();
        }
        else if (menuCode == 0) {
            main();
        }
    }
}

void merge(int arr[], int left, int middle, int right) {
    int x = 40;
    int y = 40;
    int i, j, k;

    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 배열을 생성하고 데이터 복사
    int L[MAX_SIZE], R[MAX_SIZE];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // 두 부분 배열을 병합
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[], int left, int right) {
    int x = 0;
    int y = 0;
    int middle = (left + right) / 2;
    if (left < right) {
        // 두 부분 배열을 나누고 정렬
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // 두 부분 배열을 병합
        merge(arr, left, middle, right);
        mergeswap(left, right, arr);
    }

}
void mergeSortWrapper() {
    system("cls");
    int arr[5];
    int n = 5;
    printf("5개의 정수를 입력하십시오: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("정렬된 값: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    _getch(); // 화면을 유지하기 위해 사용
    while (1) {
        int menuCode = menu3();
        if (menuCode == 20) {
            selectsort();
        }
        else if (menuCode == 0) {
            main();
        }
    }
    
}