import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Main{

    static Esonaldo esonaldo = new Esonaldo();
    static ArrayList<String> linhas = esonaldo.getLinhas();
    static ArrayList<String> linhasAtuais;
    static Scanner sc = new Scanner(System.in);

    public static void rodaLinhas(ArrayList<String> linhasPassadas){

        int pc = 0;//program counter

        linhasAtuais = linhasPassadas;
        while(pc < linhasPassadas.size()){
            String linhaAtual = linhasPassadas.get(pc);

            if(linhaAtual.contains("is the brother") && !getPalavraInLinha(pc, 1).equals("what")) {
                String nomeVariavel = getPalavraInLinha(pc, 0);
                esonaldo.getVariavelByName(nomeVariavel).setTipo(0);
            }
            else if(linhaAtual.contains("is the sister") && !getPalavraInLinha(pc, 1).equals("what")) {
                String nomeVariavel = getPalavraInLinha(pc, 0);
                esonaldo.getVariavelByName(nomeVariavel).setTipo(1);
            }
            else if(linhaAtual.contains("is good")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                Variavel tmpVar = esonaldo.getVariavelByName(nomeVariavel);
                System.out.println(esonaldo.getVariaveis().get(tmpVar.getPosicao()).getNome());
            }
            else if(linhaAtual.contains("vale nada")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                esonaldo.getVariavelByName(nomeVariavel).setNumerico(0);
            }
            else if(linhaAtual.contains("vale tudo")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                esonaldo.getVariavelByName(nomeVariavel).setNumerico(1);
            }
            else if(linhaAtual.contains("vale")){
                try{
                    double valor = Double.parseDouble(getPalavraInLinha(pc, 2));
                    String nomeVariavel = getPalavraInLinha(pc, 0);
                    esonaldo.getVariavelByName(nomeVariavel).setNumerico(valor);
                }
                catch(NumberFormatException n) {
                    System.out.println("Informe um valor numerico para a variavel") ;
                    System.err.println("Erro na linha "+(pc+1)+": "+linhaAtual);
                    System.exit(0);
                }
                catch(NullPointerException n){
                    System.out.println("Informe um valor numerico para a variavel") ;
                    System.err.println("Erro na linha "+(pc+1)+": "+linhaAtual);
                    System.exit(0);
                }
            }
            else if(linhaAtual.contains("vamos procurar viver em igualdade com")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 7);
                Variavel v1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel v2 = esonaldo.getVariavelByName(nomeVariavel2);
                v1.setNumerico(v2.getNumerico());
            }
            else if(getPalavraInLinha(pc, 1).equals("disse") || getPalavraInLinha(pc, 1).equals("disse:")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                String disse = getPalavraInLinha(pc, 1);
                esonaldo.getVariavelByName(nomeVariavel).setString(linhaAtual.replace(nomeVariavel+" "+disse+" ", ""));
            }
            else if(linhaAtual.contains("respondeu")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                Variavel var = esonaldo.getVariavelByName(nomeVariavel);
                if(var.getTipo() == 1)
                    System.out.print(var.getString().replace("\\n", "\n"));
                else
                    System.out.print(var.getNumerico());
            }
            else if(linhaAtual.contains("pergunta:") || linhaAtual.contains("pergunta")){
                String nomeVariavel = getPalavraInLinha(pc, 0);
                String pergunta = getPalavraInLinha(pc, 1);
                Variavel var = esonaldo.getVariavelByName(nomeVariavel);
                System.out.print(linhaAtual.replace(nomeVariavel+" "+pergunta+" ", ""));
                if(var.getTipo() == 0){
                    var.setNumerico(sc.nextDouble());
                }
                else{
                    var.setString(sc.nextLine());
                }
            }
            else if(linhaAtual.contains("é igual ao que") && getPalavraInLinha(pc, 1).equals("e")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 2);
                String nomeVariavel3 = getPalavraInLinha(pc, 7);
                Variavel var1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel var2 = esonaldo.getVariavelByName(nomeVariavel2);
                Variavel var3 = esonaldo.getVariavelByName(nomeVariavel3);
                var3.setNumerico(var1.getNumerico()+var2.getNumerico());
            }
            else if(linhaAtual.contains("qual é a diferença?") && getPalavraInLinha(pc, 1).equals("entre")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 2);
                String nomeVariavel3 = getPalavraInLinha(pc, 4);
                Variavel var1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel var2 = esonaldo.getVariavelByName(nomeVariavel2);
                Variavel var3 = esonaldo.getVariavelByName(nomeVariavel3);
                var1.setNumerico(var2.getNumerico()-var3.getNumerico());
            }
            else if(linhaAtual.contains("what is the brother")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 5);
                String nomeVariavel3 = getPalavraInLinha(pc, 7);
                Variavel var1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel var2 = esonaldo.getVariavelByName(nomeVariavel2);
                Variavel var3 = esonaldo.getVariavelByName(nomeVariavel3);
                if(var2.getNumerico()>var3.getNumerico()){
                    var1.setNumerico(1);
                    var1.setPosicao(esonaldo.getVariaveis().indexOf(var2));
                }
                else{
                    var1.setNumerico(0);
                    var1.setPosicao(esonaldo.getVariaveis().indexOf(var3));
                }
            }
            else if(linhaAtual.contains("what is the sister")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 5);
                String nomeVariavel3 = getPalavraInLinha(pc, 7);
                Variavel var1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel var2 = esonaldo.getVariavelByName(nomeVariavel2);
                Variavel var3 = esonaldo.getVariavelByName(nomeVariavel3);
                if(var2.getNumerico()<var3.getNumerico()){
                    var1.setNumerico(1);
                    var1.setPosicao(esonaldo.getVariaveis().indexOf(var2));
                }
                else{
                    var1.setNumerico(0);
                    var1.setPosicao(esonaldo.getVariaveis().indexOf(var3));
                }
            }
            else if(linhaAtual.contains("fale o que quiser com")){
                String nomeVariavel1 = getPalavraInLinha(pc, 0);
                String nomeVariavel2 = getPalavraInLinha(pc, 6);
                Variavel var1 = esonaldo.getVariavelByName(nomeVariavel1);
                Variavel var2 = esonaldo.getVariavelByName(nomeVariavel2);
                if(var1.getString().equals(var2.getString()))
                    var1.setNumerico(1);
                else
                    var1.setNumerico(0);
            }

            else if(linhaAtual.contains("você quer ser tudo")){
                String nomeVariavel = getPalavraInLinha(pc, 4);
                int fimDoIf = pc;
                for(int j = pc; j<linhas.size(); j++){
                    if(linhas.get(j).equals("e não é de nada")){
                        fimDoIf = j-1;
                        break;
                    }
                }

                if(esonaldo.getVariavelByName(nomeVariavel).getNumerico() != 1.0)
                    pc = fimDoIf;
            }

            else if(linhaAtual.contains("enquanto") && linhaAtual.contains("assim continuar")){
                String nomeVariavel = getPalavraInLinha(pc, 1);
                Variavel var = esonaldo.getVariavelByName(nomeVariavel);
                for(int j = pc; j>0; j--){
                    if(linhas.get(j).equals("eu não vou parar de mesclar") && var.getNumerico() == 1){
                        pc = j-1;
                        break;
                    }
                }
            }

            else if(linhaAtual.contains("hora de te chamar")){
                String nomeArquivo = getPalavraInLinha(pc, 4);
                Esonaldo tmpEsonaldo = new Esonaldo();
                tmpEsonaldo.readFile(nomeArquivo);
                rodaLinhas(tmpEsonaldo.getLinhas());
            }


            pc+=1;
        }

    }

    public static void main(String[] args){



        if(args.length < 1){
            args = new String[1];
            System.out.print("Digite o nome/caminho do arquivo para executar: ");
            args[0] = sc.nextLine();
        }

        //read file
        if(!esonaldo.readFile(args[0])){
            System.out.println("Erro ao ler arquivo");
            System.exit(0);
        }

        rodaLinhas(linhas);
        


        sc.close();
       //find subroutine positions 
    }

    static String getPalavraInLinha(int pc,int pos){
        String palavra="";
        try{
            ArrayList<String> palavras = esonaldo.separaPalavras(linhasAtuais.get(pc));
            try{
                palavra = palavras.get(pos);
            }
            catch(IndexOutOfBoundsException i){
                System.err.println("Erro ao pegar a palavra na posicao: "+(pc+1));
                System.err.println("Linha na qual a palavra deveria se encontrar: "+linhasAtuais.get(pc));
                System.exit(0);
            }
        }
        catch(IndexOutOfBoundsException i){
            System.err.println(linhasAtuais.get(pc-1));
            System.err.println("Erro ao pegar a linha na posicao: "+(pc+1));
            System.exit(0);
        }
    
        return palavra;
    }
}