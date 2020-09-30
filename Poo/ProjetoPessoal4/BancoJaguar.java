//Nome: Italo Queiroz de Oliveira- RA:2144042
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class BancoJaguar {
    private static List<Jaguar> BDJaguar = new ArrayList<Jaguar>();
    private static Jaguar jaguar = new Jaguar();
    private static Leitura l = new Leitura();
    public void impAllJaguar(){
        for(int i=0;i<BDJaguar.size();i++){
            if(BDJaguar.get(i)!= null){
                impJaguar(BDJaguar.get(i));
            }else{
                System.out.println("\n Não tem mais jaguares para serem impressos!");
            }
                
        }
    }
    public void impJaguar(Jaguar jag){
        System.out.println("\n  Nome: "+jag.getNome()+" Cor: "+jag.getCor());

    }
    public void cadJaguar(Jaguar jag){
        System.out.println("\n=========Cadastro===========");
        try{
            jag.setCor(l.entDados("Insira a cor"));
            jag.setNome(l.entDados("Insira o nome: "));
            //jag.setCodJag(Integer.parseInt(l.entDados("Insira o codigo")));   
        }catch(CorException ce){
            ce.impFelinoVerde();
        }catch(NumberFormatException nf){
            System.out.println("\nErro");
        }
        if(BDJaguar.add(jag)){
            System.out.println("\nCadastro efetuado com sucesso");
        }else{
            System.out.println("\nOcorreu um erro no cadastro, tente novamente");
        }
    }
}
