import java.util.Scanner;

public class HappyNumber {
    public static int sumOfSquaresOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    public static boolean isGoodNumber(int n) {
        int slow = n, fast = n;

        do {
            slow = sumOfSquaresOfDigits(slow);
            fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));

            if (fast == 1)
                return true;

        } while (slow != fast);

        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = scanner.nextInt();
        scanner.close();

        System.out.println(isGoodNumber(n));
    }
}
