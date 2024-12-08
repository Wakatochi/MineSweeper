#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML/Graphics.hpp>
#include "singleton.h"

#include <sstream>

using namespace sf;
using namespace std;

class ResourceHandler: public Singleton<ResourceHandler>
{
   public:
      ResourceHandler();
      ~ResourceHandler();

      CircleShape getTestShape();

      Sprite& getHiddenSprite();
      Sprite& getOpenSprite();
      Sprite& getBombSprite();
      Sprite& getFlaggSprite();

      Sprite& getFaceNormalSprite();
      Sprite& getFaceOpenSprite();
      Sprite& getFaceWinSprite();
      Sprite& getFaceDeadSprite();

      Texture* getBoarderTexture();

      Font& getFont();
      Font& getClockFont();
      Text& getText(int mines, Color color);

   private:
      CircleShape m_testShape;

      Texture m_hiddenTexture;
      Texture m_openTexture;
      Texture m_bombTexture;
      Texture m_flaggTexture;

      Texture m_faceNormalTexture;
      Texture m_faceOpenTexture;
      Texture m_faceWinTexture;
      Texture m_faceDeadTexture;

      Texture m_boarderTexture;

      Sprite m_hiddenSprite;
      Sprite m_openSprite;
      Sprite m_bombSprite;
      Sprite m_flaggSprite;

      Sprite m_faceNormalSprite;
      Sprite m_faceOpenSprite;
      Sprite m_faceWinSprite;
      Sprite m_faceDeadSprite;

      Sprite m_boarderSprite;

      Font m_font;
      Font m_clockFont;
      Text m_text;

      String toString(int val);
      String toStringf(float val);
};

#endif
