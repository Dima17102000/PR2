public class HelloWorld {
    
    static int foo() {return 55;}

    static void bar(int x) {x += 1;}

    static void bar2(int[] arr) {arr[10] = 666;}
    
    public static void main(String[] args) {
        int x = 5;
        System.out.println(x);
        bar(x);
        System.out.println(x);

        int[] arr = new int[100];
        System.out.println(arr[10]);
        bar2(arr);
        System.out.println(arr[10]);

    }
}