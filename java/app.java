import java.util.Scanner;

public class app {

    /**
     * report 2
     * */
    static String goodsList[][] = {
            {"商品编号","商品名称","商品数量","商品价格","商品类型"},
            {"100001","百事可乐","24","2.5","食品"},
            {"100002","得力笔记本","10","4","文具"},
            {"100003","卫龙辣条","50","3.5","食品"}
    };
    static String usersList[][] = {
            {"pcj","123456","200"},
            {"cm","654321","25"},
            {"cyz","202020","300"}
    };

    public static void printAllGoods(){
        for(int i=0; i< goodsList.length; i++){
            for(int j=0; j<goodsList[i].length; j++){
                System.out.print(String.format("%-10s", goodsList[i][j]));
            }
            System.out.println();
        }
    }

    public static void searchGoods(String str){
        for(int j=0; j<goodsList[0].length; j++){
            System.out.print(String.format("%-10s", goodsList[0][j]));
        }
        System.out.println();
        int x = 0;
        for(int i=0; i< goodsList.length; i++) {
            x = goodsList[i][1].indexOf(str);
            if (x > 0){
                for(int k=0; k<goodsList[i].length; k++){
                    System.out.print(String.format("%-10s", goodsList[i][k]));
                }
                System.out.println();
                x = 0;
            }
        }
    }


    public static void main(String[] args) {

        /**
         * report 1
         * */
        /*System.out.println("********* Welcome Shopping System *********");
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
        }*/
        /**
         * report 1
         * */
    }
}
