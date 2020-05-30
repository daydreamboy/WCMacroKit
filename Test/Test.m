//
//  Test.m
//  Test
//
//  Created by wesley chen on 16/8/28.
//
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test : XCTestCase

@end

@implementation Test

- (void)setUp {
    [super setUp];
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
    [super tearDown];
}

#pragma mark - __TIME__

- (void)test___TIME__ {
    __TIME__;
    NSLog(@"%s", __TIME__);
}

#pragma mark - __TIMESTAMP__

- (void)test___TIMESTAMP__ {
    __TIMESTAMP__;
    NSLog(@"%s", __TIMESTAMP__);
}

#pragma mark - __COUNTER__

- (void)test___COUNTER__ {
    NSLog(@"%d", __COUNTER__); // 0
    NSLog(@"%d", __COUNTER__); // 1
    NSLog(@"%d", __COUNTER__); // 2
}

#pragma mark - __BASE_FILE__

- (void)test___BASE_FILE__ {
    NSLog(@"%s", __BASE_FILE__);
}

#pragma mark - __FILE_NAME__

- (void)test___FILE_NAME__ {
    NSLog(@"%s", __FILE_NAME__);
}

#pragma mark -

- (void)test_sel {
    //    NSString *selector = NSStringFromSelector(@selector(buttonClicked:));
    //    SEL_SAFE_CALL(self, @selector(buttonClicked));
    
    //    SEL_SAFE_CALL(self, @selector(actionWithFirstParam:), self);
    
    //    id receiver = self;
    //
    //    IMP imp__ = [receiver methodForSelector:selector__];
    //    void (*func__)(id, SEL, __VA_ARGS__) = (void *)imp__;
    //    func__(receiver, selector, __VA_ARGS__);
}

- (void)actionWithFirstParam:(id)firstParam {
    NSLog(@"_cmd: %@", NSStringFromSelector(_cmd));
}

- (void)buttonClicked {
    NSLog(@"_cmd: %@", NSStringFromSelector(_cmd));
}

@end
