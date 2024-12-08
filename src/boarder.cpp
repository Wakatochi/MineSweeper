#include "boarder.h"
#include "resourcehandler.h"

Boarder::Boarder()
{
   m_sizeX = 0.0f;
   m_sizeY = 0.0f;

   m_face = new Face(0.0f, 0.0f);
   m_time = new Display();
   m_mines = new Display();

   m_frame.setSize(sf::Vector2f(0.0f, 0.0f));
   m_frame.setPosition(sf::Vector2f(0.0f, 0.0f));

   m_frame.setOutlineThickness(1);
   m_frame.setOutlineColor(sf::Color::Black);
   m_frame.setTexture(ResourceHandler::getInstance().getBoarderTexture());
}

Boarder::~Boarder()
{
   delete m_face;
   delete m_time;
   delete m_mines;
}

void
Boarder::setBoarderSize(float x, float y)
{
   m_frame.setSize(sf::Vector2f(100.0f, 100.0f));
   m_frame.setPosition(sf::Vector2f(0.0f, 0.0f));
}

void
Boarder::SetFaceStatus(Face::State state)
{
   m_face->setState(state);
}

void
Boarder::setClockPosition(float x, float y)
{
   m_time->setPosition(x, y);
}

void
Boarder::setMinePosition(float x, float y)
{
   m_mines->setPosition(x, y);
}

void
Boarder::setFacePosition(float x, float y)
{
   m_face->setPosition(x, y);
}

Vector2f
Boarder::getDisplaySize()
{
   return m_mines->getSize();
}

void
Boarder::Update(sf::String clockStr, sf::String minesStr)
{
   m_time->setText(clockStr);
   m_mines->setText(minesStr);
}

void
Boarder::Draw(RenderWindow& window)
{
   window.draw(m_frame);
   m_face->Draw(window);

   m_time->Draw(window);
   m_mines->Draw(window);
}
