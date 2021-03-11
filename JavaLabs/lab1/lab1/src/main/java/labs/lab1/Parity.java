package labs.lab1;

public class Parity {
    private int num;
    private int result;
    public Parity(int num){
        this.num=num;
        this.result=num%2;
    }
    public String getParity(){
        if(result==1){
            return "Нечетное";
        }
        else return "Четное";
    }
    public String getPrimeNumber(){
        for (int i = 2; i<=Math.sqrt(num); i++)
            if (num % i == 0)
                return "Число не простое";
        return "Простое";
    }
}
