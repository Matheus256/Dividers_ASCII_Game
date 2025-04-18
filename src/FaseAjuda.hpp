#pragma once

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "../ASCII_Engine/Sound.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"

class FaseAjuda: public Fase{
    public:
        FaseAjuda(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
        FaseAjuda(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
        virtual ~FaseAjuda() {}
    
    
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
    
        //bool colideComBloco() const;
    
    private:
        //ObjetoDeJogo *pSelE,*pSelD;
        //unsigned op;
};