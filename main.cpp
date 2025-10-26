#include<iostream>
#include<string>

std::string board[3][3];
int visited[3][3]={0};
bool player=true;

void initialBoard();
void displayBoard();
void updateBoard(int number,std::string play);
void userInput();
bool check();
bool over();


int main()
{
    std::cout << "\033[34mWelcome to Game\033[m" << std::endl;
    initialBoard();
    displayBoard();

    while(!over())
    {
        userInput();
        displayBoard();
        if(check())
        {
            if(player) std::cout << "\033[34mPlayer O Won!!! \033[m" << std::endl;
            else  std::cout << "\033[31mPlayer X Won!!! \033[m" << std::endl;
            return 0;
        }
    }
    std::cout << "\033[31mDraw\033[m" << std::endl;
}





void initialBoard()
{
    char counter='1';
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            board[i][j]=counter++;
        }
    }
}

void displayBoard()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            std::cout << board[i][j] << "     ";
        }
        std::cout << std::endl;
    }
}

void userInput()
{
    int number;
    std::cout << "Enter the Number: ";
    std::cin >> number;
    updateBoard(number,player?"X":"0");
}

void updateBoard(int number,std::string play)
{
    int i,j;
    // for i index
    if(number<=3) i=0;
    else if(number<=6) i=1;
    else i=2;

    // for j index
    if(number==1 || number==4 || number==7) j=0;
    else if(number==2 || number==5 || number==8) j=1;
    else j=2;
    if(!visited[i][j] && number>=1 && number<=9)
    {
        if(play=="X")
        {
            board[i][j]="\033[31mX\033[m";
        }
        else
        {
            board[i][j]="\033[34mO\033[m";
        }
        visited[i][j]=1;
        player=(!player);
    }
    else
    {
        std::cout << "Already Occupied Or Invaild Input" << std::endl;
    }
}


bool check()
{
    //rows and colums and diagonals
    for(int i=0;i<3;i++)
    {
        //row
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]==board[i][0]) return true;
        //column
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[2][i]==board[0][i]) return true;
    }
    //diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==board[0][0]) return true;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]==board[0][2]) return true;
    return false;
}
bool over()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char c=board[i][j][0];
            if(c>='1' && c<='9') return false;
        }
    }
    return true;
}