#include "networking.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  if (argc == 2)
    server_socket = client_setup(argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  int player = 2;
  int winner = -1;
  char board[6][7];//create board
  clear_board(board);//clear it
  print_board(board);//print clean board
  while (1) {
  	if (player == 1){
  		read(server_socket, buffer, sizeof(buffer));//read opponent move
  		int move = convert_int(buffer);//convert to int
  		place_piece(board, player, move);//place piece
  		print_board(board);
      end_game_client(winner, board, server_socket);
      player = 2;
  	}
  	else{
  		int move = get_int(buffer, player);//get input to write
  		int fail = place_piece(board, player, move);//see if move fails
  		if (fail){
  			continue;//start over, new move
  		}
  		print_board(board);
    	write(server_socket, buffer, sizeof(buffer));//give input to opponent
      end_game_client(winner, board, server_socket);
      player = 1;
  	}
  }
}
