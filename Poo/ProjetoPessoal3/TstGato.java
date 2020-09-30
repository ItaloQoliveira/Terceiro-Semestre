//Aluno: Italo Queiroz de Oliveira
public class TstGato {
    public static void main(String arg[]){
        Leitura leitor= new Leitura();
        Gato gato = new Gato();
        try{
            gato.setCor(leitor.entDados("Insira a cor do gato")); 
        }catch(CorException ce){
            ce.impFelinoVerde();
        }
        
        System.out.println("Cor do gato: "+gato.getCor());
        
    }
}