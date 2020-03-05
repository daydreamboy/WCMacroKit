//
//  Test_MacroCode.m
//  Test
//
//  Created by wesley_chen on 2020/3/5.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroCode : XCTestCase

@end

@implementation Test_MacroCode

- (void)setUp {
}

- (void)tearDown {
}

- (void)test_CODE_SAFE_RUN_ON_MAIN_THREAD {
    CODE_SAFE_RUN_ON_MAIN_THREAD(
         NSLog(@"make sure this code run on main thread");
    );
}


@end
