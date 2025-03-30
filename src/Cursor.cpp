#include "Cursor.hpp"

void Cursor::subir(){
    Node *node = noAtual->getNo(acima);
    if(node){
        moveUp(4);
        noAtual = node;
    }
}

void Cursor::descer(){
    Node *node = noAtual->getNo(abaixo);
    if(node){
        moveDown(4);
        noAtual = node;
    }
}

void Cursor::esquerda(){
    Node *node = noAtual->getNo(acima_esquerda);
    if(node){
        moveLeft(7);
		moveUp(2);
        noAtual = node;
        return;
    }
    node = noAtual->getNo(abaixo_esquerda);
    if(node){
        moveLeft(7);
		moveDown(2);
        noAtual = node;
    }
}

void Cursor::direita(){
    Node *node = noAtual->getNo(acima_direita);
    if(node){
        moveRight(7);
		moveUp(2);
        noAtual = node;
        return;
    }

    node = noAtual->getNo(abaixo_direita);
    if(node){
        moveRight(7);
		moveDown(2);
        noAtual = node;
    }
}

void Cursor::sobrepoeValor(SpriteBase &screen, int linha, int coluna) const{
    int valor = noAtual->getValor();
    std::string str;
    if(valor <= 0)
        str = " ";
    else
        str = std::to_string(valor);

    ObjetoDeJogo value("valor", TextSprite(str), linha + 1, coluna + 3);
    value.draw(screen, value.getPosL(), value.getPosC());
}
