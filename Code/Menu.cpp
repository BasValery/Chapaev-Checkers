#include "Menu.h"

bool Menu::ShowMenu(int & Complexity)
{

	//�������� ��� ����
	sf::Image image_back;//���� �����������
	sf::Texture texture_back;//���� ��������
	sf::Sprite sprite_back;


	image_back.loadFromFile("images/Field.png");
	texture_back.loadFromImage(image_back);
	sprite_back.setTexture(texture_back);




	sf::Image image_button;//���� �����������
	sf::Texture texture_button;//���� ��������
	sf::Sprite sprite_button;

	//������� ��� ��������� ������
	image_button.loadFromFile("images/button1.png");
	texture_button.loadFromImage(image_button);
	sprite_button.setTexture(texture_button);

	sf::Image image_button_pressed;//���� �����������
	sf::Texture texture_button_pressed;//���� ��������
	sf::Sprite sprite_button_pressed;
	
	//�������� ��� ������� ������
	image_button_pressed.loadFromFile("images/button2.png");
	texture_button_pressed.loadFromImage(image_button_pressed);
	sprite_button_pressed.setTexture(texture_button_pressed);

	//�������� ������
	sf::Font font;
	font.loadFromFile("images/MoolBoran.ttf");
	sf::Text txt;
	txt.setFont(font);
	txt.setFillColor(sf::Color::Black);


	sf::Vector2f button_coord = { 606, 220 };
	bool button1 = false;
	bool button2 = false;
	bool button3 = false;
	bool button4 = false;

	while (Window->isOpen())//���� � ������� ���������� ���������.
	{
	
			sf::Event event;
			while (Window->pollEvent(event))//���� ������������ ����� �� ������� ���� �����������
			{
				if (event.type == sf::Event::Closed)
				{
					Window->close();
					exit(0);
				}
			}


		Window->clear();


		
		Window->draw(sprite_back);

		sprite_button.setPosition(button_coord);
		//��������� ����� �� ������������ �� ������
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y && pos.y < 50 + button_coord.y)
			{
				txt.setPosition({ button_coord.x + 50, button_coord.y - 3});
				txt.setString(L"One player");

				sprite_button_pressed.setPosition(button_coord);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button1 = true; //���� ����� �� ���������� ��� 
			}
			else
			{
				txt.setPosition({ button_coord.x + 50, button_coord.y });
				txt.setString(L"One player");

				Window->draw(sprite_button);		
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 50, button_coord.y });
			txt.setString(L"One player");
	
			Window->draw(sprite_button);
			Window->draw(txt);
		}
	
	



		sprite_button.setPosition({ button_coord.x, button_coord.y + 60 });
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)		//��������� ����� �� ������������ �� ������
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 60 && pos.y < 50 + button_coord.y + 60)
			{
				txt.setPosition({ button_coord.x + 50, button_coord.y + 60 - 3 });
				txt.setString(L"Two players");

				sprite_button_pressed.setPosition(button_coord.x, button_coord.y + 60);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button2 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 50, button_coord.y + 60 });
				txt.setString(L"Two players");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 50, button_coord.y + 60});
			txt.setString(L"Two players");

			Window->draw(sprite_button);
			Window->draw(txt);
		}


		sprite_button.setPosition({ button_coord.x, button_coord.y + 120 });
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)		//��������� ����� �� ������������ �� ������
		{
			
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 120 && pos.y < 50 + button_coord.y + 120)
			{
				txt.setPosition({ button_coord.x + 80, button_coord.y + 120 - 3 });
				txt.setString(L"Help");

				sprite_button_pressed.setPosition(button_coord.x, button_coord.y + 120);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button3 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 80, button_coord.y + 120 });
				txt.setString(L"Help");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 80, button_coord.y + 120 });
			txt.setString(L"Help");

			Window->draw(sprite_button);
			Window->draw(txt);
		}


		sprite_button.setPosition({ button_coord.x, button_coord.y + 180 });
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)		//��������� ����� �� ������������ �� ������
		{

			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 180 && pos.y < 50 + button_coord.y + 180)
			{
				txt.setPosition({ button_coord.x + 80, button_coord.y + 180 - 3 });
				txt.setString(L"Exit");

				sprite_button_pressed.setPosition(button_coord.x, button_coord.y + 180);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button4 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 80, button_coord.y + 180 });
				txt.setString(L"Exit");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 80, button_coord.y + 180 });
			txt.setString(L"Exit");

			Window->draw(sprite_button);
			Window->draw(txt);
		}

	
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) 
			//���� ������������ �������� ����� �� ��������� ��� ��������� ����
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)

			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y && pos.y < 50 + button_coord.y && button1)
			{
				Complexity = ChoseComplexity();
				return true;
			}
			else if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 60 && pos.y < 50 + button_coord.y + 60 && button2)
			{
				return false;
			}
			else if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 120 && pos.y < 50 + button_coord.y + 120 && button3)
			{
				ShowHelp();
			}
			else if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 120 && pos.y < 50 + button_coord.y + 180 && button4)
			{
				Window->close();
				exit(0);
			}
			
				button1 = false;
				button2 = false;
				button3 = false;
				button4 = false;
			
			//���� ���� ���������� �� ������ �� ��������� ��������� ��������������� ��������	
		}
		

		Window->display();

	}

	return false;
}

int Menu::ChoseComplexity()//���� ������ ��������� ��� ���� � ����������
{


	//�������� ��� ����
	sf::Image image_back;//���� �����������
	sf::Texture texture_back;//���� ��������
	sf::Sprite sprite_back;


	image_back.loadFromFile("images/Field.png");
	texture_back.loadFromImage(image_back);
	sprite_back.setTexture(texture_back);




	sf::Image image_button;//���� �����������
	sf::Texture texture_button;//���� ��������
	sf::Sprite sprite_button;

	//�������� ��� ������� ������
	image_button.loadFromFile("images/button1.png");
	texture_button.loadFromImage(image_button);
	sprite_button.setTexture(texture_button);

	sf::Image image_button_pressed;//���� �����������
	sf::Texture texture_button_pressed;//���� ��������
	sf::Sprite sprite_button_pressed;

	//�������� ��� �� ������� ������
	image_button_pressed.loadFromFile("images/button2.png");
	texture_button_pressed.loadFromImage(image_button_pressed);
	sprite_button_pressed.setTexture(texture_button_pressed);


	//��������� �����
	sf::Font font;
	font.loadFromFile("images/MoolBoran.ttf");
	sf::Text txt;
	txt.setFont(font);
	txt.setFillColor(sf::Color::Black);


	sf::Vector2f button_coord = { 606, 220 };
	bool button1 = false;
	bool button2 = false;
	bool button3 = false;

	//��� ���� �������� ���������� �����������
	while (Window->isOpen())
	{

		sf::Event event;
		while (Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window->close();
		}


		Window->clear();



		Window->draw(sprite_back);

		sprite_button.setPosition(button_coord);
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y && pos.y < 50 + button_coord.y)
			{
				txt.setPosition({ button_coord.x + 45, button_coord.y - 3 });
				txt.setString(L"Easy");

				sprite_button_pressed.setPosition(button_coord);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button1 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 45, button_coord.y });
				txt.setString(L"Easy");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 45, button_coord.y });
			txt.setString(L"Easy");

			Window->draw(sprite_button);
			Window->draw(txt);
		}





		sprite_button.setPosition({ button_coord.x, button_coord.y + 60 });
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 60 && pos.y < 50 + button_coord.y + 60)
			{
				txt.setPosition({ button_coord.x + 55, button_coord.y + 60 - 3 });
				txt.setString(L"Normal");

				sprite_button_pressed.setPosition(button_coord.x, button_coord.y + 60);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button2 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 55, button_coord.y + 60 });
				txt.setString(L"Normal");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 55, button_coord.y + 60 });
			txt.setString(L"Normal");

			Window->draw(sprite_button);
			Window->draw(txt);
		}


		sprite_button.setPosition({ button_coord.x, button_coord.y + 120 });
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{

			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 120 && pos.y < 50 + button_coord.y + 120)
			{
				txt.setPosition({ button_coord.x + 85, button_coord.y + 120 - 3 });
				txt.setString(L"Hard");

				sprite_button_pressed.setPosition(button_coord.x, button_coord.y + 120);

				Window->draw(sprite_button_pressed);
				Window->draw(txt);

				button3 = true;
			}
			else
			{
				txt.setPosition({ button_coord.x + 85, button_coord.y + 120 });
				txt.setString(L"Hard");

				Window->draw(sprite_button);
				Window->draw(txt);
			}
		}
		else
		{
			txt.setPosition({ button_coord.x + 85, button_coord.y + 120 });
			txt.setString(L"Hard");

			Window->draw(sprite_button);
			Window->draw(txt);
		}


		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*Window);//�������� ����� �������
			sf::Vector2f pos = Window->mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)

			if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y && pos.y < 50 + button_coord.y  && button1)
			{
				return 1;
			}
			else if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 60 && pos.y < 50 + button_coord.y + 60 && button2)
			{
				return 8;
			}
			else if (pos.x > button_coord.x && pos.x < 190 + button_coord.x && pos.y > button_coord.y + 120 && pos.y < 50 + button_coord.y + 120 && button3)
				return 10;
			else
			{
				button1 = false;
				button2 = false;
				button3 = false;
			}
		}


		Window->display();

	}




	return 0;
}

void Menu::ShowHelp()
{

	sf::Texture texture_help;//���� ��������
	sf::Sprite sprite_help;

	texture_help.loadFromFile("images/FieldRules.png");
	sprite_help.setTexture(texture_help);
	while (Window->isOpen())//���� � ������� ���������� ���������.
	{

		sf::Event event;
		while (Window->pollEvent(event))//���� ������������ ����� �� ������� ���� �����������
		{
			if (event.type == sf::Event::Closed)
			{
				Window->close();
				exit(0);
			}
		}


		Window->clear();



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;

		Window->draw(sprite_help);
		Window->display();

	}

}
