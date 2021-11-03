#include "guessingGame.h"

int main ()
{
    while(true)
    {
        switch (menuGame())
        {
        case 1:
            cout << "case 1" << endl;
            //youName();
            do
            {
                checkValue();
                cout << "01" << endl;
            } while(false);
            // int read_tabele();
            break;
        case 2:
            cout << "case 2" << endl;
            // int read_tabele();
            break;
        case 3:
            cout << "case 3" << endl;
            endGame();
            break;
        
        default:
            cout << "ERROR: unknow case number " << endl;
            break;
        }
    }
}