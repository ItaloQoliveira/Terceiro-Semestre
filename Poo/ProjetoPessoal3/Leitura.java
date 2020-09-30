//Aluno: Italo Queiroz de Oliveira
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Leitura {
    public  String entDados(String texto){
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