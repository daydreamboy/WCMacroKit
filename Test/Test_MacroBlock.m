//
//  Test_MacroBlock.m
//  Test
//
//  Created by wesley_chen on 2020/3/3.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroBlock : XCTestCase

@end

@implementation Test_MacroBlock

- (void)setUp {
    [super setUp];
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
    [super tearDown];
}

- (void)test_BLOCK_SAFE_RUN {
    void (^block1)(NSString *) = ^(NSString *string) {
        NSLog(@"%@", string);
        XCTAssertEqualObjects(string, @"123");
    };
    
    BLOCK_SAFE_RUN(block1, @"123");
    
    void (^block2)(void) = ^{
        NSLog(@"block2 called");
    };
    
    BLOCK_SAFE_RUN(block2);
}

- (void)test_BLOCK_SAFE_RUN_ON_MAIN_THREAD {
    // Case 1
    void (^block)(NSString *) = ^(NSString *string) {
        NSLog(@"%@", string);
        XCTAssertTrue([NSThread isMainThread]);
    };
    
    BLOCK_SAFE_RUN_ON_MAIN_THREAD(block, @"123");
    
    // Case 2
    BLOCK_SAFE_RUN_ON_MAIN_THREAD(^{
        NSLog(@"%@", @"456");
        XCTAssertTrue([NSThread isMainThread]);
    });
}

- (void)test_strongify_weakify {
    id foo = [[NSObject alloc] init];
    id bar = [[NSObject alloc] init];
    
    weakify(self);
    weakify(foo);
    
    // this block will not keep 'foo' or 'bar' alive
    BOOL (^matchesFooOrBar)(id) = ^ BOOL (id obj){
        // but now, upon entry, 'foo' and 'bar' will stay alive until the block has
        // finished executing
        strongify(self);
        strongify(foo);
        
        NSLog(@"self: %@", self);
        NSLog(@"foo: %@", foo);
        
        return [foo isEqual:obj] || [bar isEqual:obj];
    };
    
    matchesFooOrBar([NSDate date]);
}

@end
