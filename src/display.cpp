#include "display.h"
#include "resourcehandler.h"

Display::Display()
{
   m_xPos = 0.0f;
   m_yPos = 0.0f;

   m_display.setPosition(Vector2f(m_xPos, m_yPos));
   m_display.setFillColor(Color::Black);
   m_display.setSize(Vector2f(20.0f, 30.0f));

   m_text.setFont(ResourceHandler::getInstance().getClockFont());
   m_text.setFillColor(Color::Red);
   m_text.setString("0");
}

Display::Display(float x, float y)
{
   m_xPos = x;
   m_yPos = y;

   m_display.setPosition(Vector2f(m_xPos, m_yPos));
   m_display.setFillColor(Color::Black);
   m_display.setSize(Vector2f(20.0f, 30.0f));

   m_text.setFont(ResourceHandler::getInstance().getClockFont());
   m_text.setFillColor(Color::Red);
   m_text.setString("0");
}

Display::~Display()
{

}

void
Display::setPosition(float x, float y)
{
   m_xPos = x;
   m_yPos = y;
}

void
Display::setText(String text)
{
   m_text.setString(text);
}

void
Display::Draw(RenderWindow& window)
{
   window.draw(m_display);
   window.draw(m_text);
}
