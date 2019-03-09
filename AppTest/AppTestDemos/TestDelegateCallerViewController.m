//
//  TestDelegateCallerViewController.m
//  AppTest
//
//  Created by wesley_chen on 30/10/2017.
//

#import "TestDelegateCallerViewController.h"
#import <WCMacroKit/WCMacroKit.h>

typedef NS_ENUM(NSUInteger, SomeState) {
    SomeStateUnknown,
    SomeStateSuccess,
    SomeStateFailed,
};

@implementation TestDelegateCallerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
//    [self test_with_original_code1];
//    [self test_with_original_code2];
//    [self test_with_original_code3];
//    [self test_with_original_code4];
    
    [self test_with_macros];
}

#pragma mark - Test Methods

- (void)test_with_original_code1 {
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
            [invocation setArgument:(void *)&arg3 atIndex:2];
            [invocation invoke];
            [invocation getReturnValue:&tempReturnValue];
            returnValue = (__bridge id)tempReturnValue;
        }
        returnValue;
#pragma GCC diagnostic pop
    });

    NSLog(@"return value: %@", returnString);
}

- (void)test_with_original_code2 {
    SEL sel = @selector(testNoReturnMethodWithPrimitiveType:);
    id delegate = self;
    BOOL arg = YES;
    
    typeof(arg) arg1 = arg;
    
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    if ([delegate respondsToSelector:sel]) {
        NSMethodSignature *methodSignature = [delegate methodSignatureForSelector:sel];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = delegate;
        invocation.selector = sel;
        [invocation setArgument:(void *)&arg1 atIndex:2];
        [invocation invoke];
    }
#pragma GCC diagnostic pop
}

- (void)test_with_original_code3 {
    SEL sel = @selector(testNoReturnMethodWithEnumType:);
    id delegate = self;
    SomeState state = SomeStateSuccess;
    
    typeof(state) arg1 = state;
    
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    if ([delegate respondsToSelector:sel]) {
        NSMethodSignature *methodSignature = [delegate methodSignatureForSelector:sel];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = delegate;
        invocation.selector = sel;
        [invocation setArgument:(void *)&arg1 atIndex:2];
        [invocation invoke];
    }
#pragma GCC diagnostic pop
}

- (void)test_with_original_code4 {
    SEL sel = NSSelectorFromString(@"testWeakSelfAsParameter:p2:p3:");
    id delegate = self;
    __weak typeof(self) weak_self = self;
    
    typeof(weak_self) arg1 = weak_self;
    
    if ([delegate respondsToSelector:sel]) {
        NSMethodSignature *methodSignature = [delegate methodSignatureForSelector:sel];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = delegate;
        invocation.selector = sel;
        [invocation setArgument:(void *)&arg1 atIndex:2];
        [invocation invoke];
    }
}

- (void)test_with_macros {
    NSString *returnValue;
    
    // Case 1: normal
    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");
    NSLog(@"returnValue: %@", returnValue);

    // Case 2: nil as parameter
    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithArg1:arg2:arg3:"), @"A", nil, @"C");
    NSLog(@"returnValue: %@", returnValue);

    // Case 3: none existed method
    returnValue = DELEGATE_SAFE_CALL3_WITH_RETURN(self, NSSelectorFromString(@"noneExistedMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");
    NSLog(@"returnValue: %@", returnValue);

    // Case 4: basic type parameter
    returnValue = DELEGATE_SAFE_CALL4_WITH_RETURN(self, NSSelectorFromString(@"testMethodWithBOOL:integer:cgFloat:enumType:"), YES, 100, 3.14, SomeStateSuccess);
    NSLog(@"returnValue: %@", returnValue);
    
    // Case 5: without return value
    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:"), @"A", @"B", @"C");

    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:"), nil, nil, nil);

    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testNoReturnMethodWithArg1:arg2:arg3:"), nil, nil, nil);
    
    // Case 6: weak self as parameter
    __weak typeof(self) weak_self = self;
    DELEGATE_SAFE_CALL3(self, NSSelectorFromString(@"testWeakSelfAsParameter:p2:p3:"), weak_self, nil, nil);
    
    // Case 7: float as parameter
    // Note: float type must append `f`, e.g 4.0 should be 4.0f
    DELEGATE_SAFE_CALL1(self, NSSelectorFromString(@"testFloatWithArg1:"), 4.0f);
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

- (void)testWeakSelfAsParameter:(id)weakSelf p2:(id)p2 p3:(id)p3 {
    typeof(self) caller = weakSelf;
    [caller log];
}

- (void)log {
    NSLog(@"called by testWeakSelfAsParameter");
}

- (void)testFloatWithArg1:(float)arg1 {
    NSLog(@"float: %f", arg1);
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
