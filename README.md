Este projeto se trata de um protótipo para a implementação de coleta automática de lixo na linguagem de programação C.
A técnica usada é a de contagem de referências, onde são contados quantos ponteiros apontam para uma área de memória da Heap. Se essa contagem chegar a zero, a área de memória é liberada.

Os arquivos contidos são a biblioteca (contref.h) e um código para testar suas funções (contref-teste.c). 

Para implementar a contagem de referências, foi usada uma estrutura que guarda o dado da área de memória (de forma genérica) e contém uma variável inteira que indica o número de ponteiros.
É feito um vetor dessa estrutura para que isso possa ser feito com várias áreas de memória.

As funções principais são a malloc2 e a atrib2. A malloc2 aloca a memória na heap e adiciona a contagem de 1 ponteiro para ela, além de retornar o ponteiro para a área de memória.
A atrib2 faz com que um ponteiro aponte para a mesma área de outro, diminui a contagem da área para a qual este estava apontando antes e aumenta a contagem da área para a qual ele irá apontar. 
