//
//  ViewController.swift
//  TomCat
//
//  Created by LiweiGu on 2020/3/2.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var tomImageView: UIImageView!
    
    func tomAnimate(count:Int, name:String) {
        // 新建可变数组并初始化
        var images:NSMutableArray?;
        images = NSMutableArray.init();
        
        var index=0;
        while(index<count){
            index += 1;
            // 拼接文件名
            let filename = String(format: "%@_%02d.jpg", name, index);
            // 将文件读入内存
            let image = UIImage(named: filename);
            // 将文件放入数组中
            images?.add(image as Any);
            // 设置关联数组、播放次数
            self.tomImageView.animationImages = (images as! [UIImage]);
            self.tomImageView.animationRepeatCount = 0;
            tomImageView.animationDuration = 5;
            self.tomImageView.startAnimating();
        }
    }
    
    @IBAction func cymbal(_ sender: UIButton) {
        self.tomAnimate(count: 12, name: "cymbal");
    }
    
    @IBAction func drink(_ sender: UIButton) {
        self.tomAnimate(count: 80, name: "drink");
    }
    
    @IBAction func eat(_ sender: UIButton) {
        self.tomAnimate(count: 39, name: "eat")
    }
    
    @IBAction func fart(_ sender: UIButton) {
        self.tomAnimate(count: 27, name: "fart")
    }
    
    @IBAction func pie(_ sender: UIButton) {
        self.tomAnimate(count: 23, name: "pie")
    }
    
    @IBAction func scratch(_ sender: UIButton) {
        self.tomAnimate(count: 55, name: "scratch")
    }
    
    @IBAction func knockout(_ sender: UIButton) {
        self.tomAnimate(count: 80, name: "knockout")
    }
    
    @IBAction func stomach(_ sender: UIButton) {
        self.tomAnimate(count: 33, name: "stomach")
    }
    
    @IBAction func footLeft(_ sender: UIButton) {
        self.tomAnimate(count: 29, name: "footLeft")
    }
    
    @IBAction func footRight(_ sender: UIButton) {
        self.tomAnimate(count: 29, name: "footRight")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

