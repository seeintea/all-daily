import java.util.Scanner;

/**
 * report 2
 * */

public class app_test {

    /**
     *  util
     * */
    public static String scanUtil(){
        String str = "";
        Scanner scanner = new Scanner(System.in);
        if(scanner.hasNext()){
            str = scanner.next();
        }
        scanner.close();
        return str;
    }

    public static int stringToInt(String str) {
        return Integer.parseInt(str);
    }

    public static String intToString(int i){
        return Integer.toString(i);
    }

    public static float stringToFloat(String str){
        return Float.parseFloat(str);
    }

    public static String floatToString (float f){
        return Float.toString(f);
    }

    /**
     * func
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

    static String shopCar[][] = {
            {"0","0","0"},
            {"0","0","0"},
            {"0","0","0"}
    };

    static String userUIID =  "-1";

    public static boolean userLogin(String un, String up) {
        for (int i = 0; i < usersList.length; i++) {
            if ((un.equals(usersList[i][0])) && (up.equals(usersList[i][1]))) {
                userUIID = usersList[i][0];
                return true;
            }
        }
        return  false;
    }

    public static void printAllGoods(){
        System.out.println("******* Please Using Goods List ! *******");
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

    public static void addGoodsInShop(String goodsID, String goodsNum) {
        boolean checkFlag = true;
        int checkInfo = 4;
        for(int k = 0; k<goodsList.length; k++) {
            if((goodsList[k][0].equals(goodsID)) && (stringToInt(goodsList[k][2])>=stringToInt(goodsNum))){
                for(int i = 0; i<shopCar.length; i++){
                    if(shopCar[i][0].equals(goodsID)){
                        int x = stringToInt(shopCar[i][1]);
                        int y = stringToInt(goodsNum);
                        int z = stringToInt(goodsList[k][2]);
                        shopCar[i][1] = intToString((x+y));
                        shopCar[i][2] = goodsList[k][3];
                        goodsList[k][2] = intToString((z-y));
                        checkFlag = false;
                    }
                }
                if(checkFlag){
                    for(int j = 0; j<shopCar.length; j++){
                        if(shopCar[j][0].equals("0")){
                            shopCar[j][0] = goodsID;
                            shopCar[j][1] = goodsNum;
                            shopCar[j][2] = goodsList[k][3];
                            int y = stringToInt(goodsNum);
                            int z = stringToInt(goodsList[k][2]);
                            goodsList[k][2] = intToString((z-y));
                            j = shopCar.length + 1;
                        }
                    }
                }
            } else {
                checkInfo--;
            }
        }
        if(checkInfo == 0) {
            System.out.println("goodsID not in goodsList or goodNum not enough !");
        }
    }

    public static void checkUserBalance() {
        float total = 0, userBalance = 0;
        for(int i = 0; i<shopCar.length; i++){
            float f = stringToFloat(shopCar[i][2]);
            int x = stringToInt(shopCar[i][1]);
            total += x*f;
        }
        for(int j = 0; j<usersList.length; j++){
            if(usersList[j][0].equals(userUIID)){
                userBalance = stringToFloat(usersList[j][2]);
                if(userBalance > total){
                    usersList[j][2] = floatToString((userBalance-total));
                    System.out.println("消费成功，余额: "+ (userBalance-total));
                    for(int k = 0; k<shopCar.length; k++){
                        for(int z = 0; z<shopCar[k].length; z++){
                            shopCar[k][z] = "0";
                        }
                    }
                } else {
                System.out.println("余额不足，所需金额: " + total +" 目前余额: " + userBalance + " 请联系管理员充值 ！");
                }
            }
        }
    }


    public static void main(String[] args) {
        String un,up,sw;
        System.out.println("********* Welcome Shopping System *********");
        for(int i=0; i< 3; i++){
            System.out.print("please input userName: ");
            un = scanUtil();
            System.out.print("please input userPassword: ");
            up = scanUtil();
            if(userLogin(un,up)){
                System.out.println("**** Welcome " + userUIID + " Using Shopping System ****");
                printAllGoods();
                break;
            } else {
                if(i < 2 ) System.out.println("only "+ (2-i) +" chance !");
            }
        }

        while (!userUIID.equals("-1")){
            System.out.println("******* Please Change Shopping Operated ! *******");
            System.out.println("1. 搜索商品");
            System.out.println("2. 加入购物车 ");
            System.out.println("3. 结算");
            System.out.println("4. 退出系统");
            System.out.print("请输入操作符: ");
            sw = scanUtil();
            switch (sw){
                case "1":
                    String needGood = "";
                    System.out.print("请输入搜索关键字: ");
                    needGood = scanUtil();
                    searchGoods(needGood);
                    break;
                case "2":
                    String goodsID = "", goodNum = "";
                    System.out.print("请输入商品编号: ");
                    goodsID = scanUtil();
                    System.out.print("请输入所需数量: ");
                    goodNum = scanUtil();
                    addGoodsInShop(goodsID,goodNum);
                    break;
                case "3":
                    checkUserBalance();
                    break;
                case "4":
                    userUIID = "-1";
                    break;
                default:
                    System.out.println("please input legal var !");
                    break;
            }

        }

        System.out.println("System out !");
    }
}
