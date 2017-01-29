#include <iostream>
using namespace std;

bool game_over = false;
#define SPACE = " ";

void print_board(string game_board[3][3]){
  cout << "    0   1   2 "<< endl;
  for (int i = 0; i < 3; i ++){
    cout << i << "   ";
    cout << game_board[i][0] << " | " << game_board[i][1] << " | " << game_board[i][2] <<endl;
    if (i < 2){
      cout << "  -------------" << endl;
    }
  }
}

void get_cord(int player_turn, int & x_cord, int & y_cord){
  if (player_turn == 1){
    cout << "Player 1's turn. ";
  }
  else{
    cout << "Player 2's turn. ";
  }
  while (x_cord != 0 && x_cord != 1 && x_cord != 2 && y_cord != 0 && y_cord != 1 && y_cord != 2){
    cout << "Enter the x and y coorinates: ";
    //Problem occur when user enters a non-integer.
    cin >> x_cord;
    cin >> y_cord;
    if (x_cord != 0 && x_cord != 1 && x_cord != 2){
      cerr << "Invalid x-coordinate, try again." << endl;
      x_cord = -1;
      y_cord = -1;
    }
    else if (y_cord != 0 && y_cord != 1 && y_cord != 2){
      cerr << "Invalid y-coordinate, try again." << endl;
      x_cord = -1;
      y_cord = -1;
    }
  }
}

void win_check(string game_board[3][3], int & winner, const int & turn_count){
  //Check horizontal win
  int full_board = 0;
  for (int i = 0; i < 3; i++){
    if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]){
      if (game_board[i][0] == "X"){
        winner = 1;
      }
      else if (game_board[i][0] == "O"){
        winner = 2;
      }
    }
    //Vertical check
    if(game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i]){
      if (game_board[0][i] == "X"){
        winner = 1;
      }
      else if (game_board[0][i] == "O"){
        winner = 2;
      }
    }
  }
  if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]){
    if (game_board[1][1] == "X"){
      winner = 1;
    }
    else if (game_board[1][1] == "O"){
      winner = 2;
    }
  }
  if (game_board[2][0] == game_board[1][1] && game_board[1][1] == game_board[0][2]){
    if (game_board[1][1] == "X"){
      winner = 1;
    }
    else if (game_board[1][1] == "O"){
      winner = 2;
    }
  }
  if (turn_count == 9){
    if (winner != 1 && winner != 2){
      winner = 3;
    }
  }
}

bool check_board(string game_board[3][3], const int &x_cord, const int &y_cord){
  if (game_board[y_cord][x_cord] == " "){
    return true;
  }
  return false;
}

int main(int argc, char* argv []){
  int winner = 0;
  int player_turn = 1;
  int x_cord = -1;
  int y_cord = -1;
  int turn_count = 0;
  bool restart = true;
  string play_again;

  //Game setup
  cout << "-----------------" << endl;
  cout << "|  TIC TAC TOE  |" << endl;
  cout << "-----------------" << endl;
  cout << "Wlecome to TIC TAC TOE" <<endl;
  cout << "- Player 1 = X and Player 2 = O" <<endl;
  cout << "- Enter 'q' at anytime to quit the game" <<endl;
  cout << endl;

  while (restart){
    player_turn = 1;
    string game_board [3][3];
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        game_board[i][j] = " ";
      }
    }
    print_board(game_board);
    while (0 == winner){
      //cout << "|||||||||||||||||" <<endl;
      get_cord (player_turn, x_cord, y_cord);
      if (check_board(game_board, x_cord, y_cord)){
        if (player_turn == 1){
          game_board [y_cord][x_cord] = "X";
          player_turn = 2;
          turn_count++;
          x_cord = -1;
          y_cord = -1;
          print_board(game_board);
        }
        else {
          game_board [y_cord][x_cord] = "O";
          player_turn = 1;
          turn_count++;
          x_cord = -1;
          y_cord = -1;
          print_board(game_board);
        }
      }
      else {
        cerr << "That spot is invalid, try again."<< endl;
        x_cord = -1;
        y_cord = -1;
        //get_cord(player_turn, x_cord, y_cord);
      }
      x_cord = -1;
      y_cord = -1;

      win_check(game_board, winner, turn_count);
    }
    cout << "GAME OVER: ";
    if (winner == 1){
      cout << "Congratulations! Player 1 wins!" << endl;
    }
    else if (winner == 2){
      cout << "Congratulations! Player 2 wins!" << endl;
    }
    else{
      cout << "Tie Game" << endl;
    }

    cout << "Would you like to play again? (y or n): ";
    cin >> play_again;
    if (play_again == "y" || play_again == "N"){
      restart = true;
      winner = 0;
    }
    else  restart = false;
  }

  cout << "Thanks for playing!" << endl;

}
