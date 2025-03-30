#include "FaseMenu.hpp"

void FaseMenu::init(){

    objs.push_back(new ObjetoDeJogo("Ceu", SpriteAnimado("rsc/ceu.anm", 7, COR::AZUL), 1, 1));

    objs.push_back(new ObjetoDeJogo("Logo",SpriteAnimado("rsc/logo.anm",3,COR::AMARELA),4,14));

	//objs.push_back(new ObjetoDeJogo("TextGame",TextSprite("The ASCII Dividers"),3,40));
	//objs.push_back(new ObjetoDeJogo("Text----",TextSprite("---------------------------"),4,35));
	objs.push_back(new ObjetoDeJogo("MenuOp1",TextSprite("Iniciar",COR::AMARELA),6 + 4,44));
	objs.push_back(new ObjetoDeJogo("MenuOp2",TextSprite("Ajuda",COR::AMARELA),8 + 4,45));
	objs.push_back(new ObjetoDeJogo("MenuOp3",TextSprite("Sair",COR::AMARELA),10 + 4,46));
	
	objs.push_back(new ObjetoDeJogo("SelOpE",TextSprite("====>",COR::AMARELA),6 + 4,38));
	pSelE = objs.back();
	objs.push_back(new ObjetoDeJogo("SelOpD",TextSprite("<====",COR::AMARELA),6 + 4,53));
	pSelD = objs.back();
	
	op = Fase::OP_1;

}

unsigned FaseMenu::run(SpriteBuffer &screen)
{

	Sound backMusic("rsc/sounds/guitar-v10.mp3");
	backMusic.playloop();

	Keyboard::setMode(Keyboard::NONBLOCKING);

	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true)
	{
		
		//logica da fase acontece aqui
		//getline(std::cin,ent);
        char ent=Keyboard::read();

		if (ent == 'q') break;
		else if (ent == 's') {
			if(pSelE->getPosL() < 14){
				op = Fase::OP_1 + (op - Fase::OP_1  + 1) % 3;
			
				pSelE->moveTo(pSelE->getPosL() + 2, pSelE->getPosC());
				pSelD->moveTo(pSelD->getPosL() + 2, pSelD->getPosC());
			}
		}
		else if (ent == 'w') {
			if(pSelE->getPosL() > 10){
				op = Fase::OP_1 + (3 + ((op - Fase::OP_1) - 1)) % 3;
			
				pSelE->moveTo(pSelE->getPosL() - 2, pSelE->getPosC());
				pSelD->moveTo(pSelD->getPosL() - 2, pSelD->getPosC());
			}
		}
		else if (ent == 'x')
		{
			backMusic.stop();
			return op;
		}
			
		
		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);

		system("sleep 0.3");
	}

	backMusic.stop();
	return Fase::END_GAME;
}