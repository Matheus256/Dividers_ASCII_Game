#include "FaseAjuda.hpp"

void FaseAjuda::init(){
    objs.push_back(new ObjetoDeJogo("Ceu", SpriteAnimado("rsc/ceu.anm", 7, COR::AZUL), 1, 1));

    objs.push_back(new ObjetoDeJogo("Instrucoes", TextSprite("INSTRUCOES DE COMO JOGAR",COR::AMARELA), 2,35));

    objs.push_back(new ObjetoDeJogo("testo2",TextSprite("Cursor"),9,40));
    objs.push_back(new ObjetoDeJogo("cursor", Sprite("rsc/Cursor.txt"), 7, 40));
    objs.push_back(new ObjetoDeJogo("comeia_unitaria", Sprite("rsc/comeia_unitaria.txt",COR::AMARELA), 5,50));
    objs.push_back(new ObjetoDeJogo("testo2",TextSprite("Comeia"),10,51));
    objs.push_back(new ObjetoDeJogo("texto1", TextSprite("Neste jogo voce movera o cursor pelas comeias:"),4,24));

    objs.push_back(new ObjetoDeJogo("texto3",TextSprite("Use as teclas a, w, s e d para mover o cursor para comeia a esquerda, acima, abaixo"),11,8));
    objs.push_back(new ObjetoDeJogo("texto4",TextSprite("e direita, respectivamente. Para inserir um digito (0 a 9) basta precionar a tecla corres-"),12,5));
    objs.push_back(new ObjetoDeJogo("texto5",TextSprite("pondente ao digito. Caso deseje inserir um numero com mais de um digito, entao precione o"),13,5));
    objs.push_back(new ObjetoDeJogo("texto6",TextSprite("primeiro digito e depois o segundo. MAS ATENCAO:"),14,5));
    objs.push_back(new ObjetoDeJogo("texto7", TextSprite("SAO ACEITOS APENAS NUMEROS POSITIVOS COM DOIS DIGITOS.",COR::AMARELA),16,20));
    objs.push_back(new ObjetoDeJogo("texto8",TextSprite("Use a tecla ESPACO para apagar o numero de uma comeia. Para realizar a checagem ou receber"),18,5));
    objs.push_back(new ObjetoDeJogo("texto9",TextSprite("uma dica use a tecla c. Para vencer a seguinte REGRA deve ser satisfeita:"),19,5));
    objs.push_back(new ObjetoDeJogo("texto10", TextSprite("OS NUMEROS NAS COMEIAS ADJACENTES DEVEM TER UM DIVISOR COMUM MAIOR DO QUE 1!",COR::AMARELA), 21,12));
	objs.push_back(new ObjetoDeJogo("texto11", TextSprite("PRECIONE q PARA VOLTA AO MENU"),23,67));
}

unsigned FaseAjuda::run(SpriteBuffer &screen){

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
        char ent=Keyboard::read();

		if (ent == 'q') break;
		//else if (ent == 's') {
			
		//}
			
		
		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);

		system("sleep 0.3");
	}

	backMusic.stop();
	return Fase::MENU;
}