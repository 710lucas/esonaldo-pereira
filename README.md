# Esonaldo Pereira

-----

## Sobre

Esonaldo Pereira é uma [Esoteric language](https://esolangs.org/wiki/Esoteric_programming_language) onde o código fonte foi feito para ser paecido com musicas do Mestre.


## Como usar

Basta acessar [esse repl.it](https://replit.com/@LucasPB710/Esonaldo?v=1) ou clonar o respositorio e escrever "make" (obs, requer Make e c++ instalados)

-----

## Comandos

Aqui alguns comandos serão explicados para facilitar o uso da linguagem

Exemplos de programas com explicações poderão ser encontrados no final

### Variaveis

Variaveis são nomes que podem armazenar valores numericos ou palavras

**OBS: Nomes não podem conter espaços**

- `<nome_da_variavel> is the brother` > cria uma variavel com o nome escolhido que usa valores numericos, se o nome ja tiver sido usado anteriormente, a variavel existente irá usar valores numéricos

- `<nome_da_variavel> is the sister` > cria uma variavel com o nome escolhido que armazena palavras, se o nome ja tiver sido usado anteriormente, a variavel existente irá armazenar palavras

- `<nome_da_variavel> vale nada` > define o valor numerico da variavel como 0

- `<nome_da_variavel> vale tudo` > define o valor numerico da variavel como 1

- `<var> vale <algum_numero>` > define o valor numerico da variavel como algum numero

- `<var> disse: <texto que pode conter espaços>` > armazena o texto na variavel especificada, para fazer um texto com multiplas linhas, use '\n' onde voce quiser que tenha uma linha nova

- `<var> pergunta: <frase que pode conter espaços>` > pede para que o usuario insira um valor para a variavel, a frase é opcional, podem ser palavras ou um valor numerico, isso será definido por `is the sister` ou `is the brother` (funciona como um input() em python)

- `<var> fale o que quiser com <var2>` Compara duas strings, caso as duas sejam iguais o valor numerico da primeira variavel fica atribuido a 1

### Operações com variaveis

- `<var1> vamos procurar viver em igualdade com <var2>` > faz com que o valor da primeira variavel seja igual ao da segunda

- `<var1> what is the brother <var2> ou <var3>` > vê qual variavel é maior entre var2 e var3 e armazena o resultado em var1, ou seja, se var2 > var3, o valor de var2 ficará em var1, que poderá mostrar quem é o maior com o comando `<var1> is good` (confuso dmais, eu sei, veja os exemplos no final)

- `<var> is good` > coloca na tela o valor da variavel armazenado dentro de var

- `<var> respondeu` > coloca o valor da variavel na tela, podem ser palavras ou um valor numero, isso será definido por `is the sister` ou `is the brother` (funciona como um print() em python)

- `<var> e <var2> é igual ao que, <var3>?` > soma a primeira variavel com a segunda e armazena o valor da soma na terceira variavel

### If

Por enquanto o If está bem confuso, então gambiarras devem ser utilizadas para q algo util consiga sair disso

```javascript
voce quer ser tudo <var>
<outros comandos>
e não é de nada
``` 

Executa os outros comandos caso a variavel seja igual a 1

------

### Exemplos

Cada comando será explicado separadamente

#### Texto simples

`Birina is the sister` > define a variavel Birina como algo que irá armazenar palavras

`Birina disse: Por acaso voce é chico ou é uma melancia?` > armazena a frase "por acaso voce é..." em Birina

`Birina respondeu` > coloca a frase "Por acaso voce é chico ou uma melancia?" na tela

#### Maior numero

`Chico is the brother` > define Chico como uma variavel que irá armazenar valores numericos

`Jorge is the brother` > mesma coisa de Chico

`Chico pergunta: Me diga um numero, por favor ` > Chico coloca a frase "Me diga um numero..." e espera ate que o usuario digite um numero e aperte enter

`Jorge pergunta: Me diga outro numero, por favor` > Mesma coisa do comando acima

`Birina, what is the brother Chico ou Jorge?` > Vê qual dos dois é maior e armazena o valor em Birina (obs: fica salvo na parte dos valores numericos, voce pode mudar o que está armazenado como palavra em Birina e o valor ainda estará intacto)

`Birina is good` > coloca o nome da variavel de maior valor na tela



## Coisas que o esonaldo ja tem:

respondeu -> print

disse -> str = "aaaa"

vale nada -> int = 0

vale tudo -> int  = 1

vale x -> int = x

is good -> Printa o **nome** de uma variavel que esta armazenada em outro
pergunta -> input

is the brother -> muda a variavel para seu tipo numerico

is the sister -> muda a variavel para seu tipo de string

x what is the brother y ou z -> vê qual numero é o maior entre y e z e armazena o **nome da maior variavel** em x, e muda o **valor numerico** para 1 caso seja verdadeiro

x who is the sister y ou z -> menor numero entre y e z e armazena **nome da variavel** em x, e muda o **valor numerico** para 1 caso seja verdadeiro

x vamos procurar viver em igualdade com y -> igualar o valor numero de x com y

x entre y e z qual é a diferença -> subtração, x = y-z

voce quer ser tudo -> inicio do if

e não é de nada -> fim do if

x e y é igual ao que, z? -> soma x com y e armazena em z

eu nao vou parar de mesclar -> inicio do while
enquanto x assim continuar -> continua o while enquanto x for 1

# Dicas

Para verificar se um numero é igual a outro, é possivel utilizar a subtração
