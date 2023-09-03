# Esonaldo Pereira

-----

## Sobre

Esonaldo Pereira é uma [Esoteric language](https://esolangs.org/wiki/Esoteric_programming_language) na qual o código fonte foi feito para ser parecido com musicas do Mestre.

## About

Esonaldo Pereira is an [Esoteric language](https://esolangs.org/wiki/Esoteric_programming_language) which the code was made to look like musics from the brazilian singer Ednaldo Pereira





## Como compilar | How to compile

Execute os seguintes comandos

Run the following commands

```bash
git clone https://github.com/luxs710/esonaldo-pereira
cd esonaldo-pereira
make
make run
```


## Como usar

Clique em [releases](https://github.com/Luxs710/esonaldo-pereira/releases/) e baixe a versão mais recente

após isso, crie um arquivo na pasta que contem o arquivo baixado e crie o codigo em esonaldo, depois, abra um terminal nessa pasta e execute `java -jar Esonaldo.jar` e informe o nome do arquivo

OBS.: o nome do arquivo pode ser passado como argumento do comando java -jar

Você vai precisar ter o java instalado

Veja o video abaixo

https://user-images.githubusercontent.com/65160454/222925647-64e4547c-5a0e-4749-9331-91a81cc8316c.mp4


## How to use

Go to the [releases](https://github.com/Luxs710/esonaldo-pereira/releases/) page and download the most recent version

next, create a file in the folder that you've downloaded the .jar file and start coding in esonaldo, after you're done coding, open a terminal in the folder where's located the .jar and esonaldo file and run the `java -jar Esonaldo.jar` command and type the path/file name of your file

You can pass the file name/path as an argument of the java -jar command

You'll need to have java installed

See the video above

-----

## Como contribuir

Para contribuir, basta procurar uma função que seria interessante adicionar na linguagem de programação e procurar em alguma música/vídeo o ednaldo pereira falando algo que possa ser usado para nomear a função, em seguida você pode criar um issue ou contribuir diretamente e fazendo um push request

Para ter um acesso mais fácil às letras do ednaldo pereira, eu criei um script simples para ajudar a recupera-las do site (letras.mus.br)[https://letras.mus.br/ednaldo-pereira], basta acessar o link informado (que corresponde à página do ednaldo pereira), abrir o menu de inspecionar do navegador e rodar o seguinte código:

```js
letras = ""
musicas = document.getElementsByClassName("songList-table-songName") 

for(var i = 0; i < musicas.length; i++){

 fetch(musicas[i].href)
	.then(response => {
		return response.text()
	})
	.then(texto => {
		var div = document.createElement('html')
		div.innerHTML = texto
		console.log(div)
		console.log(div.getElementsByClassName("lyric-original")[0].innerText)
		letras+=div.getElementsByClassName("lyric-original")[0].innerText
	})
}
```

Após isso, as letras ficarão salvas na váriavel letras, como uma string, permitindo que a busca por alguma fale fique mais fácil

-----

## Documentation / Documentação

Por enquanto a documentação se enconta na [wiki](https://github.com/Luxs710/esonaldo-pereira/wiki)

For now, the documentation is in the [wiki](https://github.com/Luxs710/esonaldo-pereira/wiki)
