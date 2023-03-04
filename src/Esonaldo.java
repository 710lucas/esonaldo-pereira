import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

import javax.lang.model.element.VariableElement;

public class Esonaldo{

    private ArrayList<String> linhas = new ArrayList<String>();
    private ArrayList<Variavel> variaveis = new ArrayList<Variavel>();

    public boolean readFile(String filename){
        File file = new File(filename);
        try (Scanner fileScan = new Scanner(file)) {

            while(fileScan.hasNextLine())
                linhas.add(fileScan.nextLine());
            

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



}