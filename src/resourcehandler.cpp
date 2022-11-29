#include "resourcehandler.h"

ResourceHandler::ResourceHandler()
{
   m_testShape.setRadius(100.f);
   m_testShape.setFillColor(sf::Color::Green);

   m_hiddenTexture.loadFromFile("resources\\textures\\hidden.png");
   m_hiddenSprite.setTexture(m_hiddenTexture);

   m_openTexture.loadFromFile("resources\\textures\\unhidden.png");
   m_openSprite.setTexture(m_openTexture);

   m_bombTexture.loadFromFile("resources\\textures\\bomb.png");
   m_bombSprite.setTexture(m_bombTexture);

   m_flaggTexture.loadFromFile("resources\\textures\\flag.png");
   m_flaggSprite.setTexture(m_flaggTexture);

   m_font.loadFromFile("resources\\Fonts\\Retro Stereo Wide.ttf");

   m_text.setFont(m_font);
   m_text.setCharacterSize(15);
   m_text.setFillColor(Color::Cyan);
}

ResourceHandler::~ResourceHandler()
{

}

CircleShape
ResourceHandler::getTestShape()
{
   return m_testShape;
}

Sprite&
ResourceHandler::getHiddenSprite()
{
   return m_hiddenSprite;
}

Sprite&
ResourceHandler::getOpenSprite()
{
   return m_openSprite;
}

Sprite&
ResourceHandler::getBombSprite()
{
   return m_bombSprite;
}

Sprite&
ResourceHandler::getFlaggSprite()
{
   return m_flaggSprite;
}

Font&
ResourceHandler::getFont()
{
   return m_font;
}

Text&
ResourceHandler::getText(int mines, Color color)
{
   m_text.setFont(m_font);
   m_text.setCharacterSize(15);
   m_text.setFillColor(color);

   m_text.setString(toString(mines));

   return m_text;
}

String
ResourceHandler::toString(int val)
{
   ostringstream os;
   os << val;
   return os.str();
}

String
ResourceHandler::toStringf(float val)
{
   ostringstream os;
   os << val;
   return os.str();
}