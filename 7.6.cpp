#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && x < rows && y >= 0 && y < cols &&
            grid[x][y] == 1 && !visited[x][y]);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int i, int j, int rows, int cols, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int newX = current.first + dx[k];
            int newY = current.second + dy[k];

            if (isValid(newX, newY, rows, cols, grid, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int countIslands(const vector<vector<int>>& grid, int rows, int cols) {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int islands = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, rows, cols, grid, visited);
                ++islands;
            }
        }
    }
    return islands;
}

int main() {
    int rows, cols;
    cout << "Введите количество строк и столбцов (через пробел): ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Введите матрицу (" << rows << "x" << cols << ") значений, через пробел (0 - вода, 1 - суша):\n";

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> grid[i][j];

    int result = countIslands(grid, rows, cols);
    cout << "\nКоличество островов: " << result << endl;

    return 0;
}

