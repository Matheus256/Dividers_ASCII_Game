#pragma once

#include <iostream>
#include <string>
#include <array>

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/TextSprite.hpp"

//Colocar dentro de Node
//COlocar em caixa alta
enum Direcao{
    acima = 0,
    acima_direita = 1,
    abaixo_direita = 2,
    abaixo = 3,
    abaixo_esquerda = 4,
    acima_esquerda = 5
};

bool checar_divisor_valido(int, int);

class Node: public ObjetoDeJogo{

    friend std::ostream &operator<<(std::ostream &, const Node &);

public:
    //Node(std::string, int = 0);
    Node(std::string, const TextSprite &, int = 0, int = 0, int = 0);

    void setValor(int);
    int getValor() const{return valor;}
    std::string getRotulo() const{return rotulo;}

    bool checar_vizinhos() const;

    void inserir_no_adjacente(Node *, Direcao);

    Node *getNo(Direcao direcao) const {return nos_adjacentes[direcao];}

private:
    std::string rotulo;
    int valor;
    std::array<Node *, 6> nos_adjacentes;
};