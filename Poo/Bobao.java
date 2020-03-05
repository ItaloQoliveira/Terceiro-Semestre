import java.util.Scanner;
class Bobao{
    public static void main(String args[]){
        Scanner inp = new Scanner(System.in);
        System.out.println("Digite um número e os magos dirão se o mesmo é positivo :)");
        int num = inp.nextInt();
        if (num==0){
          System.out.println("Zero é zero, bobão!");
        } else if(num>0){
          System.out.println("O numero inserido é positivo:(");
        }else{
          System.out.println("O numero digitado é negativo :(");
        }


    }
}
