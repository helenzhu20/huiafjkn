#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <ifaddrs.h>

#ifndef NETWORKING_H
#define NETWORKING_H

#define BUFFER_SIZE 256
#define PORT "9001"
#define TEST_IP "127.0.0.1"

#define MAX_CLIENTS 10
#define LISTEN 0

void error_check( int i, char *s );
void error_check_sock( int i, char *s, int sd );

int server_setup();
int server_connect(int sd);

int client_setup(char * server);

int convert_int(char *buffer);
int get_int(char *buffer, char player);
int real_row(int r);
int real_col(int c);
int place_piece(char board[6][7], char player, int c);
void print_hole(char player);
void print_board(char board[6][7]);
void clear_board(char board[6][7]);
int full(char board[6][7]);
char check_winner(char board[6][7], int r, int c, int dr, int dc);
char get_winner(char board[6][7]);
void show_result(char winner);
void end_game_server(int winner, char board[6][7], int client_socket);
void end_game_client(int winner, char board[6][7], int server_socket);
#endif
