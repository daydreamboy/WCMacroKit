//
//  Test_MacroTime.m
//  Test
//
//  Created by wesley_chen on 2024/8/28.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroTime : XCTestCase

@end

@implementation Test_MacroTime

- (void)test_MODIFY_TIME_FOR_CURRENT_FILE {
    NSLog(@"current file modify time: %@", MODIFY_TIME_FOR_CURRENT_FILE);
}

- (void)test_BUILD_TIME_FOR_CURRENT_FILE {
    NSLog(@"current file build time: %@", BUILD_TIME_FOR_CURRENT_FILE);
}

@end
