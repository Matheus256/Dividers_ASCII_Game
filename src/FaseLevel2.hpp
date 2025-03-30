#pragma once

#include <cctype> //Para o isdigit
#include <string> 
#include <algorithm>  // Necessário para std::replace

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"
#include "../ASCII_Engine/Sound.hpp"

#include "Node.hpp"
#include "Grafo.hpp"
#include "Cursor.hpp"
#include "Texto.hpp"
#include "Ajudante.hpp"
#include "AjudanteMotivacional.hpp"

class FaseLevel2: public Fase{
public:
    FaseLevel2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
    FaseLevel2(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
    virtual ~FaseLevel2() {}


    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    //bool colideComBloco() const;

private:
    Grafo *comeia;
    Cursor *cursor;
    ObjetoDeJogo *caixa;
    Texto *frase;
    Ajudante *lisa;
};