#include "Grafo.hpp"

void Grafo::inserirNo(Node *node){
    nos_do_grafo.push_back(node);
}

/*
void Grafo::desenhaValores(SpriteBase &screen, int linha, int coluna) const{

    desenhaValor(nos_do_grafo[0], screen, linha, coluna);

    desenhaValor(nos_do_grafo[1], screen, linha + 4, coluna);

    desenhaValor(nos_do_grafo[2], screen, linha + 8, coluna);

    desenhaValor(nos_do_grafo[3], screen, 12, 34);

    desenhaValor(nos_do_grafo[4], screen, 12, 62);

    desenhaValor(nos_do_grafo[5], screen, 14, 41);

    desenhaValor(nos_do_grafo[6], screen, 14, 55);

    desenhaValor(nos_do_grafo[7], screen, 16, 34);

    desenhaValor(nos_do_grafo[8], screen, 16, 62);

}
*/

void Grafo::desenhaValor(Node *aux, SpriteBase &screen, int linha, int coluna) const{
    if(aux){
        ObjetoDeJogo value("test", TextSprite(std::to_string(aux->getValor()), COR::AMARELA), linha + 3, coluna + 20);
        value.draw(screen, value.getPosL(), value.getPosC());
    }
}
 
void Grafo::desenhaValores(SpriteBase &screen, int linha, int coluna) const{

    for(const auto node : nos_do_grafo){
        node->draw(screen, node->getPosL() + 3, node->getPosC() + 20);
    }

}

Node *Grafo::checagem() const{
    std::set<int> set{};
    for(int i = 0; i < nos_do_grafo.size(); i++){
        set.insert(nos_do_grafo[i]->getValor());
        if(set.size() != i + 1)
            return nos_do_grafo[i];
        if(!(nos_do_grafo[i]->checar_vizinhos()))
            return nos_do_grafo[i];
    }

    return nullptr;
}