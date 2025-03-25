package classes;

public class CalculadorArea 
{
    public double somarAreas(FiguraGeometrica figuraA, FiguraGeometrica figuraB)
    {
        return figuraA.calcularArea() + figuraB.calcularArea();
    }   
}
