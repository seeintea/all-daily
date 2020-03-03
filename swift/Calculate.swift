//
//  ViewController.swift
//  calculate
//
//  Created by LiweiGu on 2020/3/3.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    // 计算器行为
    enum Action {
        case nul    // 空
        case dou    // 平方
        case sqr    // 开方
        case add    // 加
        case sub    // 减
        case mul    // 乘
        case div    // 除
    }
    
    // result 视图，显示运算结果
    @IBOutlet weak var result: UITextView!
    
    // 定义全局变量
    var numberShow:String = "0";
    // 记录符号位
    var action = Action.nul;
    // 中继值
    var midNum:Float64 = 0.0;
    
    // 定义方法
    // 复位方法
    func claerAllState(){
        numberShow = "0";
        action = Action.nul;
        midNum = 0;
    }

    // 字符串转数字
    func stringToFloat64(str:String)->Float64{
        var number:Float64 = 0.0;
        number = Float64(str)!;
        return number;
    }
    
    // 数字转字符串
    func floatToString(f:Float64)->String{
        let str:String = "\(f)";
        return str;
    }
    
    // 输入数字封装
    func numberFunc(str:String, need:String)->String{
        var string:String = "";
        if(str.elementsEqual("0")){
            string = "\(need)";
        }else{
            string = "\(str)\(need)";
        }
        return string;
    }
    
    // 整数去除小数位
    func floatToInteger(f:Float64)->Bool{
        let str = floatToString(f: f)
        let reg = "\\.0$";
        let Re = try? NSRegularExpression(pattern: reg, options: .caseInsensitive)
        let res = Re?.matches(in: str, range: NSRange(location: 0, length: str.count))
        let comp = (res?.count)!;
        if(comp>0){
            return true;
        }
        return false
    }
    
    // 添加小数点
    func addPoint(str:String)->Bool{
        let reg = "\\.";
        let Re = try? NSRegularExpression(pattern: reg, options: .caseInsensitive)
        let res = Re?.matches(in: str, range: NSRange(location: 0, length: str.count))
        let comp = (res?.count)!;
        if(comp>0){
            return true;
        }
        return false;
    }
    
    // 清空 result
    // 复原各类状态
    @IBAction func claer(_ sender: UIButton) {
        claerAllState();
        self.result.text = numberShow;
    }
    
    // 算数平方
    @IBAction func double(_ sender: UIButton) {
        action = Action.dou;
        midNum = stringToFloat64(str: numberShow);
        midNum = pow(midNum,2);
        if(floatToInteger(f: midNum)){
            let mid = Int(midNum);
            numberShow = "\(mid)";
        }else{
            numberShow = floatToString(f: midNum);
        }
        self.result.text = numberShow;
        action = Action.nul;
    }
    
    // 开平方根
    @IBAction func sqort(_ sender: UIButton) {
        action = Action.sqr;
        midNum = stringToFloat64(str: numberShow);
        midNum = sqrt(midNum);
        if(floatToInteger(f: midNum)){
            let mid = Int(midNum);
            numberShow = "\(mid)";
        }else{
            numberShow = floatToString(f: midNum);
        }
        self.result.text = numberShow;
        action = Action.nul;
    }
    
    // 加
    @IBAction func add(_ sender: UIButton) {
        action = Action.add;
        midNum = stringToFloat64(str: numberShow);
        numberShow = "0";
        self.result.text = numberShow;
    }
    
    // 减
    @IBAction func sub(_ sender: UIButton) {
        action = Action.sub;
        midNum = stringToFloat64(str: numberShow);
        numberShow = "0";
        self.result.text = numberShow;
    }
    
    // 乘
    @IBAction func mul(_ sender: UIButton) {
        action = Action.mul;
        midNum = stringToFloat64(str: numberShow);
        numberShow = "0";
        self.result.text = numberShow;
    }
    
    // 除
    @IBAction func div(_ sender: UIButton) {
        action = Action.div;
        midNum = stringToFloat64(str: numberShow);
        numberShow = "0";
        self.result.text = numberShow;
    }
    
    // 计算
    @IBAction func equal(_ sender: UIButton) {
        if(action == Action.nul){
            return;
        }
        let afterNumber = stringToFloat64(str: numberShow);
        // 加
        if(action == Action.add){
            midNum = midNum + afterNumber;
        }
        // 减
        if(action == Action.sub){
            midNum = midNum - afterNumber;
        }
        // 乘
        if(action == Action.mul){
            midNum = midNum * afterNumber;
        }
        // 除
        if(action == Action.div){
            midNum = midNum / afterNumber;
        }
        
        if(floatToInteger(f: midNum)){
            let mid = Int(midNum);
            numberShow = "\(mid)";
        }else{
            numberShow = floatToString(f: midNum);
        }
        // 复位
        action = Action.nul;
        self.result.text = numberShow;
    }
    
    // 数据录入事件
    @IBAction func zero(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "0");
        self.result.text = numberShow;
    }
    
    @IBAction func one(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "1");
        self.result.text = numberShow;
    }
    
    @IBAction func two(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "2");
        self.result.text = numberShow;
    }
    
    @IBAction func three(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "3");
        self.result.text = numberShow;
    }
    
    @IBAction func four(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "4");
        self.result.text = numberShow;
    }
    
    @IBAction func five(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "5");
        self.result.text = numberShow;
    }
    
    @IBAction func six(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "6");
        self.result.text = numberShow;
    }
    
    @IBAction func seven(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "7");
        self.result.text = numberShow;
    }
    
    @IBAction func eight(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "8");
        self.result.text = numberShow;
    }
    
    @IBAction func nine(_ sender: UIButton) {
        numberShow = numberFunc(str: numberShow, need: "9");
        self.result.text = numberShow;
    }
    
    @IBAction func ponit(_ sender: UIButton) {
        if(!addPoint(str: numberShow)){
            numberShow = "\(numberShow)."
            self.result.text = numberShow;
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
}
