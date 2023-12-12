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
#define MAX_VERTICES 100// �׷����� �ִ� ���� ��

#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#define black SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#define yellow SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int keyControl();
void titleDraw();
void gotoxy(int, int);
int menuDraw();// ���� �˰��� �׷��� Ʈ��
int sortmenu();//���� �޴�
int menu3();//�������� ���ư��� �� �ٽ� ����
void selectsort(); //���� ����
void bubblesort(); // ��������
void selectionSort(int arr[], int n); //��������
void insertionsort(); //��������
void merge(int arr[], int left, int mid, int right);//�պ�����
void mergeSort(int arr[], int left, int right);//�պ�����
void mergeSortWrapper();//�պ�����
void quickSort(int arr[], int low, int high);//������
int partition(int arr[], int low, int high);//������
void quickSortWrapper();//������
void radixSort(int arr[], int n);//�������
int getMax(int arr[], int n);//�������
void countSort(int arr[], int n, int exp);//�������
void radixSortWrapper();//�������
void heapify(int arr[], int n, int i);//������
void heapSort(int arr[], int n); //������
void heapSortWrapper();//������
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
    system("mode con cols=150 lines=50 | title �˰���");
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
    printf("�������� ���ư���");
    gotoxy(x + 50, y + 9);
    printf(" �ٽ� ����");
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
    printf("> ��������");
    gotoxy(x, y + 2);
    printf(" �������� ");
    gotoxy(x, y + 4);
    printf(" ��������");
    gotoxy(x, y + 6);
    printf(" �պ�����");
    gotoxy(x, y + 8);
    printf(" ������");
    gotoxy(x, y + 10);
    printf(" �������");
    gotoxy(x, y + 12);
    printf(" ������");

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
    printf("> ũ�罺Į");
    gotoxy(x, y + 2);
    printf(" ����");

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
    printf("> ���� Ž�� Ʈ��");
   

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
    printf("> �� ��");
    gotoxy(x, y + 1);
    printf(" �� �� �� ");
    gotoxy(x, y + 2);
    printf(" Ʈ �� ");

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
            // pivot�� �������� �迭�� ������, pivot�� ��ġ�� ã��
            int pivotIndex = partition(arr, low, high);

            // pivot�� �������� ���� �� �κ� �迭�� ���� ��������� ����
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    int partition(int arr[], int low, int high) {
        // pivot�� �迭�� ���� ������ ��ҷ� ����
        int pivot = arr[high];

        // pivot�� �������� ���� ���� ��������, ū ���� ���������� �̵�
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                // ���� ��ҿ� i ��ġ�� ��Ҹ� ��ȯ
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap(i, j, arr);
            }
        }

        // pivot�� ���� ��ġ�� ã�Ƽ� ��ȯ
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
        printf("5���� ������ �Է��Ͻʽÿ�: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        quickSort(arr, 0, n - 1);

        printf("���ĵ� ��: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        _getch(); // ȭ���� �����ϱ� ���� ���
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

        // �ڸ���(exp)�� ���� ���������� ����
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

        // ���� �ڸ����� ���� count �迭�� �󵵼� ����
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % BASE]++;
        }

        // count �迭 ������Ʈ
        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        // output �迭�� ���ĵ� ������� �� ����
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
            count[(arr[i] / exp) % BASE]--;
        }

        // output �迭�� ���� �迭�� ����
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
        printf("5���� ������ �Է��Ͻʽÿ�: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        radixSort(arr, n);

        printf("��� ���� ��: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        _getch(); // ȭ���� �����ϱ� ���� ���
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
        printf("5���� ������ �Է��Ͻʽÿ�: ");
        for (int i = 0; i < 5; i++) {
            scanf_s("%d", &arr[i]);
        }

        heapSort(arr, n);

        printf("�� ���� ��: ");
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

    // Kruskal �˰��� ���� �Լ�
    void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
        system("cls");
        // ������ ����ġ �������� �������� ����
        for (int i = 0; i < numEdges - 1; i++) {
            for (int j = 0; j < numEdges - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    // ���� ��ȯ
                    struct Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        // �θ�� rank �迭�� ���� �޸� �Ҵ�
        int* parent = (int*)malloc(numVertices * sizeof(int));
        int* rank = (int*)malloc(numVertices * sizeof(int));

        // �θ�� rank �迭 �ʱ�ȭ
        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // MST ������ ������ �迭 �ʱ�ȭ
        struct Edge* resultEdges = (struct Edge*)malloc((numVertices - 1) * sizeof(struct Edge));

        int resultIndex = 0; // resultEdges �迭�� �ε���

        // ���ĵ� ������ ��� ������ ��ȸ
        for (int i = 0; i < numEdges; i++) {
            int rootX = find(parent, edges[i].src);
            int rootY = find(parent, edges[i].dest);

            // �� ������ �������� �� ����Ŭ�� �����Ǵ��� Ȯ��
            if (rootX != rootY) {
                // ����� ���� �߰��ϰ� �θ�� rank �迭 ������Ʈ
                resultEdges[resultIndex++] = edges[i];
                unionSets(parent, rank, rootX, rootY);
            }
        }

        // MST ���
        printf("\n�ּ� ���� Ʈ�� (MST):\n");
        for (int i = 0; i < numVertices - 1; i++) {
            printf("���� %d-%d ����ġ: %d\n", resultEdges[i].src, resultEdges[i].dest, resultEdges[i].weight);
        }

        // �Ҵ�� �޸� ����
        free(parent);
        free(rank);
        free(resultEdges);
        while (1) {

        }
    }

    // ���Ұ� ���� ������ ��Ʈ�� ã�� ���� �Լ�
    int find(int parent[], int i) {
        if (parent[i] != i) {
            // ��� ����
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    // �� ������ ��ġ�� ���� �Լ�
    void unionSets(int parent[], int rank[], int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        // �� ���� rank�� ������ �� ���� rank�� ���տ� ��ħ
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            // rank�� ������ �� ���� �����ϰ� rank ����
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // �迭�� ���ĵ��� ���� �κп��� �ּ� ����� �ε����� ã���ϴ�
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ã�� �ּ� ��Ҹ� ù ��° ��ҿ� �ٲߴϴ�
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swap(i, minIndex, arr);

    }
}
void selectsort() {
    system("cls"); // ȭ�� �����
    int arr[5];
    printf("5���� ������ �Է��Ͻʽÿ�: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }

    selectionSort(arr, 5);
    printf("���ĵ� ��: ");
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
                // �� ���Ҹ� ��ȯ
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap(j, j + 1, arr);
            }
        }
    }
}
void bubblesort() {
    system("cls"); // ȭ�� �����
    int arr[5];
    printf("5���� ������ �Է��Ͻʽÿ�: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }
    bubbleSort(arr, 5);
    printf("���ĵ� ��: ");
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

        // key���� ū ���ҵ��� ���������� �̵�
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // key�� �ùٸ� ��ġ�� ����
        arr[j + 1] = key;
        swap(j + 1, j + 1, arr);
    }
}
void insertionsort() {
    system("cls"); // ȭ�� �����
    int arr[5];
    printf("5���� ������ �Է��Ͻʽÿ�: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }
    insertionSort(arr, 5);
    printf("���ĵ� ��: ");
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

    // �ӽ� �迭�� �����ϰ� ������ ����
    int L[MAX_SIZE], R[MAX_SIZE];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // �� �κ� �迭�� ����
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

    // ���� ��� ����
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
        // �� �κ� �迭�� ������ ����
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // �� �κ� �迭�� ����
        merge(arr, left, middle, right);
        mergeswap(left, right, arr);
    }

}
void mergeSortWrapper() {
    system("cls");
    int arr[5];
    int n = 5;
    printf("5���� ������ �Է��Ͻʽÿ�: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("���ĵ� ��: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    _getch(); // ȭ���� �����ϱ� ���� ���
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