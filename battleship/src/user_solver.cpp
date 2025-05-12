#include <iostream>
#include "../include/user_solver.h"

void UserSolver::solve(Board &board) {
    // prepare
    size_t rows = board.getX();
    size_t columns = board.getY();
    // track boxes that have been guessed
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

    int shipsFound = 0;
    int totalShips = static_cast<int>(board.getShipCount());

    // offsets for 4 surrounding
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // walk through each box till all ships are found
    for (size_t i = 0; i < rows && shipsFound < totalShips; i++) {
        for (size_t j = 0; j < columns && shipsFound < totalShips; j++) {
            if (visited[i][j]) continue;
            visited[i][j] = true;

            // player guesses
            ReturnType res = guess(i, j, board);

            // reaction based on result
            switch (res) {
                case hit:
                    // ship found
                        ++shipsFound;
                break;
                case near_miss:
                    // one of 4 surrounding boxes must be a ship
                        for (int k = 0; k < 4; ++k) {
                            int ni = static_cast<int>(i) + dx[k];
                            int nj = static_cast<int>(j) + dy[k];

                            // stay in bounds and haven't tried yet
                            if ( ni < 0 || ni >= static_cast<int>(rows)
                                || nj < 0 || nj >= static_cast<int>(columns)
                                || visited[ni][nj]) {
                            continue ;
                            }

                            visited[ni][nj] = true;
                            ReturnType res2 = guess(ni, nj, board);
                            if (res2 == hit) {
                                ++shipsFound;
                                break; // don't need to check other surrounding boxes
                            }
                        }
                break;

                default:
                    // miss or bad guess-- move on
                        break;
            }
        }
    }
    //ReturnType t = guess(1, 1, board);
    //std::cout << t << std::endl;
}
