#include "Node.hpp"

bool checar_divisor_valido(int a, int b){
    int menor = (a >= b) ? b : a;
    for(int i = 2; i < menor + 1; i++){
        if((a % i == 0) && (b % i == 0))
            return true;
    }

    return false;
}

std::ostream &operator<<(std::ostream &out, const Node &node){
    if(node.nos_adjacentes.size() <= 0)
        return out;

    out << "Nos adjacentes ao no (" << node.rotulo << ", " << node.valor <<"):" << std::endl;
    for(int i = 0; i < 6; i++){
        if(node.nos_adjacentes[i]){
            out << "    (" << node.nos_adjacentes[i]->getRotulo() << ", ";
            out << node.nos_adjacentes[i]->getValor() << "), " << i << std::endl;
        }
    }

    return out;
}

Node::Node(std::string name, const TextSprite &s, int valor, int posL, int posC): ObjetoDeJogo(name, s, posL, posC){
    this->rotulo = name;
    setValor(valor);
    for(int i = 0; i < 6; i++)
        this->nos_adjacentes[i] = nullptr;
}

void Node::setValor(int valor){
    this->valor = (valor > 0) ? valor : 0;
    std::string str;
    if(valor <= 0)
        str = " ";
    else
        str = std::to_string(this->valor);

    //Dynamic Casting para fazer o ponteiro aponta para uma TextSprite e usar o método setText
    //Além disso é preciso fazer um const_cas
    TextSprite *pSprite{nullptr};
    pSprite = dynamic_cast <TextSprite *> (const_cast <SpriteBase*> (getSprite()));

    if(pSprite)
        pSprite->setText(str);
}

bool Node::checar_vizinhos() const{
    for(int i = 0; i < 6; i++){
        if (this->nos_adjacentes[i]){
            if (!(checar_divisor_valido(this->nos_adjacentes[i]->getValor(), this->valor)))
                return false;
        }
    }

    return true;
}

void Node::inserir_no_adjacente(Node *node, Direcao direcao){
    if(direcao == acima)
        node->moveTo(this->getPosL() - 4, this->getPosC());
    else if(direcao == acima_direita)
        node->moveTo(this->getPosL() - 2, this->getPosC() + 7);
    else if(direcao == abaixo_direita)
        node->moveTo(this->getPosL() + 2, this->getPosC() + 7);
    else if(direcao == abaixo)
        node->moveTo(this->getPosL() + 4, this->getPosC());
    else if(direcao == abaixo_esquerda)
        node->moveTo(this->getPosL() + 2, this->getPosC() - 7);
    else if(direcao == acima_esquerda)
        node->moveTo(this->getPosL() - 2, this->getPosC() - 7);

    //Antes de mudar
    this->nos_adjacentes[direcao] = node;
}
