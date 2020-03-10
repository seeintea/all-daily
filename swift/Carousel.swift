//
//  ViewController.swift
//  Carousel
//
//  Created by LiweiGu on 2020/3/9.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIScrollViewDelegate {
    
    // 代理方法
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        let scrollW = scrollView.frame.size.width;
        let page = (scrollView.contentOffset.x + scrollW*0.5)/scrollW;
        self.pageControl.currentPage = Int(page);
    }
    
    // 手动拖动暂停定时器
    func scrollViewWillBeginDragging(_ scrollView: UIScrollView) {
        self.removeTimer();
    }
    
    // 手动拖动结束重启定时器
    func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
        self.addTimer();
    }
    
    // 定时器
    var timer: Timer?;
    
    func addTimer() {
        self.timer = Timer.scheduledTimer(timeInterval: 3.0, target: self, selector: #selector(nextImage), userInfo: nil, repeats: true);
        
    }
    
    func removeTimer() {
        self.timer?.invalidate();
        self.timer = nil;
    }
    
    @objc func nextImage() {
        let count = 6;
        var page = 0;
        if(self.pageControl.currentPage == count-1){
            page = 0;
        } else {
            page = self.pageControl.currentPage + 1;
        }
        let offSetX = CGFloat(page)*self.scrollView.frame.size.width;
        let offSet = CGPoint(x: offSetX, y: 0);
        self.scrollView.setContentOffset(offSet, animated: true);
    }

    @IBOutlet weak var scrollView: UIScrollView!
    
    @IBOutlet weak var pageControl: UIPageControl!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        let count = 6;
        let imageY:CGFloat = 0;
        let imageW = self.scrollView.frame.size.width;
        let imageH = self.scrollView.frame.size.height;
        var i = 0;
        while(i<count){
            let imageX = CGFloat(i)*imageW;
            let imageView = UIImageView.init(frame: CGRect(x: imageX,y: imageY,width: imageW,height: imageH));
            let imageName = String(format: "img_0%d", i+1);
            i += 1;
            imageView.image = UIImage(named: imageName);
            self.scrollView.addSubview(imageView);
        }
        
        let contentW = CGFloat(count)*imageW;
        self.scrollView.contentSize = CGSize(width: contentW, height: 0);
        self.scrollView.showsHorizontalScrollIndicator = false;
        self.scrollView.isPagingEnabled = true;
        self.pageControl.numberOfPages = count;
        self.scrollView.delegate = (self as UIScrollViewDelegate);
        self.addTimer();
    }


}

