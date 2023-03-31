#include "tile.h"
#include "resourcehandler.h"

Tile::Tile()
{
   m_xPos = 0.0f;
   m_yPos = 0.0f;

   m_currentState = State_Closed;
   m_value = 0;
   m_mine = false;

   m_rect = Rect<float>(0.0f, 0.0f, 30.0f, 30.0f);
}

Tile::Tile(float x, float y)
{
   m_xPos = x;
   m_yPos = y;

   m_currentState = State_Closed;
   m_value = 0;
   m_mine = false;

   ResourceHandler::getInstance().getHiddenSprite().setPosition(m_xPos, m_yPos);
   m_rect = ResourceHandler::getInstance().getHiddenSprite().getGlobalBounds();
}

Tile::~Tile()
{

}

void
Tile::Draw(RenderWindow& window)
{
   switch(m_currentState)
   {
      case State_Closed:
            ResourceHandler::getInstance().getHiddenSprite().setPosition(m_xPos, m_yPos);
            window.draw(ResourceHandler::getInstance().getHiddenSprite());
            break;


      case State_Open:
         if(!m_mine)
         {
            ResourceHandler::getInstance().getOpenSprite().setPosition(m_xPos, m_yPos);
            window.draw(ResourceHandler::getInstance().getOpenSprite());

            if(m_value > 0)
            {
               Color val = Color::Blue;
               switch(m_value)
               {
                  case 1:
                     val = Color::Blue;
                     break;

                  case 2:
                     val = Color::Green;
                     break;

                  case 3:
                     val = Color::Red;
                     break;

                  case 4:
                     val = Color(255, 0, 255, 255);
                     break;

                  case 5:
                     val = Color(0, 255, 255, 255);
                     break;

                  case 6:
                     val = Color(255, 255, 0, 255);
                     break;

                  case 7:
                     val = Color::Black;
                     break;

                  case 8:
                     val = Color::White;
                     break;

                  default:
                     val = Color::Blue;
               }
               ResourceHandler::getInstance().getText(m_value, Color::Blue).setPosition(m_xPos + 10, m_yPos + 5);
               window.draw(ResourceHandler::getInstance().getText(m_value, val));
            }
         }
         else
         {
            ResourceHandler::getInstance().getBombSprite().setPosition(m_xPos, m_yPos);
            window.draw(ResourceHandler::getInstance().getBombSprite());
         }

         break;

      case State_Flagged:
         ResourceHandler::getInstance().getFlaggSprite().setPosition(m_xPos, m_yPos);
         window.draw(ResourceHandler::getInstance().getFlaggSprite());
         break;

      case State_Mine:
         break;
   }
}

bool
Tile::clicked(float xPos, float yPos)
{
   return m_rect.contains(xPos, yPos);
}

void
Tile::setState(State state)
{
   m_currentState = state;
}

void
Tile::setValue(int value)
{
   m_value = value;
}

void
Tile::setMine(bool mine)
{
   m_mine = mine;
}

Tile::State
Tile::getState()
{
   return m_currentState;
}

int
Tile::getValue()
{
   return m_value;
}

bool
Tile::getMine()
{
   return m_mine;
}
