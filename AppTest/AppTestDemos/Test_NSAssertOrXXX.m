//
//  ViewController.m
//  AppTest
//
//  Created by wesley chen on 16/8/28.
//
//

#import "Test_NSAssertOrXXX.h"
#import "WCMacroKit.h"

@interface Test_NSAssertOrXXX ()
@end

@implementation Test_NSAssertOrXXX

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self test_NSAssertOrReturn];
    
    NSString *nilValue = [self test_NSAssertOrReturnNil];
    NSAssert(nilValue == nil, @"should be nil");

    BOOL noValue = [self test_NSAssertOrReturnNO];
    NSAssert(noValue == NO, @"should be NO");
    
    // TODO:
    // NSAssertOrBreak
    // NSAssertOrContinue
}

- (void)test_NSAssertOrReturn {
    NSAssertOrReturn(NO, @"test NSAssertOrReturn");
    
    NSLog(@"will never output");
}

- (NSString *)test_NSAssertOrReturnNil {
    NSAssertOrReturnNil(NO, @"test NSAssertOrReturnNil");
    
    return @"a string";
}

- (BOOL)test_NSAssertOrReturnNO {
    NSAssertOrReturnNO(NO, @"test NSAssertOrReturnNO");
    
    return YES;
}

@end
