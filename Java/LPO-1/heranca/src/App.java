import animais.*;

public class App 
{
    public static void main(String[] args) throws Exception {
        
        Cachorro cachorro = new Cachorro("Caramelo");

        cachorro.comer();
        cachorro.latir();

        Gato gato = new Gato("Snowbell");

        gato.bebeu();
        gato.miou();

        Dragao dragao = new Dragao("Dragão branco de olhos azuis");

        dragao.voar();
        dragao.soltar_fogo();

        Pombo pombo = new Pombo("Pombo correio");

        pombo.voar();
        pombo.enviarCarta();
        pombo.enviarCarta();
        pombo.enviarCarta();
    }
}
