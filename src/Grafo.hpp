#pragma once

#include <string>
#include <vector>

#include <set>

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Node.hpp"

class Grafo: public ObjetoDeJogo{
public:
  Grafo(std::string name, const Sprite &s, int posL, int posC, Node *node) : 
	ObjetoDeJogo(name, s, posL, posC), raiz(node) {}

  Node *getRaiz() const{return raiz;}

  void inserirNo(Node *);

  void desenhaValor(Node *, SpriteBase &, int, int) const;

  void desenhaValores(SpriteBase &, int, int) const;

  void desenharRecursivo(Node *, SpriteBase &, int, int) const;

  Node *checagem() const;

  virtual void draw(SpriteBase &screen, int x, int y) {
    ObjetoDeJogo::draw(screen,x,y);
    desenhaValores(screen,x,y);
  }

private:
  Node *raiz;
  std::vector<Node *> nos_do_grafo;
};