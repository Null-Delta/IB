//: A UIKit based Playground for presenting user interface
  
import UIKit
import PlaygroundSupport

class MyViewController : UIViewController {
    override func loadView() {
        let view = UIView()
        view.backgroundColor = .white

        let label = UITextView()
        label.frame = CGRect(x: 20, y: 200, width: 200, height: 200)
        label.backgroundColor = .blue
        label.center = CGPoint(x: 200, y: 200)
        label.text = "Hello World! somebody once told me that world is gonna roll me"
        label.textColor = .white
        label.textAlignment = .center
        label.font = .systemFont(ofSize: 32, weight: .bold)

        let text = label.text!

        var currentPosition = 0
        label.selectedRange = NSRange(location: 0, length: 0)

        while currentPosition != label.text.count {
            let currentPositionLabel = label.selectedTextRange!.start
            let endOfLine =
            label.tokenizer.position(from: currentPositionLabel, toBoundary: .line, inDirection: .storage(.forward))!

            let intEnd = label.offset(from: label.beginningOfDocument, to: endOfLine)

            print(text[text.index(text.startIndex, offsetBy: currentPosition)..<text.index(text.startIndex, offsetBy: intEnd)])

            currentPosition = intEnd
            label.selectedRange = NSRange(location: currentPosition, length: 0)
        }

        view.addSubview(label)

        self.view = view
    }
}
// Present the view controller in the Live View window
PlaygroundPage.current.liveView = MyViewController()
