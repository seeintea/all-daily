//
//  ViewController.swift
//  imageExport
//
//  Created by LiweiGu on 2020/3/9.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var fileName: UILabel!
    
    @IBOutlet weak var imgAlpha: UILabel!
    
    @IBOutlet weak var adjustImage: UIImageView!
    
    @IBOutlet weak var autoImage: UIImageView!
    
    // 自动动画
    func autoAnimation(name:String, count:Int) {
        // 新建可变数组并初始化
        var images:NSMutableArray?;
        images = NSMutableArray.init();
        
        var index=0;
        while(index<count){
            // 拼接文件名
            let filename = String(format: "%@%d.png", name, index);
            index += 1;
            // 将文件读入内存
            let image = UIImage(named: filename);
            // 将文件放入数组中
            images?.add(image as Any);
        }
        // 设置关联数组、播放次数
        self.autoImage.animationImages = (images as! [UIImage]);
        self.autoImage.animationRepeatCount = 0;
        autoImage.animationDuration = 3;
        self.autoImage.startAnimating();
    }
    
    var index = 1;
    
    @IBAction func prev(_ sender: UIBarButtonItem) {
        index -= 1;
        if index == 0 {
            index = 9;
        }
        let fileName = String(format: "p%d.jpg", index);
        self.fileName.text = fileName;
        self.adjustImage.image = UIImage(named: fileName);
    }
    
    @IBAction func next(_ sender: UIBarButtonItem) {
        index += 1;
        if index == 10 {
            index = 1;
        }
        let fileName = String(format: "p%d.jpg", index);
        self.fileName.text = fileName;
        self.adjustImage.image = UIImage(named: fileName);
    }
    
    @IBAction func adjustAlpha(_ sender: UISlider) {
        let value = sender.value;
        self.adjustImage.alpha = CGFloat(value);
        self.imgAlpha.text = String(format: "%0.2f", (CGFloat(value)));
    }
    
    @IBAction func AlphaChange(_ sender: UISegmentedControl) {
        let index = sender.selectedSegmentIndex;
        self.imgAlpha.text = String(format: "%0.2f", (Double(index)*2/10));
        switch index {
        case 0:
            self.adjustImage.alpha = CGFloat(0);
            break;
        case 1:
            self.adjustImage.alpha = CGFloat(0.2);
            break;
        case 2:
            self.adjustImage.alpha = CGFloat(0.4);
            break;
        case 3:
            self.adjustImage.alpha = CGFloat(0.6);
            break;
        case 4:
            self.adjustImage.alpha = CGFloat(0.8);
            break;
        case 5:
            self.adjustImage.alpha = CGFloat(1.0);
            break;
        default:
            break;
        }
    }
    
    @IBAction func autoImageSwitch(_ sender: UISwitch) {
        if sender.isOn == true {
            autoAnimation(name: "10", count: 11);
        }else {
            autoImage.stopAnimating();
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        self.autoAnimation(name: "10", count: 11);
    }


}

