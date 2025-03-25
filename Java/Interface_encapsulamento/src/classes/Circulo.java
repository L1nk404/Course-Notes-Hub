package classes;

public class Circulo implements FiguraGeometrica
{
        // Atributos
        private int raio;

        // Construtor
        public Circulo(int raio)
        {
            this.raio = raio;
        }

        // Métodos de Interfaces
        @Override
        public double calcularArea()
        {
            return Math.PI * Math.pow(raio, 2);
        }        
}
