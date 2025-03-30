#include "Texto.hpp"

Texto::Texto(std::string name, const TextSprite &s, int posL, int posC): ObjetoDeJogo(name, s, posL, posC){
    linha1 = new TextSprite("");
    linha2 = new TextSprite("");
    linha3 = new TextSprite("");
    linha4 = new TextSprite("");
}


void Texto::colocarFrase(std::string texto) const{
    if(texto.size() <= 41){
        linha1->setText(texto);
        linha2->setText("");
        linha3->setText("");
        linha4->setText("");
    } else if(texto.size() <= 82){
        linha1->setText(texto.substr(0,41));
        linha2->setText(texto.substr(41,41));
        linha3->setText("");
        linha4->setText("");
    } else if(texto.size() <= 123){
        linha1->setText(texto.substr(0,41));
        linha2->setText(texto.substr(41, 41));
        linha3->setText(texto.substr(82));
        linha4->setText("");
    } else {
        linha1->setText(texto.substr(0,41));
        linha2->setText(texto.substr(41, 41));//(41,41)
        linha3->setText(texto.substr(82, 41));//(82,41)
        linha4->setText(texto.substr(123));
    }
}