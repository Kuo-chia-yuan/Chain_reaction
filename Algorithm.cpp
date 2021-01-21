#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index) >>The number of the orbs on the cell 
 * 2. int board.get_capacity(int row_index, int col_index) >>The max number of the orbs of a cell
 * 3. char board.get_cell_color(int row_index, int col_index) >>The color of the cell, 'w'(No one has placed the orbs), 'r'(Red Player) and 'b'(Blue player)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){

    //////your algorithm design///////////

    //int row, column;
    int count[5][6] = {0};
    int temp = -1000;
    int color = player.get_color();
    int opp_color;
    if(color == 'r') opp_color = 'b';
    else opp_color = 'r';

    for(int a=0;a<5;a++){
        for(int b=0;b<6;b++){
            if(board.get_cell_color(a, b) == opp_color){
                count[a][b] = -1000;
                continue;
            }
            count[a][b] = (8-(board.get_capacity(a, b) - board.get_orbs_num(a, b)))*2;

            if(a-1<0 || b-1<0 || board.get_cell_color(a-1, b-1) == 'w');
            else if(board.get_cell_color(a-1, b-1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a-1, b-1) - board.get_orbs_num(a-1, b-1)) && board.get_cell_color(a-1, b-1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }
            
            if(a-1<0 || board.get_cell_color(a-1, b) == 'w');
            else if(board.get_cell_color(a-1, b) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a-1, b) - board.get_orbs_num(a-1, b)) && board.get_cell_color(a-1, b) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(a-1<0 || b+1>=6 || board.get_cell_color(a-1, b+1) == 'w');
            else if(board.get_cell_color(a-1, b+1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a-1, b+1) - board.get_orbs_num(a-1, b+1)) && board.get_cell_color(a-1, b+1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(b-1<0 || board.get_cell_color(a, b-1) == 'w');
            else if(board.get_cell_color(a, b-1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a, b-1) - board.get_orbs_num(a, b-1)) && board.get_cell_color(a, b-1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(b+1>=6 || board.get_cell_color(a, b+1) == 'w');
            else if(board.get_cell_color(a, b+1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a, b+1) - board.get_orbs_num(a, b+1)) && board.get_cell_color(a, b+1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(a+1>=5 || b-1<0 || board.get_cell_color(a+1, b-1) == 'w');
            else if(board.get_cell_color(a+1, b-1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a+1, b-1) - board.get_orbs_num(a+1, b-1)) && board.get_cell_color(a+1, b-1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(a+1>=5 || board.get_cell_color(a+1, b) == 'w');
            else if(board.get_cell_color(a+1, b) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a+1, b) - board.get_orbs_num(a+1, b)) && board.get_cell_color(a+1, b) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }

            if(a+1>=5 || b+1>=6 || board.get_cell_color(a+1, b+1) == 'w');
            else if(board.get_cell_color(a+1, b+1) == color){
                count[a][b] ++;
            }
            else if((board.get_capacity(a, b) - board.get_orbs_num(a, b)) <= (board.get_capacity(a+1, b+1) - board.get_orbs_num(a+1, b+1)) && board.get_cell_color(a+1, b+1) == opp_color){
                count[a][b] = count[a][b] + 10;
            }
            else{
                count[a][b] = count[a][b] - 100;
            }
        }
    }
    for(int a=0;a<5;a++){
        for(int b=0;b<6;b++){
            if(count[a][b] > temp){
                temp = count[a][b];
                index[0] = a;
                index[1] = b;
            }
        }
    }
    return;
}
