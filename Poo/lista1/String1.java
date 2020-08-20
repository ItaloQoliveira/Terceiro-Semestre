//Nome: Italo Queiroz de Oliveira - RA:2144042
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader; 

public class String1 {
    public static void main(String arg[]){
        String frase=entrada("Insira uma frase");
        frase=frase.toLowerCase();
        String proibido=entrada("Insira a letra para busca");
        proibido=proibido.toLowerCase();
        int i,cont=0;     
        for(i=0;i<frase.length();i++){
            if(frase.charAt(i) ==proibido.charAt(0)){
                cont++;
                System.out.println("Encontrada posição: "+i);
            }
        }
        if(cont>0){
            System.out.println("A letra "+proibido+" aparece na frase "+cont+" vezes");
        }else{
            System.out.println("Esta letra não existe na frase");
        }  
    }
    public static String entrada(String texto){
        InputStreamReader c= new InputStreamReader(System.in);
        BufferedReader cd=new BufferedReader(c);
        System.out.println(texto);
        String aux="";
        try{
            aux=cd.readLine();
        }catch(IOException e){
            System.out.println("Entrada invalida");
        }
        return aux;
    }    
}