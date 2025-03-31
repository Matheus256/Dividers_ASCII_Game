<h1 align="center" style="font-weight: bold;">Dividers ASCII Game 🎮</h1>

<p>Como desafio final da disciplina de Programação Orientada a Objetos (POO) do curso de Engenharia de Computação, desenvolvi um jogo
envolvendo o assunto de multiplos e divisores da Matemática. Foi proposto que o jogo fosse desenvolvido usando a Engine criada pelo 
professor da disciplina. Por meio da magnifica Engine é possível criar jogo em ASCII arte com fluídez e agilidade. O link para acessar a engine está logo abaixo:</p>

<p align="center">
    <a href="https://github.com/victorHSS/Cpp-ASCII-Game-Engine">The ASCII Game Engine 🕹️</a>
</p>

<h2>Descrição do Jogo</h2>
<p>O jogo é essencialemte composto por um grafo no formato de hexagonos (similares a colmeias, termo que comumente será usado também) na cor amarela, nos quais o jogodor pode inserir números inteiros positivos de no máximo dois digitos.
O navegação pelas colmeias acontece por meio de um curso que tem o formato de um hexgonal incompleto na cor branco. Com o cursor sobre a comeia desejada, para inserir um número basta digitar a tecla correspondente, a saber: 1, 2, 3, 4, 5, 6, 7, 8 e 9. Caso deseje inserir um número com dois dígitos então basta inserir um digito e depois outro. Para vencer a seguinte regra deve ser satisfeita:</p>

<p align="center">
    TODAS AS COLMEIAS DEVEM SER PREENCHIDAS COM NÚMEROS DISTINTOS, DE TAL SORTE QUE OS NÚMEROS NAS COLMEIAS ADJACENTES DEVEM TER UM DIVISOR COMUM ESTRITAMENTE MAIOR DO QUE 1.
</p>

<p>Entede-se que duas colmeias são adjacentes quando os dois hexgonos compartilham um lado em comum. Cada colmeia é adjascentes a pelo menos uma outra comeia, sendo possível a uma colmeia ser adjascente a outras seis colmeias.
Atenção, outras restrições podem ser aplicadas durante as fazes para deficultar o resolução, como por exemplo permitir que números menores do que 13 possam ser usados: neste caso deve-se usar apenas os números 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 11 e 12 para preencher todas as colmeias de determinada fase. Instruções adicionais de como jogar podem ser encontradas dentro do próprio jogo.</p>

<h2 id="layout">🎨 Layout do Jogo</h2>
<!--
![Imagem1](https://github.com/user-attachments/assets/6b5d1089-0090-4b59-94bc-3d96b96307ab)
![Imagem2](https://github.com/user-attachments/assets/f22a5594-27c0-4683-83c8-90326991ea1a)
-->

<p>Logo abaixo é possível observar imagens do Designe do jogo. Na imagem da esquerda temos o menu do jogo, com as opçoes de Iniciar, Ajuda e Sair. Para mover o cursor basta usar a teclas w e s.
Por meio da opção de ajuda é possível acessar o guia de como jogar.</p>

<p align="center">
    <img src="https://github.com/user-attachments/assets/6b5d1089-0090-4b59-94bc-3d96b96307ab" alt="Image do Menu do Jogo" width="400px">
    <img src="https://github.com/user-attachments/assets/f22a5594-27c0-4683-83c8-90326991ea1a" alt="Image da Primeira Fase do Jogo" width="400px">
</p>

A seguir também apresentamos um GIF da terceira fase do jogo:

![dividers](https://github.com/user-attachments/assets/4865da14-99df-4421-9763-7e9857b3d98e)

<p>Uma mais completa pode ser vista por meio do video no YouTube:</p>
<p align="center">
    <a href="https://www.youtube.com/watch?v=dIBq-FbOSdk">Gameplay no YouTube ▶️</a>
</p>

<h2 id="started">🚀 Como jogar?</h2>

Em um sistema `Linux` clone o repositório com o comando

```bash
git clone github.com/Matheus256/Dividers_ASCII_Game
```

Por fim adicione a permissão e crie o executável com os comandos

```bash
cd Dividers_ASCII_Game
chmod +x makeplay
./makeplay
```
Caso tenha ocorrido algum erro na execução do ./makeplay, então será necessario instalar o `g++` por meio do comando
```bash
sudo apt install g++
```

No jogo também existem músicas e efeitos sonoros. Caso nenhum som esteja tocando durante o jogo, então será necessario instalar o tocador de músicas `mpg321` no seu terminal. Para isto, basta executar o comando
```bash
  sudo apt install mpg321
```


