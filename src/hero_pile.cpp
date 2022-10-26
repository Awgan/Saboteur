
#include "hero_pile.hpp"


//choose number of miners and saboteurs
void HeroPile::prepareHeroCards()
{
	uint8_t players = getCardsNumber();
	switch(players)
	{
		case 3:
			s_cardsNumber.miner 		= 3;
			s_cardsNumber.saboteur 	= 1;
		break;

		case 4:
			s_cardsNumber.miner 		= 4;
			s_cardsNumber.saboteur 	= 1;
		break;

		case 5:
			s_cardsNumber.miner 		= 4;
			s_cardsNumber.saboteur 	= 2;
		break;

		case 6:
			s_cardsNumber.miner 		= 5;
			s_cardsNumber.saboteur 	= 2;
		break;

		case 7:
			s_cardsNumber.miner 		= 5;
			s_cardsNumber.saboteur 	= 3;
		break;

		case 8:
			s_cardsNumber.miner 		= 6;
			s_cardsNumber.saboteur 	= 3;
		break;

		case 9:
			s_cardsNumber.miner 		= 7;
			s_cardsNumber.saboteur 	= 3;
		break;

		case 10:
			s_cardsNumber.miner 		= 7;
			s_cardsNumber.saboteur 	= 4;
		break;

		default:
		break;
	}

}


//convert literal value from file to number value
void maintainHeroCardFile(const std::string fileName)
{
	std::cerr << "maintainHeroCardFile() : run\n";
	std::ifstream file(fileName);

	if(!file)
	{
		std::cerr << "maintainHeroCardFile() : file doesn't exist\n";
		return;
	}

	std::ofstream fileOut(fileName.substr(0,fileName.size()-4) + "_maintain.txt");

	while(file)
	{
		std::string line;
		std::getline(file,line);

		if(line[0] == '#')
		{
			std::cerr << "maintainHeroCardFile() : line with comment\n";
			continue;
		}

		char * token = nullptr;
		token = std::strtok(&line[0], ";");
		uint8_t count = 1;

		while(token)
		{
			//uint8_t id, cardT, heroT;
			std::string name;
			switch (count)
			{
				case 1:
					fileOut << token << ";";
					//id = atoi(token);
				break;
				case 2:
					if((std::string)token == "hero")
						{
							fileOut << 1 << ";";
							//cardT = 1;
						}

				break;
				case 3:
					if((std::string)token == "miner")
					{
						fileOut << 0 << ";";
						//heroT = 0;
					}
					else if((std::string)token == "saboteur")
					{
						fileOut << 1 << ";";
						//heroT = 1;
					}
				break;
				case 4:
					fileOut << token << '\n';
					name = std::string(token);
				break;
				default:
				std::cerr << "maintainHeroCardFile() : switch() : default\n";
				break;
			}

			token = std::strtok(NULL, ";");
			++count;
		}
	}
	file.close();
}
