//
//  ViewController.swift
//  CookBook
//
//  Created by LiweiGu on 2020/3/24.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    // 加载表格数据源 name-scores
    let cookNames = ["桂花糯米藕", "亲子丼", "玻璃糖饼干", "蚝油蘑菇", "鸡蛋三明治", "洋葱炒鸡蛋", "糯米烧麦", "阿胶固元膏"];
    let cookScores = ["9.1分", "7.6分", "6.9分", "8.4分", "5.3分", "7.5分", "8.2分", "9.4分"];
    
    // Swift 协议写法
    // 设置表格的行
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cookNames.count;
    }
    
    // 设置行表格内容
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cookIndetifier = "cookCell";
        var cell = (tableView.dequeueReusableCell(withIdentifier: cookIndetifier));
        if !(cell != nil) {
            cell = UITableViewCell.init(style: UITableViewCell.CellStyle.subtitle, reuseIdentifier: cookIndetifier);
        }
        
        // 获取菜谱菜名
        let cookName = cookNames[indexPath.row];
        
        // 设置表格行中的参数
        cell?.textLabel?.text = cookName;
        cell?.imageView?.image = UIImage.init(named: String.init(format: "%@.png", cookName));
        cell?.detailTextLabel?.text = cookScores[indexPath.row];
        
        // 返回行
        return cell!;
    }
    
    // 设置行表格格式
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60;
    }
    
    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return 60;
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 60;
    }
    
    // 表格头
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        let str = "本餐馆的菜单信息";
        return str;
    }
    
    // 表格尾
    func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        let str = String.init(format: "共有 %lu 道菜肴信息", cookNames.count);
        return str;
    }
    
    // 点击行为
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let msg = String.init(format: "当前选中的菜肴名: %@ , 评分为 %@ ", cookNames[indexPath.row], cookScores[indexPath.row]);
        self.showMessage(str: msg);
    }
    
    // 阻止某行点击行为
    func tableView(_ tableView: UITableView, willSelectRowAt indexPath: IndexPath) -> IndexPath? {
        let row = indexPath.row;
        if row == 3 {
            self.showMessage(str: "改行行为被阻止!");
            return nil;
        }
        return indexPath;
    }
    
    // 弹窗
    func showMessage(str:String) {
        let msgBox = UIAlertController.init(title: "提示", message: str, preferredStyle: UIAlertController.Style.alert);
        let action = UIAlertAction.init(title: "确定", style: UIAlertAction.Style.default, handler: nil);
        // 添加确定按钮
        msgBox.addAction(action);
        // 显示弹窗
        self.present(msgBox, animated: true, completion: nil);
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

}
