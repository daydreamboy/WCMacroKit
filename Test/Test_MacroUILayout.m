//
//  Test_MacroUILayout.m
//  Test
//
//  Created by wesley_chen on 2021/7/15.
//

#import <XCTest/XCTest.h>
#import <UIKit/UIKit.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroUILayout : XCTestCase

@end

@implementation Test_MacroUILayout

- (void)test_FrameSetOrigin {
    UIView *view;
    
    // Case 1
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetOrigin(view.frame, 7, 8);
    XCTAssertTrue(view.frame.origin.x == 7);
    XCTAssertTrue(view.frame.origin.y == 8);
    
    // Case 2
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetOrigin(view.frame, 7, NAN);
    XCTAssertTrue(view.frame.origin.x == 7);
    XCTAssertTrue(view.frame.origin.y == 2);
    
    // Case 3
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetOrigin(view.frame, NAN, NAN);
    XCTAssertTrue(view.frame.origin.x == 1);
    XCTAssertTrue(view.frame.origin.y == 2);
}

- (void)test_FrameSetSize {
    UIView *view;
    
    // Case 1
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetSize(view.frame, 7, 8);
    XCTAssertTrue(view.frame.size.width == 7);
    XCTAssertTrue(view.frame.size.height == 8);
    
    // Case 2
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetSize(view.frame, 7, NAN);
    XCTAssertTrue(view.frame.size.width == 7);
    XCTAssertTrue(view.frame.size.height == 4);
    
    // Case 3
    view = [[UIView alloc] initWithFrame:CGRectMake(1, 2, 3, 4)];
    FrameSetSize(view.frame, NAN, NAN);
    XCTAssertTrue(view.frame.size.width == 3);
    XCTAssertTrue(view.frame.size.height == 4);
}

- (void)test_UIEdgeInsetsSet {
    UIButton *button;
    
    // Case 1
    button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.contentEdgeInsets = UIEdgeInsetsMake(1, 2, 3, 4);
    UIEdgeInsetsSet(button.contentEdgeInsets, 7, 8, NAN, NAN);
    XCTAssertTrue(button.contentEdgeInsets.top == 7);
    XCTAssertTrue(button.contentEdgeInsets.left == 8);
    
    // Case 2
    button.contentEdgeInsets = UIEdgeInsetsMake(1, 2, 3, 4);
    UIEdgeInsetsSet(button.contentEdgeInsets, 7, NAN, NAN, NAN);
    XCTAssertTrue(button.contentEdgeInsets.top == 7);
    XCTAssertTrue(button.contentEdgeInsets.left == 2);
    
    // Case 3
    button.contentEdgeInsets = UIEdgeInsetsMake(1, 2, 3, 4);
    UIEdgeInsetsSet(button.contentEdgeInsets, NAN, NAN, NAN, NAN);
    XCTAssertTrue(button.contentEdgeInsets.top == 1);
    XCTAssertTrue(button.contentEdgeInsets.left == 2);
    XCTAssertTrue(button.contentEdgeInsets.bottom == 3);
    XCTAssertTrue(button.contentEdgeInsets.right == 4);
}

@end
