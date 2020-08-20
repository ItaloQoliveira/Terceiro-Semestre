//Nome: Italo Queiroz de Oliveira - Ra: 2144042
public class Selec1 {
    public static void main(String arg[]){
        int a= Integer.parseInt(arg[0]); //lê os numeros pelo argumento da funcao java ....
        int b= Integer.parseInt(arg[1]);
        if(a>b){
            System.out.println("O primeiro valor é maior que o segundo");
        }else if(a<b){
            System.out.println("O primeiro valor é menor que o segundo");
        }else{
            System.out.println("O primeiro valor é igual ao segundo");
        }
        
    }
}