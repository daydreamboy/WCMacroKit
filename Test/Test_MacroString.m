//
//  Test_MacroString.m
//  Test
//
//  Created by wesley_chen on 2020/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroString : XCTestCase

@end

@implementation Test_MacroString

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)test_STR_IF_EMPTY {
    
    NSString *nilString;
    XCTAssertFalse(STR_IF_EMPTY(nilString));
    
    NSString *emptyString = @"";
    XCTAssertTrue(STR_IF_EMPTY(emptyString));
    
    if (!STR_IF_EMPTY(emptyString)) {
        NSLog(@"%@ is not an empty string", nilString);
    }
    else {
        NSLog(@"an empty string");
    }
    
    NSString *notEmptyString = @"not empty";
    XCTAssertFalse(STR_IF_EMPTY(notEmptyString));
}

- (void)test_STR_IF_NOT_EMPTY {
    NSString *nilString;
    XCTAssertFalse(STR_IF_NOT_EMPTY(nilString));
    
    if (STR_IF_NOT_EMPTY(nilString)) {
        NSLog(@"%@ is not an nil string", nilString);
    }
    else {
        NSLog(@"a nil string");
    }
    
    NSString *emptyString = @"";
    XCTAssertFalse(STR_IF_NOT_EMPTY(emptyString));
    
    // A string and not empty
    if (STR_IF_NOT_EMPTY(emptyString)) {
        NSLog(@"%@ is not an empty string", nilString);
    }
    else {
        NSLog(@"an empty string");
    }
    
    NSString *notEmptyString = @"not empty";
    XCTAssertTrue(STR_IF_NOT_EMPTY(notEmptyString));
}

- (void)test_STR_FORMAT {
    NSLog(@"%@", STR_FORMAT(@"本地文件不存在, 路径是%@", @"path/to/file"));
    NSLog(@"%@", STR_FORMAT(@"参数不对, 参数1是%@，参数2是%@", @"a", @"b"));
    
    XCTAssertEqualObjects(STR_FORMAT(@"本地文件不存在, 路径是%@", @"path/to/file"), @"本地文件不存在, 路径是path/to/file");
    XCTAssertEqualObjects(STR_FORMAT(@"参数不对, 参数1是%@，参数2是%@", @"a", @"b"), @"参数不对, 参数1是a，参数2是b");
}

@end
