//
//  Test_MacroCode.m
//  Test
//
//  Created by wesley_chen on 2020/3/5.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

// Note: define a shorthand for the custom prefix
#define CustomPrefix test

#define MyMethodPrefixed(...) WCMethodPrefixed(CustomPrefix, __VA_ARGS__)
#define MySelectorPrefixed(...) WCSelectorPrefixed(CustomPrefix, __VA_ARGS__)
#define MyMethodCallPrefixed(...) WCMethodCallPrefixed(CustomPrefix, __VA_ARGS__)


@interface NSObject (MyCategory)
- (BOOL)WCMethodPrefixed(weiwo, is:(NSString *)className;);
- (BOOL)WCMethodPrefixed(weiwo, checkSomeThing:(NSDictionary<NSString *, NSString *> *)someThing);
- (BOOL)MyMethodPrefixed(checkSomeThing:(NSDictionary<NSString *, NSString *> *)someThing andAnotherThing:(NSArray<NSString *> *)anotherThing);
@end

@implementation NSObject (MyCategory)
- (BOOL)WCMethodPrefixed(weiwo, is:(NSString *)className) {
    return [self isKindOfClass:NSClassFromString(className)];
}

- (BOOL)WCMethodPrefixed(weiwo, checkSomeThing:(NSDictionary<NSString *, NSString *> *)someThing) {
    return YES;
}

- (BOOL)MyMethodPrefixed(checkSomeThing:(NSDictionary<NSString *, NSString *> *)someThing andAnotherThing:(NSArray<NSString *> *)anotherThing) {
    return YES;
}

@end

@interface Test_MacroCode : XCTestCase
@property (nonatomic, strong) NSMutableDictionary *dictM;
@end

@implementation Test_MacroCode

- (void)test_WCMethodPrefixed {
    XCTAssertTrue([self respondsToSelector:@selector(test_checkSomeThing:andAnotherThing:)]);
    XCTAssertTrue([self respondsToSelector:MySelectorPrefixed(checkSomeThing:andAnotherThing:)]);
    
    Test_MacroCode *object = [Test_MacroCode new];
    XCTAssertTrue([object test_checkSomeThing:@{} andAnotherThing:@[]]);
    
    XCTAssertTrue([object MyMethodCallPrefixed(checkSomeThing:@{} andAnotherThing:@[]]));
}

- (void)test_CODE_SAFE_RUN_ON_MAIN_THREAD {
    CODE_SAFE_RUN_ON_MAIN_THREAD(
         NSLog(@"make sure this code run on main thread");
    );
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

- (void)test_KVO {
    self.dictM = [NSMutableDictionary dictionary];
    [self.dictM addObserver:self forKeyPath:@"myCustomKey" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:nil];
    
    _dictM[@"myCustomKey"] = @"someValue";
    
    NSLog(@"213");
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    id newValue = change[NSKeyValueChangeNewKey];
    NSLog(@"%@", newValue);
}


@end
