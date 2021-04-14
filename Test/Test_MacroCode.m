//
//  Test_MacroCode.m
//  Test
//
//  Created by wesley_chen on 2020/3/5.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroCode : XCTestCase
@property (nonatomic, strong) NSMutableDictionary *dictM;
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
