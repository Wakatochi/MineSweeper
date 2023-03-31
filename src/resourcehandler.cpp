#include "resourcehandler.h"

ResourceHandler::ResourceHandler()
{
   Vector2f scale = {0.75f, 0.75f};

   m_testShape.setRadius(100.f);
   m_testShape.setFillColor(sf::Color::Green);

   m_hiddenTexture.loadFromFile("resources\\textures\\hidden.png");
   m_hiddenSprite.setTexture(m_hiddenTexture);
   m_hiddenSprite.setScale(scale);

   m_openTexture.loadFromFile("resources\\textures\\unhidden.png");
   m_openSprite.setTexture(m_openTexture);
   m_openSprite.setScale(scale);

   m_bombTexture.loadFromFile("resources\\textures\\bomb.png");
   m_bombSprite.setTexture(m_bombTexture);
   m_bombSprite.setScale(scale);

   m_flaggTexture.loadFromFile("resources\\textures\\flag.png");
   m_flaggSprite.setTexture(m_flaggTexture);
   m_flaggSprite.setScale(scale);

   m_faceNormalTexture.loadFromFile("resources\\textures\\smile.png");
   m_faceNormalSprite.setTexture(m_faceNormalTexture);

   m_faceOpenTexture.loadFromFile("resources\\textures\\oh.png");
   m_faceOpenSprite.setTexture(m_faceOpenTexture);

   m_faceWinTexture.loadFromFile("resources\\textures\\win.png");
   m_faceWinSprite.setTexture(m_faceWinTexture);

   m_faceDeadTexture.loadFromFile("resources\\textures\\dead.png");
   m_faceDeadSprite.setTexture(m_faceDeadTexture);

   m_font.loadFromFile("resources\\Fonts\\Retro Stereo Wide.ttf");
   m_clockFont.loadFromFile("resources\\Fonts\\lcddot_tr.ttf");

   m_text.setFont(m_font);
   m_text.setCharacterSize(15);
   m_text.setFillColor(Color::Cyan);
   m_text.setScale(scale);

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

Sprite&
ResourceHandler::getFaceNormalSprite()
{
   return m_faceNormalSprite;
}

Sprite&
ResourceHandler::getFaceOpenSprite()
{
   return m_faceOpenSprite;
}

Sprite&
ResourceHandler::getFaceWinSprite()
{
   return m_faceWinSprite;
}

Sprite&
ResourceHandler::getFaceDeadSprite()
{
   return m_faceDeadSprite;
}

Font&
ResourceHandler::getFont()
{
   return m_font;
}

Font&
ResourceHandler::getClockFont()
{
   return m_clockFont;
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