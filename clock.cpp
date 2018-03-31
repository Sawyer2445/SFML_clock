#include "clock.h"
_clock::_clock() : mWindow(sf::VideoMode(300, 300), "Clock", sf::Style::Close), hours(sf::Vector2f(110, 4)), minutes(sf::Vector2f(140, 4)), seconds(sf::Vector2f(140, 4)), dial(), back()
{
	dial.loadFromFile("Dial.png");	//загружаем картинку цифкрблата
	back.setTexture(dial);			
	back.setPosition(0, 0);			//устанавливаем позицию
	
	//настройки вида часовой стрелки
	hours.setFillColor(sf::Color::Black);	//цвет
	hours.setOrigin(0, 2);					//точка поворота
	hours.setPosition(150, 150);			//позиция
	//настройка вида минутной стрелки
	minutes.setFillColor(sf::Color::Black);	//цвет
	minutes.setOrigin(0, 2);				//точка поворота
	minutes.setPosition(150, 150);			//позиция
	//настройка вида секундной стрелки 
	seconds.setFillColor(sf::Color::Red);	//цвет
	seconds.setOrigin(0, 2);				//точка поворота
	seconds.setPosition(150, 150);			//позиция
}

void _clock::run() //основной метод, будет вызван в main
{
	while (mWindow.isOpen())
	{
		GetLocalTime(&t);	//получение времени
		processEvents();	//обработка событий
		update(t.wHour, t.wMinute, t.wSecond);//отправляем время 
		render();

	}
}

void _clock::update(int h, int m, int s)	//изменяет положение стрелок
{
	float hs = (h % 12) * 30 - 90 + ((m / 12) * 5);
	
	hours.setRotation(hs);
	minutes.setRotation(m * 6 - 90);
	seconds.setRotation(s * 6 - 90);

}

void _clock::render()	//отрисовывает объекты 
{
	//отрисовка
	mWindow.clear();

	mWindow.draw(back);
	mWindow.draw(hours);
	mWindow.draw(minutes);
	mWindow.draw(seconds);
	
	mWindow.display();
}

void _clock::processEvents()	//обработчик событий
{
	sf::Event _event;
	while (mWindow.pollEvent(_event)) //пока поступают события
	{
		//закрыть при закрытии окна или при нажатии на Escape
		if (_event.type == sf::Event::Closed || _event.key.code == sf::Keyboard::Escape)
			mWindow.close();
		
	}
}

_clock::~_clock()
{
}
