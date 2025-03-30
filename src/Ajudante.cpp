#include "Ajudante.hpp"

void Ajudante::carregarFalas(std::string path){
    falasTC.addFromFile(path);
}

const std::string &Ajudante::falaSorteada(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,falasTC.get_size() - 2);

    const std::string &sorteado{std::to_string(var(generator))};

    return falasTC.getText(sorteado);
}