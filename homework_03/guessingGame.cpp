#include "guessingGame.h"

int menuGame()
{
    int menuCnt = 0;
    cout << "-----GUESSING-GAME-----" << endl;
    cout << "[1] GAME START" << endl;
    cout << "[2] TABELE ansehen" << endl;
    cout << "[3] END" << endl;
    cin >> menuCnt;
    return(menuCnt);
}

void youName()
{
    char youName[10];
    char *pyouName = youName;
    cout << "you NAME: ";
    cin >> youName;
    cout << youName << endl;
}

int valueGenerator()
{
    cout << "valueGenerator()" << endl;
    srand(time(nullptr));
    const int max_value = 100;
    const int random_value = rand() % 100;
    return(random_value);
}

int cinValue()
{
    int guessValue = 0;
    int *pguessValue = &guessValue; 
    cout << "you VALUE: ";
    cin >> guessValue;
    return(guessValue);
} 

int checkValue()
{
    cout << "checkValue()" << endl;
    int sollValue = valueGenerator();
    bool win = 0;
    do
    {
        int istValue = cinValue();
        if(sollValue < istValue)
        {
            cout << " < " << endl; 
        }
        if(sollValue > istValue)
        {
            cout << " > " << endl;
        }
        if(sollValue == istValue)
        {
            cout << "YOU WINN" << endl;
            char frage;
            cout << "noch mal yes->[y] no->[n]: ";
            cin >> frage;
            if(frage == 'y')
            {
                win = 0;
            }
            else
            {
                win = 1;
            }
        }
    } while (win == false);
    return(true);
}

/* int read_tabele()
{

} */

/* int write_tabele()
{

} */

/* int tabele(std::fstream& file)
{
    cout << "read_write_file_example:" << endl;
    if(!file-is_open())
    {
        std::cout << "Error! File was not opened!" << std::endl;
        return false; // besser in main 
    }


        const std::string filename2 = "testFile2.txt";
    std::fstream io_file(filename2, std::ios_base::in | std::ios_base::out | std::fstream::app);
    tabele(io_file);
    int tabelle;
    return(tabelle);
} */

void endGame()
{
    cout << "END" << endl;
    exit(EXIT_SUCCESS);
}