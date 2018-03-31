#pragma once
#include "SFML/Graphics.hpp"	//для работы с прмитивной графикой
#include <Windows.h>			//для получения времени операционной системы
class _clock
{
private:
	sf::RenderWindow mWindow;		//окно
	sf::Texture dial;				//циферблат
	sf::Sprite back;			
	
	sf::RectangleShape hours;		//стрелка часов в виде прямоугольника
	sf::RectangleShape minutes;		//стрелка минут в виде прямоугольника
	sf::RectangleShape seconds;		//стрелка секунд в виде прямоугольника
	SYSTEMTIME t;					//переменная для получения времени ОС

	
public:
	_clock();								//конструктор
	void run();								//запуска
	void update(int h, int m, int s);		//вращение стрелок
	void render();							//отрисовка
	void processEvents();					//обработка событий
	~_clock();
};

