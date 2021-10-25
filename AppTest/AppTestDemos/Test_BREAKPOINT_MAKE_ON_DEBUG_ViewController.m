//
//  Test_BREAKPOINT_MAKE_ON_DEBUG_ViewController.m
//  AppTest
//
//  Created by wesley_chen on 2021/2/25.
//

#import "Test_BREAKPOINT_MAKE_ON_DEBUG_ViewController.h"
#import <WCMacroKit/WCMacroKit.h>

@interface Test_BREAKPOINT_MAKE_ON_DEBUG_ViewController ()

@end

@implementation Test_BREAKPOINT_MAKE_ON_DEBUG_ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    sDisableGlobalBreakpointMakeOnDebug = YES;
    
    [self test_BREAKPOINT_MAKE_ON_DEBUG];
}

- (void)test_BREAKPOINT_MAKE_ON_DEBUG {
    BREAKPOINT_MAKE_ON_DEBUG(NO, @"set NO to trigger breakpoint");
}

@end
