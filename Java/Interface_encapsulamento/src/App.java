import classes.*;


public class App {
    public static void main(String[] args)
    {
        // Encapsulamento -> Interface
        Circulo circuloPequeno = new Circulo(2);
        Quadrado quadradoPequeno = new Quadrado(2);

        System.out.printf("Área circulo: %.2f\n", circuloPequeno.calcularArea());
        System.out.printf("Área quadrado: %.2f\n", quadradoPequeno.calcularArea());
        
        CalculadorArea calculator = new CalculadorArea();

        System.out.printf("Soma: %.2f\n", calculator.somarAreas(quadradoPequeno, circuloPequeno));

    }
}
