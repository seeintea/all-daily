//
//  ViewController.swift
//  rabbit
//
//  Created by LiweiGu on 2020/3/6.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    // 组件
    @IBOutlet weak var rabbitShow: UIImageView!
    
    @IBOutlet weak var rabbitText0: UILabel!
    
    @IBOutlet weak var rabbitText1: UILabel!
    
    @IBAction func rabbitSlider(_ sender: UISlider) {
        sender.isContinuous = false;
        self.rabbitShow.animationDuration = TimeInterval(5-Int(sender.value));
        self.rabbitShow.startAnimating();
        self.rabbitText0.text = String(format: "slider's value : %.2f", sender.value);
    }
    
    @IBAction func rabbitStepper(_ sender: UIStepper) {
        self.rabbitShow.animationDuration = TimeInterval(5-Int(sender.value));
        self.rabbitShow.startAnimating();
        self.rabbitText1.text = String(format: "stepper's value : %.2f", (sender.value));
    }
    
    @IBAction func rabbitSwitch(_ sender: UISwitch) {
        if sender.isOn == true {
            self.rabbitShow.startAnimating();
        } else {
            self.rabbitShow.stopAnimating();
        }
    }
    
    @IBAction func rabbitSegment(_ sender: UISegmentedControl) {
        self.rabbitShow.animationDuration = TimeInterval(sender.selectedSegmentIndex+1);
        self.rabbitShow.startAnimating();
    }
    
    // 封装方法
    func rabbitAnimate(count:Int, name:String) {
        // 新建可变数组并初始化
        var images:NSMutableArray?;
        images = NSMutableArray.init();
        
        var index=0;
        while(index<count){
            index += 1;
            // 拼接文件名
            let filename = String(format: "%@-%d.jpg", name, index);
            // 将文件读入内存
            let image = UIImage(named: filename);
            // 将文件放入数组中
            images?.add(image as Any);
            // 设置关联数组、播放次数
            self.rabbitShow.animationImages = (images as! [UIImage]);
            self.rabbitShow.animationRepeatCount = 0;
            rabbitShow.animationDuration = 5;
            self.rabbitShow.startAnimating();
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.rabbitAnimate(count: 20, name: "frame")
        // Do any additional setup after loading the view.
    }
}
