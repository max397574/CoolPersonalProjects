#include <iostream>

#define PLAYER_1 1
#define PLAYER_2 2


int winner(char* board)
{
    int winning_opts[8][3]={
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6},
    };
    bool player_1_won = false;
    bool player_2_won = false;
    for (int i = 0; i < 8; i++)
    {
        int a = winning_opts[i][0];
        int b = winning_opts[i][1];
        int c = winning_opts[i][2];
        if (board[a]==board[b] && board[b]==board[c])
        {
            if (board[a]== 'x')
            {
                player_1_won = true;
            }
            else
            {
                player_2_won = true;
            }
        }
    }

    if (player_1_won)
    {
        return PLAYER_1;
    }
    else if (player_2_won)
    {
        return PLAYER_2;
    }
    return 0;
}

/**
* @brief Prints out the board
*/
void print_board(char* board)
{
    std::cout << "Input the number for the field you want" << std::endl;
    std::cout << " " <<board[0]<<" | "<<board[1]<<" | "<<board[2]<<" " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " <<board[3]<<" | "<<board[4]<<" | "<<board[5]<<" " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " <<board[6]<<" | "<<board[7]<<" | "<<board[8]<<" " << std::endl;
}

/**
* @brief Marks field as ouccupied and sets the board field to the player symbol
*
* @param field the field number
* @param player the current player symbol
*/
bool* made_move(int field, char player, char* board, bool* field_occupied)
{
    field_occupied[field-1]=true;
    board[field-1]=player;
    return field_occupied;
}

char switch_player(char player)
{
    player = (player == 'x') ? 'o' : 'x';
    return player;
}

void check_input(int* input, bool* field_occupied)
{
    if (*input< 1 || *input > 9)
    {
        std::cout << "Choose a number from 1-9"<<std::endl;
        std::cin>>*input;
        check_input(input, field_occupied);
    }
    if (field_occupied[*input-1])
    {
        std::cout<<"This field is occupied!"<<std::endl;
        std::cin>>*input;
        check_input(input, field_occupied);
    }
    return;
}

int main ()
{
    bool field_occupied[9]= {false,false,false,false,false,false,false,false,false};
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int win_status = 0;
    char player = 'x';
    int input = 0;
    std::cout << "Welcome to the tic tac toe" << std::endl;
    int moves = 0;
    while (true)
    {
        print_board(board);
        std::cout << "Player "<<player << " it's your turn." << std::endl;
        std::cin >> input;
        check_input(&input, &field_occupied[0]);
        made_move(input, player, board, &field_occupied[0]);
        win_status = winner(board);
        switch (win_status)
        {
            case 0:
                player = switch_player(player);
                system("clear");
                break;
            case PLAYER_1:
                std::cout << "Player x won!" << std::endl;
                print_board(board);
                return 0;
            case PLAYER_2:
                std::cout << "Player o won!" << std::endl;
                print_board(board);
                return 0;
        }
        moves++;
        if (moves == 9)
        {
            std::cout << "It's a draw" << std::endl;
            return 0;
        }
    }
    return 0;
}
