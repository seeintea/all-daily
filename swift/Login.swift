//
//  ViewController.swift
//  Login
//
//  Created by LiweiGu on 2020/3/9.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    // 本地用户名、密码
    let username = "admin";
    let password = "password"
    
    // messageBox 事件
    func messageBox(str:String) {
        let alertBox = UIAlertController(title: "提示", message: str, preferredStyle: UIAlertController.Style.alert);
        let alertAtion = UIAlertAction(title: "确定", style: UIAlertAction.Style.default, handler: { (_) in
            self.userName.text = "";
            self.passWord.text = "";
            self.userName.becomeFirstResponder();
        });
        alertBox.addAction(alertAtion);
        self.present(alertBox, animated: true, completion: nil);
    }
    
    
    @IBOutlet weak var userName: UITextField!
    
    @IBOutlet weak var passWord: UITextField!
    
    
    @IBAction func login(_ sender: UIButton) {
        let user = userName.text;
        if(user == ""){
            messageBox(str: "用户名不能为空");
        }
        let pwd = passWord.text;
        if(pwd == ""){
            messageBox(str: "密码不能为空");
        }
        if(user != username){
            messageBox(str: "用户输入错误");
        }
        if(pwd != password){
            messageBox(str: "密码输入错误");
        }
        messageBox(str: "登陆成功!");
    }
    
    @IBAction func hideKeyBoard(_ sender: UIButton) {
        self.view.endEditing(true);
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

