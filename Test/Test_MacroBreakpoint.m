//
//  Test_MacroBreakpoint.m
//  Test
//
//  Created by wesley_chen on 2021/2/25.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroBreakpoint : XCTestCase

@end

@implementation Test_MacroBreakpoint

- (void)test_BREAKPOINT_MAKE_ON_DEBUG {
    BREAKPOINT_MAKE_ON_DEBUG(NO, @"set NO to trigger breakpoint");
}

@end
