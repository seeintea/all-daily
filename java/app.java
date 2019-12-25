import java.util.Scanner;

public class app {

    public static void main(String[] args) {
        /**
         * report 1
         * */
        System.out.println("********* Welcome Shopping System *********");
        boolean pwdErrFlag = true;
        int pwdErrCount = 0;
        boolean loginFlag = false;
        String userName = "pcj", userPwd = "123456";
        String inputName = " ", inputPwd = " ";
        Scanner scanner;
        while (pwdErrFlag) {
            System.out.print("please input userName: ");
            scanner = new Scanner(System.in);
            if (scanner.hasNext()) {
                inputName = scanner.next();
            }
            System.out.print("please input userPassword: ");
            scanner = new Scanner(System.in);
            if (scanner.hasNext()) {
                inputPwd = scanner.next();
            }
            if((inputName.equals(userName)) && (inputPwd.equals(userPwd))){
                loginFlag = true;
                scanner.close();
                break;
            } else {
                if(pwdErrCount++ > 1) {
                    pwdErrFlag = false;
                    scanner.close();
                }
                System.out.println("userPwd err ! has "+(3-pwdErrCount)+" chance! ");
            }
        }
        if(loginFlag){
            System.out.println("Welcome "+userName+" Login Shopping System !");
        }
    }
}
