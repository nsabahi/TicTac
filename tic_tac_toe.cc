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
  while (x_cord != 0 && x_cord != 1 && x_cord != 2 && y_cord != 0 && y_cord != 1 && y_cord != 2){
    cout << "Enter the x and y coorinates: ";
    cin >> x_cord >> y_cord;
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

bool check_board(string game_board[3][3], const int &x_cord, const int &y_cord){
  if (game_board[y_cord][x_cord] == " "){
    return true;
  }
  return false;
}

int main(int argc, char* argv []){
  int player_turn = 1;
  int x_cord = -1;
  int y_cord = -1;
  string game_board [3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      game_board[i][j] = " ";
    }
  }
  print_board(game_board);
  while (!game_over){
    //cout << "|||||||||||||||||" <<endl;
    get_cord (player_turn, x_cord, y_cord);
    if (check_board(game_board, x_cord, y_cord)){
      if (player_turn == 1){
        game_board [y_cord][x_cord] = "X";
        player_turn = 2;
        x_cord = -1;
        y_cord = -1;
        print_board(game_board);
      }
      else {
        game_board [y_cord][x_cord] = "O";
        player_turn = 1;
        x_cord = -1;
        y_cord = -1;
        print_board(game_board);
      }
    }
    else {
      cerr << "That spot is invalid, try again."<< endl;
      x_cord = -1;
      y_cord = -1;
      get_cord(player_turn, x_cord, y_cord);
    }
    x_cord = -1;
    y_cord = -1;

  }

}
