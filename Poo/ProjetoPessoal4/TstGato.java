//Aluno: Italo Queiroz de Oliveira
public class TstGato {
    public static void main(String arg[]){
        boolean flag =true;
        int op;
        Jaguar jaguar = new Jaguar();
        Leitura l = new Leitura();
        BancoJaguar BDJag= new BancoJaguar();
        while(flag){ //utilizarei apenas cor e nome para ficar mais simples
            System.out.println("\n MENU");
            System.out.println("\n Insira 1 para cadastro ");
            System.out.println("\n Insira 2 para imprimir todos ");
            System.out.println("\n Insira 3 para finalizar apicaçao");


        
            try{
                op=Integer.parseInt(l.entDados("\n opçao: "));
            }catch(NumberFormatException nf){
                System.out.println("Deve ser um valor inteiro");
                continue;
            }
            switch(op){
                case 1:
                    jaguar = new Jaguar();
                    BDJag.cadJaguar(jaguar);
                    break;
                case 2:
                    BDJag.impAllJaguar();
                    break;
                case 3:
                    flag = false;
                    break;
                default:
                    System.out.println("Apenas de 1 a 3");
                    break;
            }
        }
    }
}