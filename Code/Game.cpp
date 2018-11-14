#include "Game.h"
#include <Windows.h>
#include "VectorOverloads.h"
Game::Game(sf::RenderWindow * window, int complexity, bool ComputerGame)//Конструктор в котором инициализируются поля 
	:Window(window),
	Computer(ComputerGame),
	Field("images/Field.png", "images/Cheker1.png", "images/Cheker2.png")
{
	Complexity = complexity;
	if (ComputerGame)//В зависимости от выбора второй игрок либо человек либо компьютер
	{
		player1 = new HumanPlayer("images/Direction.png");
		player2 = new ComputerPlayer();
	}
	else
	{
		player1 = new HumanPlayer("images/Direction.png");
		player2 = new HumanPlayer("images/Direction.png");
	}
}

void Game::StartGame()
{


	sf::Texture texture_turn_white;//сфмл текстура
	sf::Texture texture_turn_red;
	sf::Sprite sprite_turn;

	texture_turn_white.loadFromFile("images/WhiteTurn.png");
	texture_turn_red.loadFromFile("images/RedTurn.png");

	sf::Vector2f TurnVec(630, 240);
	sprite_turn.setPosition(TurnVec);

	// Создаем переменную таймера (нужен для плавной анимации)
	sf::Clock clock;
	
	bool click_flag_player1 = false;//Переменная для проверки отпустил ли игрок мышь после нажатия
	bool click_flag_player2 = false;
	bool flag_player_queue = true;//Определяет очередность ходов

	while (Window->isOpen())//Цикл в котором происходит отрисовка.
	{
		sf::Event event;
		while (Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window->close();
				exit(0);
			}
		}
		Window->clear();
	


		Field.CheckPenetration();
		Field.Drow(*Window);//Поле выводит себя и шашки

		if (!Field.Move())//Если шашки не двигаются игроки делают ход
		{
	
			if (flag_player_queue)
			{
				TurnVec = { 610, 240 };
				sprite_turn.setTexture(texture_turn_white);
				sprite_turn.setPosition(TurnVec);
				Window->draw(sprite_turn);
				if (((HumanPlayer*)player1)->GetChose())//Выбрана ли игроком одна из своих шашек
				{


					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)//Запоминаем нажатие на клавишу
							click_flag_player1 = true;


						if (event.mouseButton.button == sf::Mouse::Right)//Если игрок нажал правую кнопку отменяем выбор шашки
						{
							
							dynamic_cast<HumanPlayer*>(player1)->ChangeChose();
							Window->setMouseCursorVisible(true);
						}
					}
					if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && click_flag_player1)
						//Если игрок выбрал шашку и выстрелил

					{
						sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
						sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
						sf::Vector2f direction = { pos.x - dynamic_cast<HumanPlayer*>(player1)->GetCheker().x, pos.y - dynamic_cast<HumanPlayer*>(player1)->GetCheker().y };
						//Получаем направление удара по шашке 
						//Длина вектора - сила
						float forse = Distanse(direction);

						sf::Vector2f direction_normalised = { direction.x / forse, direction.y / forse };
						if (forse > 150)
							forse = 150;
						//Ограничиваем силу размером стрелки на экране

						forse /= GetPowerBalanse();
						//Уменьшаем силу 

						Field.SetChekerSpeed(dynamic_cast<HumanPlayer*>(player1)->GetCheker(), direction_normalised, forse);//Передаем силу и направление выбранной шашке
						dynamic_cast<HumanPlayer*>(player1)->ChangeChose();
						Window->setMouseCursorVisible(true);
						click_flag_player1 = false;
						flag_player_queue = false;
					}

					else//Если игрок ничего не нажимает но выбрал шашку рисуем направление ее полета
					{
						sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
						sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
						dynamic_cast<HumanPlayer*>(player1)->DrawArrow(*Window);
					}

				}
				else
				{
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							//Если игрок не выбрал шашку но нажал на левую кнопку
							//Проверяем нажал ли он на свою шашку, запоминаем ее 
							sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
							sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
							if (Field.IsChekerPlayer1(pos))
							{
								dynamic_cast<HumanPlayer*>(player1)->SetCheker(pos);
								dynamic_cast<HumanPlayer*>(player1)->ChangeChose();
								Window->setMouseCursorVisible(false);

							}
						}

				}

			}
			else
			{
				TurnVec = { 630, 240 };
				sprite_turn.setTexture(texture_turn_red);
				sprite_turn.setPosition(TurnVec);
				Window->draw(sprite_turn);
				if (Computer)//В случае игры с компьютером
				{
					int CompCheker = Field.GetSizeOfPlayer2Chekers();
					int HumCheker = Field.GetSizeOfPlayer1Chekers();
					float Forse = dynamic_cast<ComputerPlayer*>(player2)->GetKnock(CompCheker, HumCheker); 
					//Получаем колличество шашек у первого и второго игрока, случайно выбираем две из них
					Forse /= GetPowerBalanse();
					//Придаем одной из них импульс в сторону другой
					Field.ShootFromPlayer2ToPlayer1(CompCheker, HumCheker, Forse, 10 / Complexity);

					flag_player_queue = true;
				}
				else//В случае игры с человеком алгоритм аналогичен опианному ранее.
				{
					TurnVec = { 630, 240 };
					sprite_turn.setTexture(texture_turn_red);
					sprite_turn.setPosition(TurnVec);
					Window->draw(sprite_turn);
					
					if (((HumanPlayer*)player2)->GetChose())
					{


						if (event.type == sf::Event::MouseButtonPressed)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
								click_flag_player2 = true;


							if (event.mouseButton.button == sf::Mouse::Right)
							{
								Window->setMouseCursorVisible(true);
								dynamic_cast<HumanPlayer*>(player2)->ChangeChose();
							}
						}
						if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && click_flag_player2)

						{
							sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
							sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
							sf::Vector2f direction = { pos.x - dynamic_cast<HumanPlayer*>(player2)->GetCheker().x, pos.y - dynamic_cast<HumanPlayer*>(player2)->GetCheker().y };
							float forse = sqrt(direction.x*direction.x + direction.y*direction.y);


							sf::Vector2f direction_normalised = { direction.x / forse, direction.y / forse };
							if (forse > 150)
								forse = 150;
							forse /= GetPowerBalanse();
							Field.SetChekerSpeed(dynamic_cast<HumanPlayer*>(player2)->GetCheker(), direction_normalised, forse);
							dynamic_cast<HumanPlayer*>(player2)->ChangeChose();
							Window->setMouseCursorVisible(true);
							click_flag_player2 = false;
							flag_player_queue = true;
						}

						else
						{
							sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
							sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
							dynamic_cast<HumanPlayer*>(player2)->DrawArrow(*Window);
						}

					}
					else
					{
						if (event.type == sf::Event::MouseButtonReleased)
							if (event.mouseButton.button == sf::Mouse::Left)
							{


								sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//забираем коорд курсора
								sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
								if (Field.IsChekerPlayer2(pos))
								{
									dynamic_cast<HumanPlayer*>(player2)->SetCheker(pos);
									dynamic_cast<HumanPlayer*>(player2)->ChangeChose();
									Window->setMouseCursorVisible(false);
								}
							}

					}

				}
				
			}

		}
		
		Field.CheckClash();//Проверяем столкновение шашек

		Field.CheckExit();//Удаляем вылетевшие за пределы шашки


		if (!Field.GetSizeOfPlayer1Chekers())
			//Проверяем наличие шашек у игроков определяем победу в раунде или игре
		{
			++(*player2);
			if (player2->GetScore() > 3)
			{
				Window->clear();
				Win("images/FieldRed.png");
				Field.~PlayingField();
				return ;
			}
			Field.NewLevel(player1->GetScore(), player2->GetScore());
			flag_player_queue = true;
		}
		else if (!Field.GetSizeOfPlayer2Chekers())
		{
			++(*player1);
			if (player1->GetScore() > 3)
			{
				
				Win("images/FieldWhite.png");
				return;
			}
			Field.NewLevel(player1->GetScore(), player2->GetScore());
			
			flag_player_queue = ((player1->GetScore() + player2->GetScore()) % 2) == 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			{
				Sleep(100);
				++(*player2);
				if (player2->GetScore() > 3)
				{
				
					Win("images/FieldRed.png");
					return;
				}

				Field.NewLevel(player1->GetScore(), player2->GetScore());
				flag_player_queue = ((player1->GetScore() + player2->GetScore()) % 2) == 0;
			}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			return;
		}


		


		Window->display();
	}


}

void Game::Win(string Image)//Метод который показывает сообщение о победе
{
	
	Field.~PlayingField();
	sf::Image image_win;//сфмл изображение
	sf::Texture texture_win;//сфмл текстура
	sf::Sprite sprite_win;

	image_win.loadFromFile(Image);
	texture_win.loadFromImage(image_win);
	sprite_win.setTexture(texture_win);


	while (Window->isOpen())
	{
		sf::Event event;
		while (Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window->close();
				exit(0);
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;
		Window->clear();

		Window->draw(sprite_win);

		Window->display();

	}
}

Game::~Game()
{
	if (Computer)//В зависимости от выбора второй игрок либо человек либо компьютер
	{
		delete  (HumanPlayer*)(player1);
		delete (ComputerPlayer*)(player2);
	}
	else
	{
		delete  (HumanPlayer*)(player1);		
		delete  (HumanPlayer*)(player2);
	}
}


