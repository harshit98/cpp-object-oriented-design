#include "Game.h"


Game::Game() {
	this->deck.shuffle();

	//hand out two cards to each player
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);

	//print the directions
	this->printGreeting();
	this->printHelp();
}

//simply prints the greeting
void Game::printGreeting() {
	std::cout << "Hello, and welcome to Robin's BlackJack!\n";
	std::cout << "A quick and simple BlackJack simulator.\n";
}

//prints the directions
void Game::printHelp() {
	std::cout << "Here are the possible commands: \n";
	std::cout << "\tPress [h] to hit.\n";
	std::cout << "\tPress [s] to stay.\n";
	std::cout << "\tPress [r] to restart.\n";
	std::cout << "\tPress [q] to quit.\n";
	std::cout << "\tPress [?] to get help.\n";
}

//Asks the player for their choice
int Game::askPlayer() {
	//clear buffer

	std::cout << this->player;
	std::cout << "What will you do?\n";

	char cmd = getchar();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


	//parse the input and return the correct code
	switch(cmd) {
	case 'h' : 
		return HIT;
		break;
	case 's' :
		return STAY;
		break;
	case 'r' :
		return RESTART;
		break;
	case 'q' :
		return QUIT;
		break;
	case '?' :
		return HELP;
		break;
	default :
		std::cout << "Command not recognized, please try again.\n";
		return 0;
		break;
	}
}


void Game::dealerTurn() {
	std::cout << "Conducting dealer's turn.\n";

	//dealer hits for 17 and under
	while(dealer.getCurrentValue() < 18) {
		deck.deal(dealer);
	}

	std::cout << "The Dealer's hand : \n" << dealer;
	std::cout << "The value of dealer's hand: " << dealer.getCurrentValue() << std::endl;

	//determine the winner
	if(dealer.getCurrentValue() > 21) {
		std::cout << "The Dealer's bust! You've won!\n" << std::endl;
	} else if(dealer.getCurrentValue() == player.getCurrentValue()) {
		std::cout << "It's a tie!\n";
	} else if(dealer.getCurrentValue() > player.getCurrentValue()) {
		std::cout << "You've lost!\n";
	} else {
		std::cout << "You've won!\n";
	}

	std::cout << "Press [q] to quit, any other key to restart.\n";

	//does the user wish to quit?
	char cmd = getchar();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	if (cmd=='q') exit(0);

	//start over again, if user does not quit.
	resetGame();
}

//reshuffles the deck and passes out two cards to each player
void Game::resetGame() {
	this->deck.reset();
	this->deck.shuffle();

	//clear the hands
	player.clear();
	dealer.clear();

	//hand out two cards to each player
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);
}

//if the player goes over 21
int playerBust() {
	std::cout << "Darn! You've lost!\n";
	std::cout << "Press [q] to quit, any other key to restart.\n";

	//does the user wish to continue?
	char cmd = getchar();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	if(cmd == 'q') return 1;

	return 0;
}

//this executes the game
void Game::play() {
	//loop until quit
	for(;;) {
		std::cout << "________________________________\n";
		int choice = askPlayer();

		//handle each user choice
		switch(choice) {
		case HIT :
			std::cout << "You chose hit on " << player.getCurrentValue() << std::endl;
			deck.deal(player);

			if(player.isBust()) {
				std::cout << player;
				//user is over the 21 limit
				if(playerBust()) {
					//user chooses to quit
					std::cout << "Thank you for playing.\n";
					exit(0);
				} else {
					resetGame();
				}
			}
			break;
		case STAY :
			std::cout << "You chose to stay on: " << player.getCurrentValue() << std::endl;
			dealerTurn();
			break;
		case RESTART:
			std::cout << "Restarting game...\n";
			resetGame();
			break;
		case QUIT :
			std::cout << "Thank you for playing.\n";
			exit(0);
			break;
		case HELP : 
			printHelp();
			break;
		}
		std::cout << std::endl;

	}
}
