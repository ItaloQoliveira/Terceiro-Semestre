//Aluno: Italo Queiroz de Oliveira
public class TstGato {
    public static void main(String arg[]){
        Leitura leitor= new Leitura();
        Gato gato = new Gato();
        gato.setCor(leitor.entDados("Insira a cor do gato"));
        gato.setNome(leitor.entDados("Insira o nome do gato"));
        gato.getMedida().setAltura(Integer.parseInt(leitor.entDados("Insira a altura do gato em cm")));
        gato.getMedida().setComprimento(Integer.parseInt(leitor.entDados("Insira o comprimento do gato em cm")));
        gato.getMedida().setPeso(Float.parseFloat(leitor.entDados("Insira o peso do gato em kg")));
        
        System.out.println("Nome do gato: "+gato.getNome());
        System.out.println("Cor do gato: "+gato.getCor());
        System.out.println("Altura do gato: "+gato.getMedida().getAltura()+"cm");
        System.out.println("Peso do gato: "+gato.getMedida().getPeso()+"kg");
        System.out.println("Comprimento do gato: "+gato.getMedida().getComprimento()+"cm");
    }
}