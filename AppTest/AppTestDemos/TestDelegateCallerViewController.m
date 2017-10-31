//
//  TestDelegateCallerViewController.m
//  AppTest
//
//  Created by wesley_chen on 30/10/2017.
//

#import "TestDelegateCallerViewController.h"
#import "WCMacroKit.h"

@implementation TestDelegateCallerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
//    [self test_with_original_code];
    [self test_with_macros];
}

#pragma mark - Test Methods

- (void)test_with_original_code {
    SEL sel = @selector(testMethodWithArg:);
    id delegate = self;
    id arg3 = [@"something" copy];
    arg3 = @"string";
    __unused id arg4 = [(__bridge id)(void *)0 copy];
    
    NSString *returnString = ({
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        id returnValue = nil;
        if ([delegate respondsToSelector:sel]) {
            // @see https://stackoverflow.com/questions/22018272/nsinvocation-returns-value-but-makes-app-crash-with-exc-bad-access
            void *tempReturnValue = nil;
            NSMethodSignature *methodSignature = [delegate methodSignatureForSelector:sel];
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
            invocation.target = delegate;
            invocation.selector = sel;
            [invocation setArgument:&arg3 atIndex:2];
            [invocation invoke];
            [invocation getReturnValue:&tempReturnValue];
            returnValue = (__bridge id)tempReturnValue;
        }
        returnValue;
#pragma GCC diagnostic pop
    });

    NSLog(@"return value: %@", returnString);
}

- (void)test_with_macros {
    NSString *returnValue;
    
    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");
    NSLog(@"returnValue: %@", returnValue);
    
    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:"), @"A", nil, @"C");
    NSLog(@"returnValue: %@", returnValue);

    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"noneExistedMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");
    NSLog(@"returnValue: %@", returnValue);
    
    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");
    
    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:"), nil, nil, nil);
}

#pragma mark - Callee Methods

#pragma mark > with return values

- (NSString *)testMethodWithArg:(NSString *)string {
    return [NSString stringWithFormat:@"#%@", string];
}

- (NSString *)testMethodWithArg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 {
    return [NSString stringWithFormat:@"%@||%@||%@", arg1, arg2, arg3];
}

#pragma mark > without return values

- (void)testNoReturnMethodWithArg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 {
    NSLog(@"%@", [NSString stringWithFormat:@"%@||%@||%@", arg1, arg2, arg3]);
}

@end
