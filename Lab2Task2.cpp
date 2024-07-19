#include <iostream>
#include <array>
using namespace std;

class TicTacToe{
    private:
    int board[3][3];
    int Status = 0;
  
    public:
    TicTacToe(){
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = 0;
            }
        }
    }
    void clearBoard(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = 0;
            }
        }
    }
    void To_string(){
        for (int i = 0; i < 3; i++){
            cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
            if(i<2){
                cout << "-----------" << endl;
            }   
            }
    }
    int gameStatus() const {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) ||
            (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2)) {
            return board[i][0];  
        }
    }


    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 1) ||
            (board[0][j] == 2 && board[1][j] == 2 && board[2][j] == 2)) {
            return board[0][j];  
        }
    }
    
    if ((board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
        (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)) {
        return board[0][0];  
    }

    if ((board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) ||
        (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)) {
        return board[0][2];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;  
            }
        }
    }
    return 3; 
}

    bool move(int player, int row, int col){
        if (board[row][col] == 0){
            board[row][col] = player;
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    TicTacToe game = TicTacToe();
    int row,player,col;
    while (game.gameStatus()==0){
        game.To_string();
        cout << endl << "Enter player 1 move!"<<endl;
        player = 1;
        cout << "Enter row number"<<endl;
        cin >> row;
        cout << "Enter col number"<<endl;
        cin >> col;
        game.move(player,row,col);
        game.To_string();
        if (game.gameStatus()!=0){
            break;
        }
        if(game.gameStatus()==0){
        cout << endl << "Enter player 2 move!"<<endl;
        player = 2;
        cout << "Enter row number"<<endl;
        cin >> row;
        cout << "Enter col number"<<endl;
        cin >> col;
        game.move(player,row,col);
        
        if (game.gameStatus()!=0){
            break;
        }
        }
    }
    switch (game.gameStatus()){
        case 1:
        cout<<"PLAYER 1 WINS!";
        break;

        case 2:
        cout<<"PLAYER 2 WINS!";
        break;

        default:
        cout<<"GAME DRAW!";
    }
}