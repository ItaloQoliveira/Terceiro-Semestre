//Nome: Italo Queiroz de Oliveira - RA:2144042
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader; 

public class Calculadora {
    public static void main(String arg[]){
        int a=entrada("Entre com o primeiro valor:");
        int b=entrada("Entre com o segundo valor:");
        System.out.println("Opções:\n1-Somar\n2-Multiplicar\n3-subtrair\n4-dividir");
        int escolha=entrada("Escolha uma opção valida:");
        switch (escolha) {
            case 1:
                System.out.println("Resultado da soma: "+(a+b));
                break;
            case 2:
                System.out.println("Resultado da multiplicação: "+(a*b));
                break;
            case 3:
                System.out.println("Resultado da subração: "+(a-b));
                break;
            case 4:
                System.out.println("Resultado da divisão: "+(a/b));
                break;
            default:
                System.out.println("Opção invalida!");
                break;
        }
    }
    public static int entrada(String texto){
        InputStreamReader c= new InputStreamReader(System.in);
        BufferedReader cd=new BufferedReader(c);
        System.out.println(texto);
        String aux="";
        try{
            aux=cd.readLine();
        }catch(IOException e){
            System.out.println("Entrada invalida");
        }
        int retorno=Integer.parseInt(aux);
        return retorno;
    }    
}