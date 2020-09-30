//Nome: Italo Queiroz de Oliveira- RA:2144042
public class Jaguar extends Gato {
    private int tamanhoPresa;
    private int codJag;
    public void roar(){
        System.out.println("Roar!! :3");

    }
    
    public int getTamanhoPresa() {
        return tamanhoPresa;
    }
  
    public void setTamanhoPresa(int tamanhoPresa) {
        this.tamanhoPresa = tamanhoPresa;
    }
    public int getCodJag() {
        return codJag;
    }
    public void setCodJag(int codJag) {
        this.codJag = codJag;
    }

}