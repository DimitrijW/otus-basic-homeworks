#include "guessingGame.h"

int menuGame()
{
    int menuCnt = 0;
    std::cout << "=====> GUESSING-GAME <=====" << std::endl;
    std::cout << "[1] GAME START" << std::endl;
    std::cout << "[2] VIEW RECORDS" << std::endl;
    std::cout << "[3] END" << std::endl;
    std::cin >> menuCnt;
    return(menuCnt);
}

void imputUsername(std::string& user_name)
{
    std::cout << "Enter your name, please: ";
    std::cin >> user_name;
    std::cout << user_name << std::endl;
}

int generator()
{
    srand(time(nullptr));
    const int max_value = 100;
    const int random_value = rand() % 100;
    return(random_value);
}

int inputValue()
{
    int guessValue = 0;
    int *pguessValue = &guessValue; 
    std::cout << "your VALUE: ";
    std::cin >> guessValue;
    return(guessValue);
} 

int checkValue(int& attempts_count)
{
    int setpoint = generator();
    bool win = 0;
    do
    {
        int actualValue = inputValue();
        if(setpoint < actualValue)
        {
            std::cout << " less [<] " << std::endl; 
        }
        if(setpoint > actualValue)
        {
            std::cout << " greater [>] " << std::endl;
        }
        if(setpoint == actualValue)
        {
            std::cout << "YOU WINN" << std::endl;
            char frage;
            std::cout << "afresh YES->[y] NO->[any key]: ";
            std::cin >> frage;
            if(frage == 'y')
            {
                win = 0;
            }
            else
            {
                win = 1;
            }
        }
        attempts_count++;
    } while (win == false);
    return(true);
}

bool read(std::string high_scores_filename)
{
    std::ifstream in_file { high_scores_filename };
    if(!in_file.is_open())
    {
        std::cout << "FAILED open file for read" << high_scores_filename << "!" << std::endl;
        return -1;
    }
    std::string username;
    int high_score = 0;
    while(true)
    {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();

        if(in_file.fail())
        {
            break;
        }
        std::cout << username << '\t' << high_score << std::endl;
    }
    return 0;
}

bool write(std::string user_name, std::string gameFile, int attempts_count)
{ 
    std::ofstream out_file{gameFile, std::ios_base::app};
    if(!out_file.is_open())
    {
        std::cout << "FAILED open file for write" << gameFile << "!" << std::endl;
        return -1;
    }
    out_file << user_name << " ";
    out_file << attempts_count;
    out_file << std::endl;
    return 0;
}

void endGame()
{
    std::cout << "GAME END" << std::endl;
    exit(EXIT_SUCCESS);
}