#pragma once

#include <array>

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Node.hpp"

class Cursor: public ObjetoDeJogo{
public:
    Cursor(std::string name, const Sprite &s, int posL, int posC, Node *node) : 
		ObjetoDeJogo(name, s, posL, posC), noAtual(node) {}

    Node *getNoAtual() const{return noAtual;}
    void setNoAtual(Node *node) {noAtual = node;}
    
    void subir();
    void descer();
    void esquerda();
    void direita();

    void sobrepoeValor(SpriteBase &, int, int) const;

    virtual void draw(SpriteBase &screen, int x, int y) {
      ObjetoDeJogo::draw(screen,x,y);
      sobrepoeValor(screen,x,y);
    }

private:
    Node *noAtual;
};