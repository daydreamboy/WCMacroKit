//
//  Test_WCCallerTool_ViewController.m
//  AppTest
//
//  Created by wesley_chen on 20/12/2017.
//

#import "Test_WCCallerTool_ViewController.h"
#import "WCCallerTool.h"
#import "WCMacroKit.h"

typedef NS_ENUM(NSUInteger, SomeState) {
    SomeStateUnknown,
    SomeStateSuccess,
    SomeStateFailed,
};

@implementation Test_WCCallerTool_ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self test_with_WCCallerTool];
}

#pragma mark - Test Methods

- (void)test_with_WCCallerTool {
    NSString *returnValue;
    
    returnValue = [WCCallerTool call3AndReturn:self selector:NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:") param1:@"A" param2:@"B" param3:@"C"];
    NSLog(@"returnValue: %@", returnValue);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    returnValue = [WCCallerTool call3AndReturn:self selector:NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:") param1:@"A" param2:nil param3:@"C"];
#pragma GCC diagnostic pop
    NSLog(@"returnValue: %@", returnValue);
    
    returnValue = [WCCallerTool call3AndReturn:self selector:NSSelectorFromString(@"noneExistedMethodWithArg1:arg2:arg3:") param1:@"A" param2:@"B" param3:@"C"];
    NSLog(@"returnValue: %@", returnValue);
    
    // Note: WCCallerTool not support basic type parameter
    /*
    returnValue = DELEGATE_SAFE_CALL4_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithBOOL:integer:cgFloat:enumType:"), YES, 100, 3.14, SomeStateSuccess);
    NSLog(@"returnValue: %@", returnValue);
     */
    
    [WCCallerTool call3:self selector:NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:") param1:@"A" param2:@"B" param3:@"C"];
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    [WCCallerTool call3:self selector:NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:") param1:nil param2:nil param3:nil];
    [WCCallerTool call3:self selector:NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:") param1:nil param2:nil param3:nil];
#pragma GCC diagnostic pop
}

#pragma mark - Callee Methods

#pragma mark > with return values

- (NSString *)testMethodWithArg:(NSString *)string {
    return [NSString stringWithFormat:@"#%@", string];
}

- (NSString *)testMethodWithArg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 {
    return [NSString stringWithFormat:@"%@||%@||%@", arg1, arg2, arg3];
}

- (NSString *)testMethodWithBOOL:(BOOL)yesOrNo integer:(NSInteger)integer cgFloat:(CGFloat)cgFloat enumType:(SomeState)state {
    
    NSString *stateString = [self stringFromState:state];
    return [NSString stringWithFormat:@"BOOL=%@ || NSInteger=%ld || CGFloat=%f || %@", STR_OF_BOOL(yesOrNo), (long)integer, cgFloat, stateString];
}

#pragma mark > without return values

- (void)testNoReturnMethodWithArg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 {
    NSLog(@"%@", [NSString stringWithFormat:@"%@||%@||%@", arg1, arg2, arg3]);
}

- (void)testNoReturnMethodWithPrimitiveType:(BOOL)yesOrNo  {
    NSLog(@"%@", [NSString stringWithFormat:@"%@", STR_OF_BOOL(yesOrNo)]);
}

- (void)testNoReturnMethodWithEnumType:(SomeState)state  {
    NSLog(@"%@", [NSString stringWithFormat:@"%@", [self stringFromState:state]]);
}

#pragma mark - Utility

- (NSString *)stringFromState:(SomeState)state {
    NSString *stateString = nil;
    switch (state) {
        case SomeStateUnknown:
            stateString = @"unknown";
            break;
        case SomeStateSuccess:
            stateString = @"success";
            break;
        case SomeStateFailed:
            stateString = @"failed";
            break;
        default:
            break;
    }
    
    return stateString;
}

@end
