#ifndef GUESSINGGAME_H_
#define GUESSINGGAME_H_

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

int menuGame();
void imputUsername(std::string& user_name);
/* the function generates any value from 1 to 100 */
int generator();
int inputValue();
int checkValue(int& attempts_count);
bool read(std::string high_scores_filename);
bool write(std::string user_name, std::string high_scores_filename, int attempts_count);
void endGame();

#endif /* GUESSINGGAME_H_ */