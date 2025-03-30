#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/TextSprite.hpp"
#include "../ASCII_Engine/Core/SpriteBase.hpp"

class Texto: public ObjetoDeJogo{
public:
    Texto(std::string, const TextSprite &, int, int);

    void colocarFrase(std::string) const;

    virtual void draw(SpriteBase &screen, int x, int y) {
        linha1->draw(screen,x,y);
        linha2->draw(screen,x + 1,y);
        linha3->draw(screen,x + 2,y);
        linha4->draw(screen, x + 3, y);
    }

private:
    TextSprite *linha1, *linha2, *linha3, *linha4;
};