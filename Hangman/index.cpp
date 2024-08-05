#include <iostream>
#include <cstring>
#include <string>
#include<conio.h>
#include<iomanip>
#include<ctime>
#include<Windows.h>
using namespace std;
//functions
void drawhangman(int tries, int& mistakes)                   //depending on the number of guesses
{
	cout << endl;
	if (tries == 4) {
		switch (mistakes)
		{
		case 3:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |      \n";
			cout << " |   \n";
			cout << " |  \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 2:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |   \n";
			cout << " |  \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 1:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |  /|\\ \n";
			cout << " |      \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 0:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |  /|\\ \n";
			cout << " |  / \\\n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			cout << " \033[1;31m                                   //////////////////////////////////////////\033[0m\n";
			cout << " \033[1;31m                                   //                                      //\033[0m\n";
			cout << " \033[1;31m                                   //            You have lost.            //\033[0m\n";
			cout << " \033[1;31m                                   //        Better luck next time!        //\033[0m\n";
			cout << " \033[1;31m                                   //                                      //\033[0m\n";
			cout << " \033[1;31m                                   //////////////////////////////////////////\033[0m\n";
			break;
		}
		}
	}
	else if (tries == 3) {

		switch (mistakes)
		{
		case 2:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |   \n";
			cout << " |  \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 1:
		{

			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |  /|\\ \n";
			cout << " |      \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 0:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |  /|\\ \n";
			cout << " |  / \\\n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			cout << " \033[1;31m                                   //////////////////////////////////////////\033[0m\n";
			cout << " \033[1;31m                                   //                                      //\033[0m\n";
			cout << " \033[1;31m                                   //            You have lost.            //\033[0m\n";
			cout << " \033[1;31m                                   //        Better luck next time!        //\033[0m\n";
			cout << " \033[1;31m                                   //                                      //\033[0m\n";
			cout << " \033[1;31m                                   //////////////////////////////////////////\033[0m\n";
			break;
		}
		}
	}
	else if (tries == 2) {
		switch (mistakes)
		{
		case 1:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |   \n";
			cout << " |  \n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			break;
		}
		case 0:
		{
			cout << " +---+\n";
			cout << " |   |\n";
			cout << " |   O  \n";
			cout << " |  /|\\ \n";
			cout << " |  / \\\n";
			cout << " |     \n";
			cout << "==========" << endl << endl;
			cout << setw(35) << "\n\nYOU HAVE LOST ";
			break;
		}
		}
	}
}
void Leaderboard(string name[], int score[], int size, int start) {

	// Sort the leaderboard based on scores (you can use your existing sorting logic)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (score[j] < score[j + 1])
			{
				int tempScore = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tempScore;
				string tempName = name[j];
				name[j] = name[j + 1];
				name[j + 1] = tempName;
			}
		}
	}
	if (start == 2)
	{   // Display the updated leaderboard
		cout << setw(40) << "LEADERBOARD" << endl;
		cout << setw(30) << "Name" << setw(34) << "Score" << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << setw(27) << name[i] << setw(34) << score[i] << endl;
		}
	}
}
void maingame(int& player_score, int choice, int& mistakes, string guessedletters, int& ttl_hints, string& Word, string categ[], string guess, int score[], string name[], int start, string& MysteryWord, int RandNum, int tries, int size)
{
	int time = 60;
	while (time > 0)
	{
		do
		{
			cout << "\r" << "\033[A" << setw(30) << MysteryWord << setw(20) << "Number of Lives: " << mistakes << setw(20) << "You have " << ttl_hints << " Hints Left " << setw(20) << "Guessed: " << guessedletters << setw(20) << "    Score : " << player_score << setw(20) << "Time: " << time << endl << "Enter The Letter: ";
			if (_kbhit())
			{
				cin >> guess;
				if (guessedletters.find(guess) != -1)
				{
					guessedletters += guess;
					mistakes--;
					Beep(1000, 250);
					drawhangman(tries, mistakes);
				}
				else if (guess == "@")
				{
					if (ttl_hints > 0)
					{
						int lastHintIndex = -1;
						if (ttl_hints > 0) {
							int randHint;
							do {
								randHint = rand() % MysteryWord.length();
								guess = categ[RandNum][randHint];
							} while (guessedletters.find(guess) != -1);  // Repeat if the new hint is the same as the last one
							lastHintIndex = randHint;  // Update the last hinted index
							char help = categ[RandNum][randHint];
							guessedletters += help;
							guess = help;
							int pos = 0;
							pos = Word.find(guess, pos);
							while (pos != -1)
							{
								MysteryWord.replace(pos, 1, guess);
								pos = Word.find(guess, pos + 1);
							}
							ttl_hints--;
						}
					}
					else
					{
						mistakes--;
						drawhangman(tries, mistakes);
						Beep(1000, 250);
					}
				}
				else if (Word.find(guess) != -1)
				{
					Beep(2500, 250);
					guessedletters += guess;
					if (choice == 1)
						player_score++;
					else if (choice == 2)
						player_score += 2;
					else if (choice == 3)
						player_score += 3;
					int pos = 0;
					pos = Word.find(guess, pos);
					while (pos != -1)
					{
						MysteryWord.replace(pos, 1, guess);
						pos = Word.find(guess, pos + 1);
					}
				}
				else
				{
					guessedletters += guess;
					mistakes--;
					Beep(1000, 250);
					drawhangman(tries, mistakes);
				}
				if (MysteryWord != Word)
				{
					if (mistakes > 0)
						cout << "\033[A";
					if (mistakes == 0)
					{
						cout << "Enter Your Name : ";
						if (player_score > score[4])
						{
							cin >> name[4];
							score[4] = player_score;
						}
						Leaderboard(name, score, size, start);
						break;
					}
				}
				if (MysteryWord == Word)
				{
					cout << "\n\n";
					cout << " " << setw(30) << "\033[1;32m                          ///////////////////////////////////////////\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                        //      Congratulations! You have won!   //\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                       //////////////////////////////////////////\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                       \\                                     /\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                        \\                                   /\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                         \\                                 /\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                          \\                               /\033[0m\n";
					cout << " " << setw(30) << "\033[1;32m                           \\_____________________________/\033[0m\n";
					cout << " " << setw(30) << "\n\nMysteryWord Is : " << MysteryWord << "\"" << endl;
					cout << "Enter Your Name : ";
					if (player_score > score[4])
					{
						cin >> name[4];
						score[4] = player_score;
					}
					Leaderboard(name, score, size, start);
				}
			}
			time--;
			Sleep(1000);
			if (time == 0)
			{
				mistakes = 0;
				drawhangman(tries, mistakes);
				break;
			}
		} while (Word != MysteryWord && mistakes > 0);
		if (mistakes == 0 || Word == MysteryWord)
			break;
	}

}
void rules()
{
	cout << "\033[1;34m                                             ////////////////////////////////////\033[0m\n";
	cout << "\033[1;34m                                              //   Welcome to Hangman Game!   //\033[0m\n";
	cout << "\033[1;34m                                             ////////////////////////////////////\033[0m\n" << endl << endl;
	cout << "||                                                        \033[1;31m'RULES'                                                               \033[0m||";  //Rules for the game.
	cout << "\n||\033[1;32m A blank word or  phrase will be given to you and you have to Input the blank characters,                                     \033[0m||";
	cout << "\n||\033[1;32myour number of chances to Input, number of hints and the size of the puzzle depend on your difficulty. Type '@' to            \033[0m||";
	cout << "\n||\033[1;32mget a hint, using capital letters will count as a mistake since you can only enter characters, and the characters you         \033[0m||";
	cout << "\n||\033[1;32menter should be small alphabets and \"_\" otherwise it would be considered a mistake.You have a timer for the puzzle as well.  \033[0m || ";
}
void main()
{
	const int size = 5;
	string name[size];
	int player_score = 0;
	int score[size] = {};
	rules();
	char ans;
	do
	{
		int start;
		cout << endl << endl << endl << "Press (1) To Start the Game. " << endl << "Press (2) To Check The Leaderboard. " << endl;
		cin >> start;
		if (start == 1 || start == 2)
		{
			if (start == 2)
			{
				Leaderboard(name, score, size, start);
			}
			if (start == 1)
			{
				cout << "What kind of category do you want?" << endl << "Press (1) for Animals." << endl << "Press (2) for Countries." << endl << "Press (3) for Programming languages.\n\n ";
				int choice = 0;
				cin >> choice;
				if (choice > 0 && choice < 4)
				{
					if (choice == 1)
					{
						string guess;
						int choice = 0;
						cout << "Choose The Difficulty Level " << endl << "Press(1) for Easy \n" << "Press (2) for Medium \n" << "Press (3) for Hard\n";
						cin >> choice;
						if (choice > 0 && choice < 4)
						{
							if (choice == 1)
							{
								int ttl_hints = 3;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "shark","wolves","black_cat_crosses","furry_little_squirrel" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 2)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "elephant","crocodile","flammingo","red_panda_is_adorable" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 3)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "chameleon_changes_color","platypus_lays_eggs","penguins_can_not_fly","lions_are_the_kings" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
						}
						else
							cout << "Invalid Difficulty" << endl << endl;
					}
					else if (choice == 2)
					{
						string guess;
						int choice = 0;
						cout << "Choose The Difficulty Level " << endl << "Press(1) for Easy \n" << "Press (2) for Medium \n" << "Press (3) for Hard\n";
						cin >> choice;
						if (choice > 0 && choice < 4)
						{
							if (choice == 1)
							{
								int ttl_hints = 3;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "pakistan","nepal","saudia_arabia","belgium" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 2)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "colombia_is_beautiful","morocco","slovakia_is_in_europe","serbia_has_fine_art" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 3)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "tajikistan_has_mountainous_landscapes","kyrgyzstan_mixes_traditions","turkey_is_cultural","pakistan_holds_strategic_importance" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
						}
						cout << "Invalid Difficulty" << endl << endl;
					}
					else if (choice == 3)
					{
						string guess;
						int choice = 0;
						cout << "Choose The Difficulty Level " << endl << "Press(1) for Easy \n" << "Press (2) for Medium \n" << "Press (3) for Hard\n";
						cin >> choice;
						if (choice > 0 && choice < 4)
						{
							if (choice == 1)
							{
								int ttl_hints = 3;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "python_is_versatile","java_is_cool","c_is_not_much_used","ruby_is_dynamic" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 2)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "javascript_enhances_interactivity","html_structures_web","rust_ensures_safety","perl_supports_text" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
							else if (choice == 3)
							{
								int ttl_hints = 4;
								string Word, guessedletters = "";
								int tries = 4;			//Total number of attempts
								int mistakes = 4;		//attemps available
								string categ[4] = { "cobol_handles_enterprise","prolog_facilitates_AI","j_is_array_oriented","nim_emphasizes_performance" };
								srand(time(NULL));
								int RandNum = rand() % 4;		//this will give a different word each time
								Word = categ[RandNum];
								string MysteryWord(Word.length(), '*');		//replaces every letter of alphabet with an *
								maingame(player_score, choice, mistakes, guessedletters, ttl_hints, Word, categ, guess, score, name, start, MysteryWord, RandNum, tries, size);
							}
						}
						else
							cout << "Invalid Difficulty" << endl << endl;

					}
				}
				else
					cout << "Invalid Category " << endl << endl;
			}
		}

		cout << "Press 'y' To Try Again, Press Any Other Key To Exit ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	cout << "\033[1;34m                                    ////////////////////////////// \033[0m\n";
	cout << "\033[1;34m                                    //   Thanks for playing!   // \033[0m\n";
	cout << "\033[1;34m                                    //   Hope you had fun!     // \033[0m\n";
	cout << "\033[1;34m                                    ////////////////////////////// \033[0m\n";
}
