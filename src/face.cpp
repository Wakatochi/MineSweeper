#include "face.h"
#include "resourcehandler.h"

Face::Face()
{
   m_xPos = 0.0f;
   m_yPos = 0.0f;
   m_state = Face_Normal;

   m_drawSprite.setOrigin(16.0f, 16.0f);
   m_drawSprite.setPosition(m_xPos, m_yPos);
}

Face::Face(float xPos, float yPos)
{
   m_xPos = xPos;
   m_yPos = yPos;
   m_state = Face_Normal;

   m_drawSprite.setOrigin(16.0f, 16.0f);
   m_drawSprite.setPosition(m_xPos, m_yPos);
}

Face::~Face()
{

}

void
Face::Draw(RenderWindow& window)
{
   Sprite drawSprite;

   switch(m_state)
   {
      case Face_Normal:
         drawSprite = ResourceHandler::getInstance().getFaceNormalSprite();
         break;

      case Face_Open:
         drawSprite = ResourceHandler::getInstance().getFaceOpenSprite();
         break;

      case Face_Win:
         drawSprite = ResourceHandler::getInstance().getFaceWinSprite();
         break;

      case Face_Dead:
         drawSprite = ResourceHandler::getInstance().getFaceDeadSprite();
         break;
   }

   window.draw(drawSprite);
}

void
Face::setState(State state)
{
   m_state = state;
}

void
Face::setXPos(float xPos)
{
   m_xPos = xPos;
}

void
Face::setYPos(float yPos)
{
   m_yPos = yPos;
}
