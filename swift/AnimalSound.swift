//
//  ViewController.swift
//  AnimalSound
//
//  Created by LiweiGu on 2020/3/9.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    // 装载数据
    let animalSounds = NSArray.init(array: ["Oink", "Rawr", "Ssss", "Roof", "Meow","Honk","Squeak"]);
    let animalNames = NSArray.init(array: ["Mouse", "Goose", "Cat", "Dog", "Snake", "Bear", "Pig"]);
    let animalImages = NSArray.init(array: ["mouse", "goose", "cat", "dog", "snake", "bear", "pig"]);
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 2;
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return animalNames.count;
    }
    
    func pickerView(_ pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusing view: UIView?) -> UIView {
        // 动物图片列
        if component == 0 {
            let imageName = "\(animalImages[row])";
            let imageView = UIImageView(image: UIImage(named: imageName));
            return imageView;
        }
        // 文字列
        else {
            let soundLable = UILabel.init(frame: CGRect(x: 0,y: 0,width: 100,height: 40));
            soundLable.text = "\(animalSounds[row])";
            return soundLable;
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, rowHeightForComponent component: Int) -> CGFloat {
        return 70;
    }
    
    func pickerView(_ pickerView: UIPickerView, widthForComponent component: Int) -> CGFloat {
        if component == 0{
            return 100;
        } else {
            return 150;
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if component == 0{
            self.matchLable.text = "You Selected The Animal Name is \'\(animalNames[row])\'";
        } else {
            self.matchLable.text = "You Selected The Animal Sound is \'\(animalSounds[row])\'";
        }
        let selectedName = pickerView.selectedRow(inComponent: 0);
        let selectedSound = pickerView.selectedRow(inComponent: 1);
        let result = animalSounds.count - 1 - selectedSound;
        if(selectedName == result){
            self.resultLable.text = "Yes, \(animalNames[selectedName]) sounds is \(animalSounds[selectedSound])"
        } else {
            self.resultLable.text = "No, \(animalNames[selectedName]) doesn't go \(animalSounds[selectedSound])"
        }
    }
        
    
    @IBOutlet weak var matchLable: UILabel!
    
    @IBOutlet weak var resultLable: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
}

