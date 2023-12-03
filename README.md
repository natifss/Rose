# Projeto: Rosie

## Sumário

<ol>
<a href="#descricao"><li>Descrição</li></a>
<a href="#integrantes"><li>Integrantes</li></a>
<a href="#tecnologias"><li>Tecnologias utilizadas</li></a>
<a href="#front"><li>Informações sobre o frontend</li></a>
<a href="#back"><li>Informações sobre o backend</li></a>
<a href="#passos"><li>Passos para rodar esse projeto</li></a>
<a href="#consideracoes"><li>Considerações finais</li></a>
<a href="#melhorias"><li>Possíveis Melhorias</li></a>
</ol>

<div id="descricao">
<h2>Descrição</h2>
</div>

  Desenvolvemos um sistema de controle web para uma lâmpada led RGD, estabelecendo comunicação entre o dispositivo NodeMCU via protocolo HTTP. O NodeMCU, por sua vez, se comunicava com a lâmpada por meio de infravermelho, proporcionando a capacidade de controle remoto de qualquer local, fugindo do alcance limitado do controle padrão fornecido com a lâmpada.

  ![demo](https://github.com/natifss/Rosie/blob/main/demo.jpg)

<div id="integrantes">
<h2>Integrantes</h2>
</div>

| ![teste](https://avatars.githubusercontent.com/u/126435035?v=4) | ![teste](https://avatars.githubusercontent.com/u/125417531?v=4) | ![teste](https://avatars.githubusercontent.com/u/90714332?v=4) | ![teste](https://avatars.githubusercontent.com/u/119085630?v=4) |
| - | - | - | - |
| [Ana Julia G. Peres](https://github.com/AnaJuliaGPeres) | [Anna Clara Bragato](https://github.com/annaclarabragato) | [Arthur Lunkes](https://github.com/arthurlunkes) | [Natali C. F. Santos](https://github.com/natifss) |

  Cada um desempenhou um papel fundamental, contribuindo para a diversidade de habilidades e experiências que enriqueceram o projeto.

<div id="tecnologias">
<h2>Tecnologias utilizadas</h2>
</div>

- Figma (Para criação de protótipo mobile)
- HTML/CSS/JS
- PlataformIO (Para desenvolver no nodeMCU)
- C++ (Para dispositivo IOT nodeMCU)
- IRremote (Lib para C++ para receber e enviar sinais infravermelho)

<div id="front">
<h2>Informações sobre o frontend</h2>
</div>

  O frontend foi desenvolvido com HTML/CSS/JS, contém páginas sobre o grupo, sobre o aplicativo, cores, sobre cadastro/login no aplicativo, e a tela principal que contém o controle remoto da lâmpada, também fazendo conexão com as demais páginas.

<div id="back">
<h2>Informações sobre o backend</h2>
</div>

  O backend foi desenvolvido utilizando VSCode com a extensão plataformIO, que possibilita desenvolver em C++ e enviar o código para o nodeMCU com facilidade. Utilizando C++, primeiramente copiamos os sinais infravermelho emitidos pelo controle remoto da lâmpada, após isso inserimos um componente eletrônico que permite enviar os sinais infravermelho para a lâmpada. Por fim, fizemos um servidor que recebe as requisições e dependendo do endpoint, liga/desliga a lâmpada, liga led azul, etc.

<div id="passos">
<h2>Passos para rodar esse projeto</h2>
</div>

- Clone o repositório.
- Altere o ip caso precise no arquivo main.cpp do backend
- Mande o código do backend para o seu dispositivo nodeMCU.
- Altere o ip que está no arquivo js do front, para o ip que seu dispositivo nodeMCU possuí.
- Execute o frontend.
- Pronto! Está tudo funcionando.

<div id="consideracoes">
<h2>Considerações finais</h2>
</div>

  Nosso projeto, nomeado "Rosie", representa um avanço significativo na automação residencial ao proporcionar um controle web para uma lâmpada LED RGB. A comunicação eficiente entre o dispositivo NodeMCU e a lâmpada, estabelecida através do protocolo HTTP e infravermelho, permite o controle remoto de qualquer local, superando as limitações do controle padrão fornecido com a lâmpada.

<div id="melhorias">
<h2>Possíveis Melhorias</h2>
</div>

  Embora tenhamos alcançado nossos objetivos iniciais, reconhecemos que sempre há espaço para aprimoramento. Alguns pontos para futuras melhorias incluem:
    
  - Nosso projeto visa controlar somente uma lâmpada, se a casa possuir mais de uma lâmpada que devem ser controladas, do modo que está hoje o projeto, deve inserir mais um componente eletrônico para se comunicar com a lâmpada adicional(essa estratégia seria para diminuir custo e não precisar comprar mais um nodeMCU).
  - Se comunicar com a Alexa.
  - Controle por voz.
  - Gerar relatórios e gráficos de consumo, total de custo, etc.
  - Exploração de opções de controle via Wi-Fi, eliminando a dependência do infravermelho.
    
