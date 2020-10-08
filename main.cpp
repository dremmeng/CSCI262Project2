
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

std::string ConvertPermutationToString(int permutation)
{
    std::string board = "         ";

    int counter = 0;
    int xCount = 0;
    int oCount = 0;

    while (permutation > 0)
    {
        
        /*Generate every possible board from a combination of three characters*/
        switch (permutation % 3)
        {
        case 0:
            break;
        case 1:
            xCount++;
            board[9 - counter] = 'X';
            break;
        case 2:
            oCount++;
            board[9 - counter] = 'O';
            break;
        default:
            break;
        }
       
 
       
       
        if ((board[0] == 'X') && (board[0] == board[4]) && (board[4] == board[8]))
        {
            return board;
        }
        if ((board[0] == 'O') && (board[0] == board[4]) && (board[4] == board[8]))
        {
            return board;
        }
        if ((board[0] == 'O') && (board[0] == board[1]) && (board[1] == board[2]))
        {
            return board;
        }
        if ((board[0] == 'X') && (board[0] == board[1]) && (board[1] == board[2]))
        {
            return board;
        }
        if (((board[0] == 'O') && (board[3] == board[4]) && (board[4] == board[5])))
        {
            return board;
        }
        if ((board[0] == 'X') && (board[3] == board[4]) && (board[4] == board[5]))
        {
            return board;
        }
        if ((board[6] == 'O') && (board[6] == board[7]) && (board[7] == board[8]))
        {
            return board;
        }
        if ((board[6] == 'X') && (board[6] == board[7]) && (board[7] == board[8]))
        {
            return board;
        }
        if ((board[6] == 'O') && (board[6] == board[4]) && (board[4] == board[3]))
        {
            return board;
        }
        if ((board[6] == 'X') && (board[6] == board[4]) && (board[4] == board[3]))
        {
            return board;
        }
        if ((board[0] == 'O') && (board[0] == board[3]) && (board[3] == board[6]))
        {
            return board;
        }
        if ((board[0] == 'X') && (board[0] == board[3]) && (board[3] == board[6]))
        {
            return board;
        }
        if ((board[1] == 'O') && (board[1] == board[4]) && (board[4] == board[7]))
        {
            return board;
        }
        if ((board[1] == 'X') && (board[1] == board[4]) && (board[4] == board[7]))
        {
            return board;
        }
        if ((board[2] == 'O') && (board[2] == board[5]) && (board[5] == board[8]))
        {
            return board;
        }
        if ((board[2] == 'X') && (board[2] == board[5]) && (board[5] == board[8]))
        {
            return board;
        }
        
        counter++;
        permutation = permutation / 3;
    }


    return board;
}
    set<string> get_all_boards(set<string>& allBoards)
    {
    /*Here we generate every single board from each permutation of boards*/
        string board;
    for (int i = 0; i < 196830; ++i) {

        board = ConvertPermutationToString(i);

        if (board.length())
        {
            allBoards.insert(board);
        }
    }
    return allBoards;
    }
    set<string> eliminate_boards(set<string>& allboards)
    {
        set<string> safe_boards;
        for (auto it = allboards.begin(); it != allboards.end(); it++)
        {
            string board = *it;
            int oCount = 0;
            int xCount = 0;
            for (int j = 0; j < 9 ; j++)
            {
                if (board[j] == 'X')
                {
                    xCount++;
                }
                else if (board[j] == 'O')
                {
                    oCount++;
                }
            }
            if (oCount >= xCount)
            {
                board = "        ";
            }
            else if (xCount - oCount > 1)
            {
                board = "        ";
            }
            safe_boards.insert(board);
        }
    }
    void count_winners(set<string> allboards)
    {
        int xWins=0;
        int oWins=0;
        int draws=0;
        for (auto it = allboards.begin(); it != allboards.end(); it++)
        {
            string board = *it;
            if ((board[0] == 'X') && (board[0] == board[4]) && (board[4] == board[8]))
            {
                xWins++;
            }
            else if ((board[0] == 'O') && (board[0] == board[4]) && (board[4] == board[8]))
            {
                oWins++;
            }
            else if ((board[0] == 'O') && (board[0] == board[1]) && (board[1] == board[2]))
            {
                oWins++;
            }
            else if ((board[0] == 'X') && (board[0] == board[1]) && (board[1] == board[2]))
            {
                xWins++;
            }
            else if (((board[0] == 'O') && (board[3] == board[4]) && (board[4] == board[5])))
            {
                oWins++;
            }
            else if ((board[0] == 'X') && (board[3] == board[4]) && (board[4] == board[5]))
            {
                xWins++;
            }
            else if ((board[6] == 'O') && (board[6] == board[7]) && (board[7] == board[8]))
            {
                oWins++;
            }
            else if ((board[6] == 'X') && (board[6] == board[7]) && (board[7] == board[8]))
            {
                xWins++;
            }
            else if ((board[6] == 'O') && (board[6] == board[4]) && (board[4] == board[3]))
            {
                oWins++;
            }
            else if ((board[6] == 'X') && (board[6] == board[4]) && (board[4] == board[3]))
            {
                xWins++;
            }
            else if ((board[0] == 'O') && (board[0] == board[3]) && (board[3] == board[6]))
            {
                oWins++;
            }
            else if ((board[0] == 'X') && (board[0] == board[3]) && (board[3] == board[6]))
            {
                xWins++;
            }
            else if ((board[1] == 'O') && (board[1] == board[4]) && (board[4] == board[7]))
            {
                oWins++;
            }
            else if ((board[1] == 'X') && (board[1] == board[4]) && (board[4] == board[7]))
            {
                xWins++;
            }
            else if ((board[2] == 'O') && (board[2] == board[5]) && (board[5] == board[8]))
            {
                oWins++;
            }
            else if ((board[2] == 'X') && (board[2] == board[5]) && (board[5] == board[8]))
            {
                xWins++;
            }
            else if ((board[0] != ' ') && (board[1] != ' ') && (board[2] != ' ') && (board[3] != ' ') && (board[4] != ' ') && (board[5] != ' ') && (board[6] != ' ') && (board[7] != ' ') && (board[8] != ' '))
            {
                draws++;
            }
        }
        cout << "xWins = " << xWins << ", oWins = " << oWins << ", draws = " << draws << endl;
            
    }


int main() {
    set<string> boards;
    string board;
    get_all_boards(boards);
    eliminate_boards(boards);
    count_winners(boards);
    for (auto it = boards.begin(); it != boards.end(); it++)
    {
        
        if (*it == "        ")
        {
            continue;
        }
        else
        {
            cout << *it << endl;
        }
        
    }
}