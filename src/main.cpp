#include <iostream>
#include <string>

/*
#include "../ASCII_Engine/Cores.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/TextSprite.hpp"
*/

#include "FaseMenu.hpp"
#include "FaseLevel1.hpp"
#include "FaseLevel2.hpp"
#include "FaseLevel3.hpp"
#include "FaseAjuda.hpp"


int main(){
	system("clear");
	
	SpriteBuffer buffer(101, 25);


	FaseMenu fase("FaseMenu",Sprite("rsc/bg_verde.txt", COR::VERDE));
	fase.init();
	unsigned state = Fase::MENU;
	unsigned level = Fase::LEVEL_1;
	//unsigned level = Fase::LEVEL_3;

	while (state != Fase::END_GAME)
	{
		switch (state)
		{
			case Fase::MENU:
				state = fase.run(buffer);
				//level = Fase::LEVEL_1;
				break;
			case Fase::OP_1:
				{
					if (level == Fase::LEVEL_1)
					{
						FaseLevel1 fase1("Fase1",Sprite("rsc/bg_verde.txt", COR::VERDE));
						fase1.init();
						state = fase1.run(buffer);
					} else if(level == Fase::LEVEL_2){
						FaseLevel2 fase2("Fase2", Sprite("rsc/bg_verde.txt", COR::VERDE));
						fase2.init();
						state = fase2.run(buffer);
					} else if(level == Fase::LEVEL_3){
						FaseLevel3 fase3("Fase3", Sprite("rsc/bg_verde.txt", COR::VERDE));
						fase3.init();
						state = fase3.run(buffer);
					} else
						state = Fase::MENU;
				}
				break;
			case Fase::OP_2:
				{
					FaseAjuda faseAjuda("FaseAjuda",Sprite("rsc/bg_verde.txt", COR::VERDE));
					faseAjuda.init();
					state = faseAjuda.run(buffer);
				}
				break;
			case Fase::OP_3:
				system("clear");
				std::cout << "Saindo...\n";
				system("sleep 1");
				state = Fase::END_GAME;
				break;
			case Fase::LEVEL_COMPLETE:
				{
					//FaseLevelComplete faseLC("FaseLC",Sprite("rsc/background.img"));
					//faseLC.init();
					//state = faseLC.run(screen);
					level++;
					state = Fase::OP_1;
				}
				break;
			case Fase::GAME_OVER:
				{
					//FaseGameOver faseGO("FaseGO",Sprite("rsc/background.img"));
					//faseGO.init();
					//state = faseGO.run(screen);
					level = Fase::LEVEL_1;
					state = Fase::MENU;
				}
				break;
		}
	}

	return 0;
}
