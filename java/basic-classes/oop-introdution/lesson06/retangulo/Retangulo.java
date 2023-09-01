package lesson06.retangulo;

public class Retangulo {
    private double largura = 1;
    private double altura = 1;

    public Retangulo() {
    }

    public Retangulo(double largura, double altura) {
        this.largura = largura;
        this.altura = altura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double area() {
        return this.largura * this.altura;
    }
    public double perimetro() {
        return 2 * (this.largura + this.altura);
    }
    public double diagonal() {
        return Math.sqrt(this.largura * this.largura + this.altura * this.altura);
    }
}
