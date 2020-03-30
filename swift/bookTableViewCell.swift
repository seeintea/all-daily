//
//  bookTableViewCell.swift
//  bookList
//
//  Created by LiweiGu on 2020/3/30.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

import UIKit

class bookTableViewCell: UITableViewCell {

    
    @IBOutlet weak var bookAuthor: UILabel!
    
    @IBOutlet weak var bookTitle: UILabel!
    
    @IBOutlet weak var bookComments: UILabel!
    
    @IBOutlet weak var bookIcon: UIImageView!
    
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
