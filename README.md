📚 Minha Jornada com Ponteiros e Alocação Dinâmica e Vetores e Matrizes em C

Bom, Se você está aqui, provavelmente está estudando C e quer entender como eu resolvi cada um desses exercícios.
Vou mostrar o raciocínio que usei em cada questão. Espero que isso te ajude a compreender melhor os conceitos!

🧭 Bloco 1 – Ponteiros e Aritmética de Ponteiros
1. O básico: ponteiro apontando para uma variável
Como pensei:
Precisava mostrar que um ponteiro guarda endereços. Então criei x e p. Fiz p = &x – isso significa: “p, agora você aponta para o endereço da x”. Depois imprimi tudo: o valor de x, o endereço dela, o que p contém (que é o endereço) e o valor que está nesse endereço (o conteúdo de x). Simples, mas essencial.

2. Mudando o valor de uma variável sem tocar nela diretamente
O que pensei:
Com p apontando para n, usei *p = 20. Aqui a mágica: *p é como se fosse a própria n. Assim, alterei n de forma indireta. É como ter um controle remoto que mexe na variável à distância.

3. Somando dois números com ponteiros
Como pensei:
A função soma recebe três ponteiros. Dentro dela, desreferencio os dois primeiros (*a, *b) para pegar os valores, somo e guardo no endereço apontado por resultado. Na main, passo os endereços das variáveis com &. Pronto, a função faz o trabalho e o resultado aparece onde eu quiser.

4. Trocando valores de duas variáveis
O que pensei:
Trocar valores sem ponteiros seria fácil, mas o exercício queria a versão “ponteiro”. Usei uma variável temporária para guardar *a, depois copiei *b para *a, e finalmente coloquei o valor temporário em *b. Assim, o conteúdo de a e b trocam de lugar. É como trocar duas cartas usando uma terceira como apoio.

5. Descobrindo o maior entre dois números
O que pensei:
Simples: comparo *a e *b com um operador ternário e retorno o maior. Direto e sem firulas.

6. Percorrendo um vetor com aritmética de ponteiros
O que pensei:
O vetor v tem seus elementos na memória um ao lado do outro. Fiz p apontar para o primeiro (p = v). Depois, no laço, usei *(p + i) para acessar cada posição. Isso é a aritmética de ponteiros: somar i ao ponteiro me leva ao i-ésimo elemento.

7. Somando todos os elementos de um vetor
Como pensei:
A função recebe um ponteiro para o vetor e o tamanho. Percorro com *(v + i) e vou acumulando. No final, retorno a soma. Simples e eficiente.

8. Encontrando o maior elemento de um vetor
Como pensei:
Começo dizendo que o maior é o primeiro (*v). Depois percorro o resto, e se encontrar alguém maior, atualizo a variável. No fim, retorno o maior.

9. Ponteiro para ponteiro: dois níveis de indireção
O que pensei:
Criei x, p apontando para x e pp apontando para p. Então *p me dá x, e **pp me dá x também. É como se pp fosse um endereço que guarda outro endereço, que por fim leva ao valor. Mostra que podemos ter vários níveis de referência.

10. Invertendo um vetor com ponteiros
O que pensei:
Coloquei um ponteiro no início (inicio) e outro no fim (fim = v + n - 1). Enquanto inicio estiver antes de fim, troco os valores apontados por eles. Depois avanço o início e recuo o fim. Quando eles se cruzam, o vetor está invertido.

11. Desafio: alocação dinâmica e média
Como pensei:
Pedi o tamanho n, aloquei espaço com malloc. Verifiquei se deu certo (sempre bom!). Li os valores usando aritmética de ponteiros (vetor + i), somei tudo, calculei a média e mostrei. No final, liberei a memória com free. Alocar e liberar é tão importante quanto usar!

📦 Bloco 2 – Vetores e Matrizes com Alocação Dinâmica
1. Vetor dinâmico – imprimindo ao contrário
O que pensei:
Aloquei o vetor com malloc, li os valores e, para exibir invertido, percorri de trás para frente. Depois liberei a memória. Fácil!

2. Matriz dinâmica e sua transposta
Como pensei:
Alocar uma matriz dinâmica é um pouco mais chatinho: primeiro aloco um vetor de ponteiros (as linhas), depois para cada linha aloco outro vetor (as colunas). Para exibir a transposta, troquei a ordem dos laços: percorro colunas por fora e linhas por dentro. Assim mostro a matriz “de lado” sem criar uma segunda matriz.

3. Matriz quadrada com números aleatórios
O que pensei:
Mesma alocação da matriz, mas no preenchimento usei rand() % 100 + 1 para números de 1 a 100. Com srand(time(NULL)) garanti que a sequência fosse diferente a cada execução. Depois exibi e liberei tudo.

4. Armazenando nomes e idades
O que pensei:
Aqui precisei de duas estruturas: um vetor de ponteiros para as strings (nomes) e um vetor de inteiros (idades). Para cada pessoa, aloquei espaço para o nome com malloc e li com fgets (para pegar nomes com espaços). As idades li com scanf. No final, liberei cada string, depois os vetores. Cuidado com o \n que fica no buffer – usei getchar() para limpar.

🧩 Exercício Extra – Matriz 5×5 com índices
Como pensei:
Aloquei uma matriz 5×5 dinâmica. Preenchi cada posição com i*5 + j. Isso dá números de 0 a 24, que representam a ordem linear dos elementos. Imprimi bonitinho e liberei a memória. Simples e direto.
