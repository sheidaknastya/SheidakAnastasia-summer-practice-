#include <iostream>
using namespace std;

const int MAX = 1000; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int rows, int cols, int** grid, bool** visited) {
    return x >= 0 && x < rows && y >= 0 && y < cols &&
           grid[x][y] == 1 && !visited[x][y];
}

struct Queue {
    pair<int, int> data[MAX * MAX];
    int front = 0;
    int rear = 0;

    void push(pair<int, int> p) {
        data[rear++] = p;
    }

    pair<int, int> pop() {
        return data[front++];
    }

    bool empty() {
        return front == rear;
    }
};


void bfs(int startX, int startY, int rows, int cols, int** grid, bool** visited) {
    Queue q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> current = q.pop();
        int x = current.first;
        int y = current.second;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY, rows, cols, grid, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int countIslands(int** grid, int rows, int cols) {
    bool** visited = new bool*[rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = new bool[cols];
        for (int j = 0; j < cols; ++j)
            visited[i][j] = false;
    }

    int islands = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, rows, cols, grid, visited);
                ++islands;
            }
        }
    }

    for (int i = 0; i < rows; ++i)
        delete[] visited[i];
    delete[] visited;

    return islands;
}

int main() {
    int rows, cols;
    cout << "Введите количество строк и столбцов (через пробел): ";
    cin >> rows >> cols;

    int** grid = new int*[rows];
    for (int i = 0; i < rows; ++i)
        grid[i] = new int[cols];

    cout << "Введите матрицу (" << rows << " x " << cols << ") значений (0 — вода, 1 — суша):\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> grid[i][j];

    int result = countIslands(grid, rows, cols);
    cout << "\nКоличество островов: " << result << endl;

    for (int i = 0; i < rows; ++i)
        delete[] grid[i];
    delete[] grid;

    return 0;
}
