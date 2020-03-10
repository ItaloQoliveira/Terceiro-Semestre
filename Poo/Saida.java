import java.util.Scanner;
public class Saida{
    public static void main(final String arg[]) {
        int a=255;
        int b=110;
        int c=a+b;
        Scanner inp = new Scanner(System.in);
        System.out.println("Digite a quantidade de anos que vc odeia sua vida: ");
        int anos = inp.nextInt();
        System.out.println("Você não está sendo honesto, entre outro numero : ");
        int outroanos=inp.nextInt();
        System.out.println("Eu odeio a minha vida "+c+" dias por ano a "+(outroanos+anos)+" anos");
        float afalso= Float.parseFloat(arg[0]);
        float bfalso= Float.parseFloat(arg[1]);
        float cfalso= Float.parseFloat(arg[2]);
        float soma= (afalso+bfalso)/cfalso;
        System.out.println("A soma de (a+b)/c é: "+soma);

    }
    public static void doente(){
        for(int i=0;i<27;i++){
        System.out.println("Doente");
        }
    }
}