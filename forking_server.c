#include "networking.h"

void subserver(int from_client);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();
  int client_socket = server_connect(listen_socket);
  subserver(client_socket);
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];
  int player = 2;
  int winner = -1;
  char board[6][7];//create board
  clear_board(board);//clear it
  print_board(board);//print clean board
  while (1){
  	if (player == 1){
  		int move = get_int(buffer, player);//get input to write
  		int fail = place_piece(board, player, move);//see if move fails
  		if (fail){
  			continue;//start over, new move
  		}
  		print_board(board);
    	write(client_socket, buffer, sizeof(buffer));//give input to opponent
      end_game_server(winner, board, client_socket);
      player = 2;
  	}
  	else{
      read(client_socket, buffer, sizeof(buffer));//read opponent move
      int move = convert_int(buffer);//convert to int
      place_piece(board, player, move);//place piece
      print_board(board);
      end_game_server(winner, board, client_socket);
      player = 1;
  	}
  }
  close(client_socket);
  exit(0);
}
