package classes;

public class Quadrado implements FiguraGeometrica
{
        // Atributos
        private int lado;

        // Construtor
        public Quadrado(int lado)
        {
            this.lado = lado;
        }
        
        // Métodos de Interface
        @Override
        public double calcularArea()
        {
            return  Math.pow(lado, 2);
        }   
}

