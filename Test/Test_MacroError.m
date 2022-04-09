//
//  Test_MacroError.m
//  Test
//
//  Created by wesley_chen on 2022/4/8.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroError : XCTestCase

@end

@implementation Test_MacroError

- (void)test_WCErrorDomainMake {
    XCTAssertEqualObjects([self instanceMethod], @"Test_MacroErrorErrorDomain");
    XCTAssertEqualObjects([self.class classMethod], @"Test_MacroErrorErrorDomain");
    
    NSError *error = [NSError errorWithDomain:WCErrorDomainMake code:1 userInfo:@{ NSLocalizedFailureReasonErrorKey: @"some reason" }];
    XCTAssertEqualObjects(error.domain, @"Test_MacroErrorErrorDomain");
}

- (void)test_WCErrorMake {
    NSError *error = WCErrorMake(-1, @"some reason");
    XCTAssertEqualObjects(error.domain, @"Test_MacroErrorErrorDomain");
    XCTAssertEqualObjects(error.localizedFailureReason, @"some reason");
    XCTAssertTrue(error.code == -1);
}

- (void)test_self {
    [self instanceMethod];
    [self.class classMethod];
}

- (NSString *)instanceMethod {
    NSString *clz = NSStringFromClass(self.class);
    NSLog(@"clz: %@", clz);
    
    return WCErrorDomainMake;
}

+ (NSString *)classMethod {
    NSString *clz = NSStringFromClass(self.class);
    NSLog(@"clz: %@", clz);
    
    return WCErrorDomainMake;
}

@end
