#include <iostream>
#include <cctype>
#include <vector>

int getRowMoveCount(char board[3][3], char target, int row);
int getColumnMoveCount(char board[3][3], char target, int column);
int getDiagonalMoveCount(char board[3][3], char target, std::string direction); // Direction is either "TL BR" or "TR BL"
int getAvailableColumnByRow(char board[3][3], int row); // Returns the INDEX of the column
int getAvailableRowByColumn(char board[3][3], int column); // Returns the INDEX of the row
std::vector<int> getAvailableCellDiagonally(char board[3][3], std::string direction); // Direction is either "TL BR" or "TR BL"
bool isCellAvailable(char board[3][3], int row, int col);
bool isBoardFull(char board[3][3]);
void getUserMove(char board[3][3], char userChar, char computerChar);
void makeComputerMove(char board[3][3], char computerChar, char userChar);
void displayBoard(char board[3][3]);
void displayWinner(char board[3][3], char userChar, char computerChar);

int main() 
{
    char board[3][3] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}};

    getUserMove(board, 'X', 'O');

    return 0;
}

int getRowMoveCount(char board[3][3], char target, int row){
    int count {0};
    for (int i = 0; i < 3; i++){
        if (board[row][i] == target){
            count++;
        }
    }

    return count;
}

int getColumnMoveCount(char board[3][3], char target, int column){
    int count = {0};
    for (int i = 0; i < 3; i++){
        if (board[i][column] == target){
            count++;
        }
    }

    return count;
}

int getDiagonalMoveCount(char board[3][3], char target, std::string direction){
    int count = {0};

    if (direction == "TL BR"){ // Top left to bottom right
        for (int i = 0; i<3; i++){
            if (board[i][i] == target) {
                count++;
            }
        }
    }else if (direction == "TR BL") { // Top right to bottom left
        int col = 2;
        for (int j = 0; j<3; j++){
            if (board[j][col] == target) {
                count++;
            }
            col--; 
        } 
    }

    return count;
}

int getAvailableColumnByRow(char board[3][3], int row){ 
    int a = -1;

    for (int i = 0; i < 3; i++){
        if (board[row][i] == ' '){
            a = i;
        }
    }

    return a;
}

int getAvailableRowByColumn(char board[3][3], int column) { 
    int a = -1;

    for (int i = 0; i < 3; i++){
        if (board[i][column] == ' '){
            a = i;
        }
    }

    return a;
}

std::vector<int> getAvailableCellDiagonally(char board[3][3], std::string direction){
    if (getDiagonalMoveCount(board, ' ', direction) == 0){
        return std::vector<int>{-1,-1};
    }

    if (direction == "TL BR"){
        for (int i = 0; i < 3; i++){
            if (isCellAvailable(board, i, i)){
                return std::vector<int>{i,i};
            }
        }
    }else if (direction == "TR BL"){
        int col = 2;
        for (int i = 0; i<3; i++){
            if (isCellAvailable(board, i, col)) {
                return std::vector<int>{i,col};
            }
            col--; 
        } 
    }

    return std::vector<int>{-1,-1};
}

bool isCellAvailable(char board[3][3], int row, int col){
    return board[row][col] == ' ';
}

bool isBoardFull(char board[3][3]){
    int available = 0;
        
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (isCellAvailable(board, i, j)){
                available++;
            }
        }
    }

    return available == 0;
}

void getUserMove(char board[3][3], char userChar, char computerChar){
    int row = -1;
    int column = -1;

    // Display the board
    displayBoard(board);
    
    while(true){
        // Get the row
        while (row == -1){
            std::cout << "\nPlease type in the row: ";
            std::cin >> row;

            if (row < 1 || row > 3){
                std::cout << "\nInvalid row, please input a number (1-3)";
                row = -1;
            }
        }

        // Get the column
        while (column == -1){
            std::cout << "Please type in the column: ";
            std::cin >> column;

            if (column < 1 || column > 3){
                std::cout << "\nInvalid column, please input a number (1-3)\n";
                column = -1;
            }
        }

        // Check if the cell is occupied
        if (isCellAvailable(board, row-1, column-1)){
            break;
        }else {
            std::cout << "\nThat cell is occupied. Please try again";
            row = -1;
            column = -1;
        }
    }

    // Apply Change
    board[row-1][column-1] = userChar; 

    // Check if anyone won
    displayWinner(board, userChar, computerChar);

    // Move to the computer
    makeComputerMove(board, computerChar, userChar);
}

void makeComputerMove(char board[3][3], char computerChar, char userChar){
    int row = -1;
    int column = -1;

    // Check if the computer is 1 away vertically
    for (int i = 0; i < 3; i++){ // i represents the columns in this case
        int availableRow = getAvailableRowByColumn(board, i);

        if (getColumnMoveCount(board, computerChar, i) == 2 && availableRow != -1){
            column = i;
            row = availableRow;
            break;
        }
    }

    // Check if the computer is 1 away horizontally
    if (row == -1) {
        for (int i = 0; i < 3; i++){
            int availableColumn = getAvailableColumnByRow(board, i);

            if (getRowMoveCount(board, computerChar, i) == 2 && availableColumn != -1){
                row = i;
                column = availableColumn;
                break;
            }
        }
    }

    // Check if the computer is 1 away diagonally
    if (row == -1){ 
        if (getDiagonalMoveCount(board, computerChar, "TL BR") == 2){
            std::vector<int> availableCell = getAvailableCellDiagonally(board, "TL BR");

            row = availableCell[0];
            column = availableCell[1];
        }else if (getDiagonalMoveCount(board, computerChar, "TR BL") == 2) {
            std::vector<int> availableCell = getAvailableCellDiagonally(board, "TR BL");

            row = availableCell[0];
            column = availableCell[1];
        }
    }

    // Check if the user is 1 away vertically
    if (row == -1) {
        for (int i = 0; i < 3; i++){ // i represents the columns in this case
            int userMoves {getColumnMoveCount(board, userChar, i)};
            int availableRow {getAvailableRowByColumn(board, i)};

            if (userMoves == 2 && availableRow != -1){
                column = i;
                row = availableRow;
                break;
            }
        }
    }

    // Check if the user is 1 away horizontally
    if (row == -1) {
        for (int i = 0; i < 3; i++){
            int userMoves {getRowMoveCount(board, userChar, i)};
            int availableColumn {getAvailableColumnByRow(board, i)};

            if (userMoves == 2 && availableColumn != -1){
                row = i;
                column = availableColumn;
                break;
            }
        }
    }

    // Check if the user is 1 away diagonally
    if (row == -1){
        std::vector<int> availableCell;

        if (getDiagonalMoveCount(board, userChar, "TL BR") == 2 && getDiagonalMoveCount(board, computerChar, "TL BR") == 0){
            availableCell = getAvailableCellDiagonally(board, "TL BR");

            row = availableCell[0];
            column = availableCell[1];
        }else if (getDiagonalMoveCount(board, userChar, "TR BL") == 2 && getDiagonalMoveCount(board, computerChar, "TR BL") == 0) {
            availableCell = getAvailableCellDiagonally(board, "TR BL");
            row = availableCell[0];
            column = availableCell[1];
        }

        
    }

    // Try for offensives
    // ... the bot first finds opportunities in which it can win right then and there
    // ... if not any, it attempts to take either the center or one of the corners
    
    if (row == -1){
        // Attempt to get the center or corner if applicable
        if (row == -1){
            if (isCellAvailable(board, 1, 1)){
                row = 1;
                column = 1;
            }else if (isCellAvailable(board, 0, 0)){
                row = 0;
                column = 0;
            }else if (isCellAvailable(board, 0, 2)){
                row = 0;
                column = 2;
            }else if (isCellAvailable(board, 2, 2)){
                row = 2;
                column = 2;
            }else if (isCellAvailable(board, 2, 0)){
                row = 2;
                column = 0;
            }else {
                // Decide a random location
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3 && row == -1; j++){
                        if (board[i][j] != userChar && board[i][j] != computerChar) {
                            row = i;
                            column = j;
                            break;
                        }
                    }
                }
            }
        }
    }

    

    // Apply the computers change
    board[row][column] = computerChar;

    // Check if anyone won
    displayWinner(board, userChar, computerChar);

    // Move to the user
    getUserMove(board, userChar, computerChar);
}

void displayBoard(char board[3][3]){
    for (int i = 0; i < 3; i++){
        std::cout << '\n' << '|';
        for (int j = 0; j < 3; j++){
            std::cout << board[i][j] << "|";
            
        }
    }
}

void displayWinner (char board[3][3], char userChar, char computerChar){

    std::string winner = "";

    // Vertical Check
    for (int i = 0; i < 3; i++){ // i represents the columns in this case
        if (getColumnMoveCount(board, userChar, i) == 3){
            winner = "User";
        }else if (getColumnMoveCount(board, computerChar, i) == 3){
            winner = "Computer";
        }
    }

    // Horizontal Check
    for (int i = 0; i < 3; i++){
        if (getRowMoveCount(board, userChar, i) == 3){
            winner = "User";
        }else if (getRowMoveCount(board, computerChar, i) == 3){
            winner = "Computer";
        }
    }

    // Diagonal Check
    if(getDiagonalMoveCount(board, userChar, "TL BR") == 3 || getDiagonalMoveCount(board, userChar, "TR BL") == 3){
        winner = "User";
    } else if (getDiagonalMoveCount(board, computerChar, "TL BR") == 3 || getDiagonalMoveCount(board, computerChar, "TR BL") == 3){
        winner = "Computer";
    }

    // Tie check
    if (winner == "" && isBoardFull(board)){
        winner = "Nobody (Tie)";
    }

    if (winner == "" && isBoardFull(board) != true){
        return;
    }

    // Display the board
    displayBoard(board);

    std::cout << "\nThe winner is: " << winner << "!\n";

    char choice {' '};

    while (choice == ' ') {
        std::cout << "\nWould you like to play another round? (Y/N)\n> ";
        std::cin >> choice;

        choice = std::tolower(choice);

        if (choice != 'y' && choice != 'n'){
            std::cout << "\nPlease enter a valid response (Y/N)";
            choice = ' ';
        }
    }

    if (choice == 'y'){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = ' ';
            }
        }
    }else if (choice == 'n'){
        exit(0);
    }
}
