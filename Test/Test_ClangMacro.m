//
//  Test_ClangMacro.m
//  Test
//
//  Created by wesley_chen on 2023/1/4.
//

#import <XCTest/XCTest.h>

#define MY_MIN(x, y) x < y ? x : y
#pragma clang deprecated(MY_MIN, "use std::min instead")

@interface Test_ClangMacro : XCTestCase

@end

@implementation Test_ClangMacro

- (void)test_clang_deprecated {
    int min = MY_MIN(1, 2); // Warning: Macro 'MY_MIN' has been marked as deprecated: use std::min instead
    NSLog(@"min:%d", min);
}

- (void)test___BASE_FILE__ {
    NSLog(@"%s", __BASE_FILE__);
}

- (void)test___FILE_NAME__ {
    NSLog(@"%s", __FILE_NAME__);
}

- (void)test___clang__ {
#ifdef __clang__
    NSLog(@"Compiled with Clang");
#else
    NSLog(@"Compiled without Clang");
#endif
}

- (void)test___clang_version__ {
    NSLog(@"%s", __clang_version__);
}

@end
