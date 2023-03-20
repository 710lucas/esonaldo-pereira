import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Scanner;

import javax.lang.model.element.VariableElement;

public class Esonaldo{

    private ArrayList<String> linhas = new ArrayList<String>();
    private ArrayList<Variavel> variaveis = new ArrayList<Variavel>();
    private int pc = 0;

    public boolean readFile(String filename){
        File file = new File(filename);
        try (Scanner fileScan = new Scanner(file)) {

            while(fileScan.hasNext()){
                String linha = fileScan.nextLine();
                linha  = removeSpaces(linha);
                if(!linha.isEmpty())
                    linhas.add(linha);
            }

            fileScan.close();

        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            return false;
        }

        return true;
    }

    public ArrayList<String> getLinhas(){
        return linhas;
    }

    public ArrayList<String> separaPalavras(String linha){
        ArrayList<String> out = new ArrayList<String>();

        String tmpString = "";

        for(int i = 0; i<linha.length(); i++){
            if(linha.charAt(i) == ' '){
                out.add(tmpString);
                tmpString = "";
            } 
            else if(i == linha.length()-1){
                tmpString+=linha.charAt(i);
                out.add(tmpString);
            }
            else{
                tmpString+=linha.charAt(i);
            }
        }

        return out;
    }

    public void novaVariavel(String nomeVariavel){
        Variavel var = new Variavel(nomeVariavel);
        variaveis.add(var);
    }

    public ArrayList<Variavel> getVariaveis(){
        return variaveis;
    }

    //Cria variavel caso não exista
    public Variavel getVariavelByName(String nome){
        nome = nome.replace("?", "");
        nome = nome.replace(",", "");
        for(int i  = 0; i<variaveis.size(); i++){
            if(variaveis.get(i).getNome().equals(nome)){
                return variaveis.get(i);
            }
        }
        this.novaVariavel(nome);
        return getVariavelByName(nome);
    }

    public boolean variavelExiste(String nome){
        for(int i = 0; i<variaveis.size(); i++){
            if(variaveis.get(i).getNome().equals(nome))
                return true;
        }
        return false;
    }

    public int getPC(){return pc;}
    public void setPC(int programCounter){pc = programCounter;}


    //tira os espaços iniciais de uma linha
    //util para poder se utilizar tab
    static String removeSpaces(String linha){

        String out = "";
        boolean started = false;
        for(int i = 0; i<linha.length(); i++){
            if(Character.isLetter(linha.charAt(i))){
                started = true;
            }
            if(started)
                out+=linha.charAt(i);
        }

        return out;
    }





}