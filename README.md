
<h2 align="center">UTILIZAÇÃO DE FONTES RENOVÁVEIS E ACUMULAÇÃO DE ENERGIA PARA GESTÃO E INSTALAÇÃO EM RESIDÊNCIAS<h2>

## Resumo

<p>Apresenta-se neste projeto um arranjo que utiliza fontes renováveis para gerar energia elétrica, que será acumulada e gerenciada através de um sistema microcontrolado. Aproveitando a nova resolução aprovada pela Agência Nacional de Energia Elétrica (ANEEL) denominada de tarifa branca, com o propósito de disponibilizar ao usuário que aderir ao sistema uma possibilidade de cooperar com o meio ambiente e reduzir custos em sua residência.</p>

## Introdução

<p>O expressivo aumento de energia no Brasil e no mundo fez com que as companhias de distribuição de energia junto com o governo tomassem medidas corretivas para aperfeiçoar o consumo de energia elétrica. Com isso surge a Resolução “Tarifa branca” que prevê o aumento do valor do KW/h em horários de pico, com o propósito de estimular a utilização da energia em horários de baixo consumo, tendo como principal objetivo uniformizar a curva de utilização de energia. Desse modo o governo posterga a necessidade de gastos na infraestrutura das redes de distribuição. 
Em análise a demanda da tarifa branca foi visualizada a necessidade de um sistema que visa captar, controlar e gerenciar a energia elétrica para que posteriormente essa energia seja consumida em horário de ponta.  Utilizando fontes de energia renovável, o sistema deverá ser automatizado com o objetivo de diminuir o consumo de energia nos horários de ponta onde o custo do KW/h será maior.
Buscamos com o desenvolvimento obter ganhos financeiros com a redução do consumo da energia gerada pelo sistema de distribuição. Outros ganhos mensuráveis são para o meio ambiente e para a companhia de rede elétrica que evitará gastos excessivos para manter a rede.</p>

## Objetivo Geral

<p>Gerar energia, acumulá-la e gerenciar as cargas em horário de pico.</p>

## Objetivo Específico

a) Dimensionamento da fonte geradora de energia;<br>
b) Especificar o acumulador utilizado;<br>
c) Definir potência do controlador de carga;<br>
d) Definir potência do inversor;<br>
e) Medir os níveis de consumo e geração;<br>
f) Controlar o sistema com o auxílio de um microcontrolador.<br>

## Hipótese

<p>Captar e controlar a energia elétrica utilizando fontes renováveis para que posteriormente essa energia seja consumida em horários de pico. Porém, em dias de baixa luminosidade o sistema pode ser afetado se o gerador de energia solar não conseguir abastecer completamente o acumulador.</p>

## Justificativa

<p>Aproveitando fontes renováveis para gerar energia, que será armazenada e utilizada conscientemente através de um controle em horários predeterminados. Resultaria em um alívio para o sistema de rede elétrica e possivelmente haveria um ganho econômico tanto para o consumidor quanto para a companhia de rede elétrica uma vez que a resolução “Tarifa Branca” esteja implantada.</p>
  
## Programação
  
 <p> Para realizar a gestão e controle da energia foi necessário o uso de microcontroladores PIC programáveis. Através da lógica de programação foi utilizada a linguagem C para traduzir os objetivos do projeto nas placas eletrônicas de controle. Ao todo, foram confeccionadas 3 placas eletrônicas que faziam a gestão e medição da energia enviando dados em tempo real pela porta analógica do coversor A/D. Essa informação recebida em Bits era tratada e convertida por meio de cálculo matemático para medições de corrente, tensão e sinais lógicos (0 ou 1). O código utilizado no projeto está disponibilizado no repositório.

## Conclusão

<p>Neste trabalho foi desenvolvido um sistema de controle e utilização de energia em horários pré-determinados com o auxílio de uma fonte geradora renovável, aproveitando a nova modalidade de cobrança redigida pela ANEEL (Tarifa Branca).
Este trabalho apresentou um novo método para controle da curva de utilização de energia, com meios para tentar reduzir ao máximo o consumo no horário de ponta.
Foi desenvolvido um software que aliado a um hardware, apresenta-se capaz de realizar leituras das variáveis do sistema e com isso tomar decisões de atuação sobre as cargas.
Nas simulações realizadas o conjunto se comportou de maneira eficiente e eficaz, sempre tomando decisões imediatas sobre os atuadores controlando as cargas conforme o estado das variáveis de entrada.
O sistema desenvolvido pode ser utilizado em residências, empresas e estabelecimentos comerciais, levando-se em consideração que as variáveis de acumulação e geração de energia podem ser multiplicadas conforme a demanda da planta.
Para trabalhos futuros sugere-se a implementação do circuito do módulo relé diretamente na placa de controle, o desenvolvimento do controlador de carga solar e do inversor de carga e a introdução de um sensor de corrente CA.
A principal contribuição deste trabalho é a estimulação do uso consciente de energia utilizando um sistema de controle microcontrolado aliado a um sistema de geração de energia renovável.</p>



