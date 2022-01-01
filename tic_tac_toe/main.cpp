#include <iostream>
#include <sys/errno.h>

#define PLAYER_1 1
#define PLAYER_2 2

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

bool field_occupied[9]= {false,false,false,false,false,false,false,false,false};

bool winner_found = false;

int winner()
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
        winner_found = true;
        return PLAYER_1;
    }
    else if (player_2_won)
    {
        winner_found = true;
        return PLAYER_2;
    }
    return 0;
}

void print_board()
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
void made_move(int field, char player)
{
    field_occupied[field-1]=true;
    switch (field)
    {
        case 1:
            board[0][0]=player;
            return;
        case 2:
            board[0][1]=player;
            return;
        case 3:
            board[0][2]=player;
            return;
        case 4:
            board[1][0]=player;
            return;
        case 5:
            board[1][1]=player;
            return;
        case 6:
            board[1][2]=player;
            return;
        case 7:
            board[2][0]=player;
            return;
        case 8:
            board[2][1]=player;
            return;
        case 9:
            board[2][2]=player;
            return;
    }
}

char switch_player(char player)
{
    player = (player == 'x') ? 'o' : 'x';
    return player;
}

void check_input(int input)
{
    if (input< 1 || input > 9)
    {
        std::cout << "Choose a number from 1-9"<<std::endl;
        std::cin>>input;
        check_input(input);
    }
    if (field_occupied[input-1])
    {
        std::cout<<"This field is occupied!"<<std::endl;
        std::cin>>input;
        check_input(input);
    }
    return;
}

int main ()
{
    int win_status = 0;
    char player = 'x';
    int input = 0;
    std::cout << "Welcome to the tic tac toe" << std::endl;
    while (not winner_found)
    {
        print_board();
        std::cout << "Player "<<player << " it's your turn." << std::endl;
        std::cin >> input;
        check_input(input);
        made_move(input, player);
        win_status = winner();
        switch (win_status)
        {
            case 0:
                break;
            case PLAYER_1:
                std::cout << "Player x won!" << std::endl;
                return 0;
            case PLAYER_2:
                std::cout << "Player o won!" << std::endl;
                return 0;
        }
        player = switch_player(player);
        system("clear");
    }
    return 0;
}