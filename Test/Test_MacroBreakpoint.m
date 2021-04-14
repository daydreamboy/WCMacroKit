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

- (void)test_CODE_RUN_IN_DEBUG {
    int a = 1;
    CODE_RUN_IN_DEBUG(^{
        if (a == 1) {
            NSLog(@"2113");
        }
    });
    
    /**
     on Debug:
     s_debug_function(^{
        if (a == 1) {
            NSLog(@"2113");
        }
     })
     
     on Release:
     __attribute__((__unused__)) void (^block_internal_1)(void) =(^{
         if (a == 1) {
             NSLog(@"2113");
         }
     });
     */
    CODE_RUN_IN_DEBUG(^{
        if (a == 1) {
            NSLog(@"2113");
        }
    });
}

@end
