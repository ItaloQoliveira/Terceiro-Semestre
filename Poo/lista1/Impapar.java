//Nome: Italo Queiroz de Oliveira - RA:2144042
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader; 

public class Impapar {
    public static void main(String arg[]){
        int a=entrada("Entre com um valor: ");
        if(a==0){
            System.out.println("O valor é zero");
        }else if(a%2==0){
            System.out.println("O valor inserido é par");
        }else{
            System.out.println("O valor inserido é impar");
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