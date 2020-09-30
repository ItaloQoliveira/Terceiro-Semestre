//Nome: Italo Queiroz de Oliveira- RA:2144042
public class Gato {
    private String nome;
    private String cor;
    private Medida medida= new Medida();

    public void miau(){
        System.out.println("Meow!! :3");

    }
    public Medida getMedida() {
        return medida;
    }
    public void setMedida(Medida medida) {
        this.medida = medida;
    }
    public String getCor() {
        return cor;
    }
    public String getNome() {
        return nome;
    }
    public void setCor(String cor) throws CorException {
        if(cor.equalsIgnoreCase("verde")){
            throw new CorException();
            
        }else{
            this.cor = cor;
        }
        
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

}