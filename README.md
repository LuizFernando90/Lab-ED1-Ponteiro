📚 Minha Jornada com Ponteiros, Alocação Dinâmica, Vetores e Matrizes e Struct e Vetores de Structs em C

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

Exercício 1 – Controle de Funcionários
A ideia aqui é simples: guardar dados de funcionários (nome, salário, identificador e cargo) numa estrutura própria, e depois fazer algumas operações básicas.

a) Preencher os dados de um funcionário
Como que a função faz:
Ela recebe o endereço (o ponteiro) de uma estrutura Funcionario e pede para o usuário digitar cada campo. Usei fgets para ler o nome e o cargo porque eles podem ter espaços (ex: "João Silva", "Analista de Sistemas"). O scanf normal para o salário e o identificador. Como o parâmetro é um ponteiro, qualquer alteração dentro da função reflete direto na estrutura original – não precisa retornar nada.

Por que assim?
Se passássemos a estrutura por cópia, a função não conseguiria modificar os valores originais. Usando ponteiro, economizamos memória e garantimos que os dados realmente sejam salvos.

b) Imprimir os dados de um funcionário
Como a função faz:
Recebe o ponteiro (mas agora como const, ou seja, só leitura) e mostra cada campo na tela com uma formatação bonitinha. Usei const para garantir que a impressão não vai alterar nada por engano.

c) Alterar o salário
Como a função faz:
É a mais simples de todas: recebe o ponteiro do funcionário e o novo salário (por parâmetro) e só faz func->salario = novoSalario. Também daria para pedir o novo valor dentro da função, mas achei mais flexível receber como argumento – assim posso usar a função tanto para um reajuste fixo quanto para um valor digitado.

d) Funcionário com maior e menor salário
O que a função faz:
Ela recebe um vetor de funcionários e o tamanho desse vetor. A lógica é clássica:

Começo supondo que o primeiro funcionário é o que tem maior salário e também o de menor salário.

Percorro todo o vetor comparando os salários: se achar um maior que o atual, atualizo o índice do maior; se achar um menor, atualizo o índice do menor.

No final, imprimo o cargo e o salário de cada um (apenas os extremos).

Cuidado que tomei:
Se o vetor estiver vazio (n <= 0), a função simplesmente não faz nada para evitar erros.

Exercício 2 – Cadastro de Pessoas
É bem parecido com o de funcionários, mas agora os campos são nome, número do documento e idade. As operações são análogas, com a diferença que aqui atualizamos a idade e buscamos a pessoa mais velha e a mais nova.

a) Preencher uma pessoa
Como a função faz:
Mesma ideia do funcionário: pede nome (com fgets para aceitar espaços), número do documento e idade. Uso ponteiro para modificar a estrutura original.

b) Imprimir uma pessoa
Como que a função faz:
Exibe os campos de forma organizada. Também uso const para segurança.

c) Atualizar a idade
O que a função faz:
Recebe a estrutura da pessoa e a nova idade, e atualiza o campo idade. Poderia ser um scanf dentro da função, mas optei por receber o valor já pronto para a função ser mais versátil.

d) Pessoa mais velha e mais nova
O que a função faz:
Percorre o vetor de pessoas comparando as idades. Começo com a primeira pessoa como referência de mais velha e mais nova, e vou trocando os índices sempre que encontro alguém mais velho ou mais novo. No final, mostro o nome da pessoa mais velha e o nome da mais nova.

Detalhe: Se houver empate (duas pessoas com a mesma idade máxima), a função mostra a primeira que apareceu. Não tem problema, porque o enunciado não pediu critério de desempate.

Exercício 3 – Gerenciamento de Turmas (com alocação dinâmica)
Esse é mais caprichado. A ideia é controlar várias turmas, cada uma com até 3 alunos (definido pela constante MAX_VAGAS). Os alunos são alocados dinamicamente, assim como as turmas. O programa tem um menu interativo parecido com o exemplo que foi dado.

a) Criar uma turma
Como a função faz:

Primeiro, verifica se já não existe uma turma com o mesmo identificador (letra A, B, etc.). Se existir, avisa e retorna NULL.

Depois, aloca memória para uma nova estrutura Turma com malloc.

Inicializa o campo vagas com MAX_VAGAS (por exemplo, 3) e o id com a letra digitada.

Por fim, coloca NULL em todas as posições do vetor alunos – isso é importante para saber quais posições estão livres depois.

Retorna o ponteiro para a turma criada.

Por que usar NULL?
Mais tarde, quando formos matricular, vamos procurar a primeira posição com NULL para colocar o novo aluno. É um jeito simples de controlar vagas.

b) Matricular um aluno
Como que a função faz:

Recebe a turma, a matrícula e o nome do aluno.

Verifica se ainda há vagas (turma->vagas > 0).

Procura a primeira posição do vetor alunos que esteja com NULL.

Aloca um novo Aluno com malloc, preenche os dados (matrícula, nome, e as três notas com zero).

Coloca o ponteiro desse novo aluno na posição encontrada.

Diminui o contador de vagas da turma.

Observação importante:
As notas começam zeradas, exatamente como o enunciado pede. Só depois o professor vai lançar as notas de verdade.

c) Lançar notas e calcular média
O que a função faz:

Descobre quantos alunos estão matriculados (MAX_VAGAS - turma->vagas).

Percorre o vetor alunos e, para cada aluno que não for NULL, pede as três notas (usando scanf).

Imediatamente calcula a média (soma das três dividido por 3) e guarda no campo media do aluno.

Por que calcular na hora?
Porque depois, quando listarmos os alunos, já teremos a média pronta para mostrar.

d) Imprimir os dados dos alunos de uma turma
Como a função faz:
Percorre o vetor alunos da turma e, para cada posição que não for NULL, mostra matrícula, nome e média. Se a turma não tiver alunos, avisa.

e) Imprimir todas as turmas
O que a função faz:
Recebe o vetor global turmas (um vetor de ponteiros) e a quantidade de turmas criadas (n). Para cada turma, exibe o identificador e quantas vagas ainda estão disponíveis. Se não houver nenhuma turma, avisa o usuário.

f) Procurar uma turma pelo identificador
Como que a função faz:
Recebe o vetor de turmas, a quantidade e um caractere id. Percorre o vetor comparando turmas[i]->id com o id procurado. Se achar, retorna o ponteiro da turma; se não achar, retorna NULL. Essa função é muito usada no menu para localizar a turma antes de matricular, lançar notas ou listar alunos.

g) O menu principal
Como que o menu faz:
Fica num loop do-while que só termina quando o usuário escolhe a opção 6 (Sair). Dentro do loop, mostra as opções, lê a escolha e, com um switch, chama a função correspondente.

Opção 1: cria uma nova turma (verifica se ainda não atingiu MAX_TURMAS).

Opção 2: lista todas as turmas.

Opção 3: matricula um aluno (pede o id da turma, localiza com procura_turma, depois pede matrícula e nome).

Opção 4: lança notas (procura a turma e chama lanca_notas).

Opção 5: lista alunos de uma turma (procura a turma e chama imprime_alunos).

Opção 6: sai do programa e libera toda a memória alocada (cada aluno e cada turma) para não deixar vazamentos.

Cuidados extras que tomei:

Depois de cada scanf eu coloquei um getchar() para consumir a quebra de linha, senão o fgets do nome podia pular.

Usei fgets(nome, 81, stdin) para ler o nome completo (com espaços) e depois removi o \n do final com strcspn.

🧩 Exercício Extra – Matriz 5×5 com índices
Como pensei:
Aloquei uma matriz 5×5 dinâmica. Preenchi cada posição com i*5 + j. Isso dá números de 0 a 24, que representam a ordem linear dos elementos. Imprimi e liberei a memória. Simples e direto.
