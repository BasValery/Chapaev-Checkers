#include "PlayingField.h"


float PlayingField::Entropy = 0.0001;

// онструктор
PlayingField::PlayingField(string texture_field_file, string Texture_checker1, string Texture_checker2):texture_cheker1(Texture_checker1),texture_checker2(Texture_checker2)
{
	srand(time(0));
	player1.reserve(8);
	player2.reserve(8);
	for (int i = 0; i < 8; i++)
	{
		player1.push_back(new Checker((75 * i) + 3, 528, texture_cheker1)); //”станавливаем позиции шашек
		player2.push_back(new Checker((75 * i) + 3, 3, texture_checker2)) ;
	}
	image_field.loadFromFile(texture_field_file);
	texture_field.loadFromImage(image_field);
	sprite_field.setTexture(texture_field);
	sprite_field.setPosition(0, 0);
}

void PlayingField::NewLevel(int ScorePlayer1, int ScorePlayer2)//”станавливаем новые позиции шашек
{
	for (int i = 0; i < player1.size(); i++)
	{
		delete player1[i];
		player1.clear();
	}
	for (int i = 0; i < player2.size(); i++)
	{
		delete player2[i];
		player2.clear();
	}
	for (int i = 0; i < 8; i++)
	{
		player1.push_back(new Checker((75 * i) + 3, 528 - ScorePlayer1*75, texture_cheker1));
		player2.push_back(new Checker((75 * i) + 3, 3 + ScorePlayer2*75, texture_checker2));
	}

}

void PlayingField::Drow(sf::RenderWindow &window)
{
	window.draw(sprite_field);

	for (int i = 0; i < player1.size(); i++)
		player1[i]->Show(window);
	for (int i = 0; i < player2.size(); i++)
		player2[i]->Show(window);
}
bool PlayingField::IsChekerPlayer1(sf::Vector2f & CoordClick)
{

	for (int i = 0; i < player1.size(); i++)
	{
		sf::Vector2f buf = player1[i]->GetCoordinates();
		sf::Vector2f Center = { buf.x + player1[i]->GetRadius(), buf.y + player1[i]->GetRadius() };
		if (sqrt( (CoordClick.x - Center.x)*(CoordClick.x - Center.x) + (CoordClick.y - Center.y)*(CoordClick.y - Center.y)) <= player1[i]->GetRadius())
		{
			CoordClick = Center;
			return true;
		}
	}
	
	return false;
}
bool PlayingField::IsChekerPlayer2(sf::Vector2f & CoordClick)
{
	for (int i = 0; i < player2.size(); i++)
	{
		sf::Vector2f buf = player2[i]->GetCoordinates();
		sf::Vector2f Center = { buf.x + player2[i]->GetRadius(), buf.y + player2[i]->GetRadius() };
		if (sqrt((CoordClick.x - Center.x)*(CoordClick.x - Center.x) + (CoordClick.y - Center.y)*(CoordClick.y - Center.y)) <= player2[i]->GetRadius())
		{
			CoordClick = Center;
			return true;
		}
	}
	return false;
}
void PlayingField::SetChekerSpeed(sf::Vector2f Cheker, sf::Vector2f Vector, double Force)
{
	for (int i = 0; i < player1.size(); i++)
	{
		if (player1[i]->GetCoordinates().x + 35 == Cheker.x && player1[i]->GetCoordinates().y + 35 == Cheker.y)
			player1[i]->AddForse(Vector, Force);
	}
	for (int i = 0; i < player2.size(); i++)
	{
		if (player2[i]->GetCoordinates().x + 35 == Cheker.x && player2[i]->GetCoordinates().y + 35 == Cheker.y)
			player2[i]->AddForse(Vector, Force);
	}
}
void PlayingField::ShootFromPlayer2ToPlayer1(int FirstCheker, int SecondCheker, float forse, int Error)
{

	sf::Vector2f knock = player1[SecondCheker]->GetCoordinates();
	knock.x += rand() % (Error * 2) - Error;
	knock.y += rand() % (Error * 2) - Error;

	knock.x -= player2[FirstCheker]->GetCoordinates().x;
	knock.y -= player2[FirstCheker]->GetCoordinates().y;

	knock = Normalize(knock);

	player2[FirstCheker]->AddForse(knock, forse);
}
bool PlayingField::Move() //ѕровер€ем движутс€ ли шашки
{
	bool move = false;
	for (int i = 0; i < player1.size(); i++)
		if (player1[i]->Move())
			move = true;
	for (int i = 0; i < player2.size(); i++)
		if (player2[i]->Move())
			move = true;
	return move;
}
void PlayingField::CheckClash()//ќбработка столкновений
{
	vector<int> used1;//ћассивы в которых хран€тс€ шашки которые уже провзаимодействовали
	vector<int> usedEnamy;//„тобы избежать повторной обработки столкновени€
	for (int i = 0; i < player1.size(); i++)
	{
		
		for (int j = 0; j < player1.size(); j++)
		{
			if (j != i && player1[i]->GetKnockForce() > 0.1 && player1[j]->Distance(*player1[i]) <= player1[i]->GetRadius()*2 )
			{
				//≈сли шашки столкнулись
				bool FlagUsed = false;
				//ѕровер€ем взаимодействовали ли они
				for (int check = 0; check < used1.size(); check++)
					if (used1[check] == i)
						FlagUsed = true;
				if (FlagUsed)
					break;
				used1.push_back(j);
			
				sf::Vector2f normal = { player1[j]->GetCoordinates().x - player1[i]->GetCoordinates().x , player1[j]->GetCoordinates().y - player1[i]->GetCoordinates().y };
				sf::Vector2f newForse = player1[i]->GetDirecton();
				normal = Normalize(normal);
				
				float buf = (newForse.x * normal.x + newForse.y * normal.y)*2;
				normal.x *= buf;
				normal.y *= buf;
				newForse.x -= normal.x;
				newForse.y -= normal.y;
				//ѕо формуле отраженного вектора получае вектор, а силу раздел€ем пропорционально углу столкновени€
				newForse = Normalize(newForse);
				normal = Normalize(normal);

				float alfa = (newForse.x*normal.x + newForse.y*normal.y);
				if (alfa < 0)
				{
					alfa = -alfa;
				}
				float Forse = player1[i]->GetKnockForce();
				
				player1[j]->AddForse(normal, Forse * alfa - GetEntropy());
				player1[i]->AddForse(newForse, Forse - Forse* alfa - GetEntropy());

				/*std::cout << "Alfa: " << alfa<<'\n';
				std::cout << "New Checker: " << Forse * alfa<<'\n';
				std::cout << "Old Checker: " << Forse - Forse*alfa<<'\n';*/
			}
		}


		for (int j = 0; j < player2.size(); j++)
		{
			if (player1[i]->GetKnockForce() > 0.1 && player2[j]->Distance(*player1[i]) <= player1[i]->GetRadius()*2 )
			{
				usedEnamy.push_back(j);
				sf::Vector2f normal = { player2[j]->GetCoordinates().x - player1[i]->GetCoordinates().x , player2[j]->GetCoordinates().y - player1[i]->GetCoordinates().y };
				sf::Vector2f newForse = player1[i]->GetDirecton();
				normal = Normalize(normal);

				float buf = (newForse.x * normal.x + newForse.y * normal.y) * 2;
				normal.x *= buf;
				normal.y *= buf;
				newForse.x -= normal.x;
				newForse.y -= normal.y;

				newForse = Normalize(newForse);
				normal = Normalize(normal);

				float alfa = (newForse.x*normal.x + newForse.y*normal.y);
				if (alfa < 0)
				{
					alfa = -alfa;
				}
				float Forse = player1[i]->GetKnockForce();

				player2[j]->AddForse(normal, Forse * alfa);
				player1[i]->AddForse(newForse, Forse - Forse* alfa);
		/*		std::cout << "Alfa: " << alfa<<'\n';
				std::cout << "New Checker: " << Forse * alfa<<'\n';
				std::cout << "Old Checker: " << Forse - Forse*alfa<<'\n';*/
			}
		}
	}

//-----------------------------------------------------------------------------------------------
//јналогична€ обработка дл€ врагов 

	vector<int> used2;
	for (int i = 0; i < player2.size(); i++)
	{

		for (int j = 0; j < player2.size(); j++)
		{
			if (j != i && player2[i]->GetKnockForce() > 0.1 && player2[j]->Distance(*player2[i]) <= player2[i]->GetRadius() * 2 )
			{
				bool FlagUsed = false;
				for (int check = 0; check < used2.size(); check++)
					if (used2[check] == i)
						FlagUsed = true;
				if (FlagUsed)
					break;
				used2.push_back(j);
				sf::Vector2f normal = { player2[j]->GetCoordinates().x - player2[i]->GetCoordinates().x , player2[j]->GetCoordinates().y - player2[i]->GetCoordinates().y };
				sf::Vector2f newForse = player2[i]->GetDirecton();
				normal = Normalize(normal);

				float buf = (newForse.x * normal.x + newForse.y * normal.y) * 2;
				normal.x *= buf;
				normal.y *= buf;
				newForse.x -= normal.x;
				newForse.y -= normal.y;

				newForse = Normalize(newForse);
				normal = Normalize(normal);

				float alfa = (newForse.x*normal.x + newForse.y*normal.y);
				if (alfa < 0)
				{
					alfa = -alfa;
				}
				float Forse = player2[i]->GetKnockForce();

				player2[j]->AddForse(normal, Forse * alfa);
				player2[i]->AddForse(newForse, Forse - Forse* alfa);

				/*std::cout << "Alfa: " << alfa<<'\n';
				std::cout << "New Checker: " << Forse * alfa<<'\n';
				std::cout << "Old Checker: " << Forse - Forse*alfa<<'\n';*/
			}
		}


		for (int j = 0; j < player1.size(); j++)
		{
			if (player2[i]->GetKnockForce() > 0.1 && player1[j]->Distance(*player2[i]) <= player2[i]->GetRadius() * 2 )
			{

				bool FlagUsed = false;
				for (int check = 0; check < usedEnamy.size(); check++)
					if (usedEnamy[check] == i)
						FlagUsed = true;
				if (FlagUsed)
					break;

				sf::Vector2f normal = { player1[j]->GetCoordinates().x - player2[i]->GetCoordinates().x , player1[j]->GetCoordinates().y - player2[i]->GetCoordinates().y };
				sf::Vector2f newForse = player2[i]->GetDirecton();
				normal = Normalize(normal);

				float buf = (newForse.x * normal.x + newForse.y * normal.y) * 2;
				normal.x *= buf;
				normal.y *= buf;
				newForse.x -= normal.x;
				newForse.y -= normal.y;

				newForse = Normalize(newForse);
				normal = Normalize(normal);

				float alfa = (newForse.x*normal.x + newForse.y*normal.y);
				if (alfa < 0)
				{
					alfa = -alfa;
				}
				float Forse = player2[i]->GetKnockForce();

				player1[j]->AddForse(normal, Forse * alfa);
				player2[i]->AddForse(newForse, Forse - Forse* alfa);
			}
		}
	}



}
void PlayingField::CheckPenetration()
{
	for (int i = 0; i < player1.size(); i++) 
	{
		for (int j = 0; j < player1.size(); j++)
		{
			if (j != i && player1[i]->GetKnockForce() > 0.1 && player1[j]->Distance(*player1[i]) <= player1[i]->GetRadius() * 2 + 1)
			{
				sf::Vector2f Connection = player1[i]->GetCoordinates();
				Connection -= player1[j]->GetCoordinates();
				int Range = Distanse(Connection);
				Range = player1[i]->GetRadius() * 2 - player1[j]->Distance(*player1[i]) + 2;
				Connection = Normalize(Connection);
				Connection.x *= Range;
				Connection.y *= Range;
				sf::Vector2f PlayerCoord = player1[i]->GetCoordinates();
				PlayerCoord += Connection;
				player1[i]->SetCoord(PlayerCoord);
			}
		}
		for (int j = 0; j < player2.size(); j++)
		{
			if (player1[i]->GetKnockForce() > 0.1 && player2[j]->Distance(*player1[i]) <= player1[i]->GetRadius() * 2+1)
			{
				sf::Vector2f Connection = player1[i]->GetCoordinates();
				Connection -= player2[j]->GetCoordinates();
				int Range = Distanse(Connection);
				Range = player1[i]->GetRadius() * 2 - player2[j]->Distance(*player1[i]) + 2;
				Connection = Normalize(Connection);
				Connection.x *= Range;
				Connection.y *= Range;
				sf::Vector2f PlayerCoord = player1[i]->GetCoordinates();
				PlayerCoord += Connection;
				player1[i]->SetCoord(PlayerCoord);
			}
		}
	}


	for (int i = 0; i < player2.size(); i++)
	{
		for (int j = 0; j < player2.size(); j++)
		{
			if (j != i && player2[i]->GetKnockForce() > 0.1 && player2[j]->Distance(*player2[i]) <= player2[i]->GetRadius() * 2 + 1)
			{
				sf::Vector2f Connection = player2[i]->GetCoordinates();
				Connection -= player2[j]->GetCoordinates();
				int Range = Distanse(Connection);
				Range = player2[i]->GetRadius() * 2 - player2[j]->Distance(*player2[i]) + 2;
				Connection = Normalize(Connection);
				Connection.x *= Range;
				Connection.y *= Range;
				sf::Vector2f PlayerCoord = player2[i]->GetCoordinates();
				PlayerCoord += Connection;
				player2[i]->SetCoord(PlayerCoord);
			}
		}
	}
}
void PlayingField::CheckExit()
{
	//≈сли шашка больше чем на половину за пределами пол€ удал€ем ее
	for (int i = 0; i < player1.size(); i++)
		if (player1[i]->GetCoordinates().x < -player1[i]->GetRadius() || player1[i]->GetCoordinates().y < -player1[i]->GetRadius() ||
			player1[i]->GetCoordinates().x > 600 - player1[i]->GetRadius() || player1[i]->GetCoordinates().y > 600 - player1[i]->GetRadius())
		{
			delete player1[i];
			player1.erase(player1.begin() + i);
		}
	for (int i = 0; i < player2.size(); i++)
		if (player2[i]->GetCoordinates().x < -player2[i]->GetRadius() || player2[i]->GetCoordinates().y < -player2[i]->GetRadius() ||
			player2[i]->GetCoordinates().x > 600 - player2[i]->GetRadius() || player2[i]->GetCoordinates().y > 600 - player2[i]->GetRadius())
		{
			delete player2[i];
			player2.erase(player2.begin() + i);
		}
}
PlayingField::~PlayingField()//ƒеструктор
{
	for (int i = 0; i < player1.size(); i++)
		delete player1[i];
			
	for (int i = 0; i < player2.size(); i++)
		delete player2[i];

	
	player1.clear();
	player2.clear();
}