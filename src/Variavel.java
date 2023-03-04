public class Variavel {

    private double valorNumerico;
    private String valorString;
    private int posicaoValorVariavel;
    private String nome;
    private int tipo = 0;  //0-int; 1-String

    public double getNumerico(){return valorNumerico;}
    public int getPosicao(){return posicaoValorVariavel;}
    public String getString(){return valorString;}
    public String getNome(){return nome;}
    public int getTipo(){return tipo;}

    public Variavel(String nome){
        this.nome = nome;
    }

    public void setTipo(int tipo){
        this.tipo = tipo;
    }

    public void setNumerico(double valor){
        this.valorNumerico = valor;
    }

    public void setString(String valor){
        this.valorString = valor;
    }

    public void setPosicao(int valor){
        this.posicaoValorVariavel = valor;
    }
    
}
