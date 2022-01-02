#include <iostream>

#define PLAYER_1 1
#define PLAYER_2 2


int winner(char** board)
{
    bool player_1_won = false;
    bool player_2_won = false;
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]== board[i][1] && board[i][1]== board[i][2])
        {
            if (board[i][0]== 'o')
            {
                player_2_won = true;
                break;
            }
            else
            {
                player_1_won = true;
                break;
            }
        }
        else if (board[0][i]== board[1][i] && board[1][i]== board[2][i])
        {
            if (board[0][i]== 'o')
            {
                player_2_won = true;
                break;
            }
            else
            {
                player_1_won = true;
                break;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[1][1]== 'o')
        {
            player_2_won = true;
        }
        else
        {
            player_1_won = true;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[1][1]== 'o')
        {
            player_2_won = true;
        }
        else
        {
            player_1_won = true;
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
void print_board(char** board)
{
    std::cout << "Input the number for the field you want" << std::endl;
    std::cout << " " <<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " <<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " <<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" " << std::endl;
}

/**
 * @brief Marks field as ouccupied and sets the board field to the player symbol
 *
 * @param field the field number
 * @param player the current player symbol
 */
bool* made_move(int field, char player, char** board, bool* field_occupied)
{
    field_occupied[field-1]=true;
    switch (field)
    {
        case 1:
            board[0][0]=player;
            return field_occupied;
        case 2:
            board[0][1]=player;
            return field_occupied;
        case 3:
            board[0][2]=player;
            return field_occupied;
        case 4:
            board[1][0]=player;
            return field_occupied;
        case 5:
            board[1][1]=player;
            return field_occupied;
        case 6:
            board[1][2]=player;
            return field_occupied;
        case 7:
            board[2][0]=player;
            return field_occupied;
        case 8:
            board[2][1]=player;
            return field_occupied;
        case 9:
            board[2][2]=player;
            return field_occupied;
    }
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
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int win_status = 0;
    char player = 'x';
    char* board_ptrs[3] = {&board[0][0], &board[1][0], &board[2][0]};
    char** board_ptr = &board_ptrs[0];
    int input = 0;
    std::cout << "Welcome to the tic tac toe" << std::endl;
    int moves = 0;
    while (true)
    {
        print_board(board_ptr);
        std::cout << "Player "<<player << " it's your turn." << std::endl;
        std::cin >> input;
        check_input(&input, &field_occupied[0]);
        made_move(input, player, board_ptr, &field_occupied[0]);
        win_status = winner(board_ptr);
        switch (win_status)
        {
            case 0:
                player = switch_player(player);
                system("clear");
                break;
            case PLAYER_1:
                std::cout << "Player x won!" << std::endl;
                return 0;
            case PLAYER_2:
                std::cout << "Player o won!" << std::endl;
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
