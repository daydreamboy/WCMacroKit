//
//  Test_MacroColor.m
//  Test
//
//  Created by wesley_chen on 2020/7/23.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroColor : XCTestCase

@end

@implementation Test_MacroColor

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)testExample {
    UIColor *color = UICOLOR_RGBA(0x111F2C3D);
    NSLog(@"%@");
}

@end
