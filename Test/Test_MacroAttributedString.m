//
//  Test_MacroAttributedString.m
//  Test
//
//  Created by wesley_chen on 2020/7/16.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroAttributedString : XCTestCase

@end

@implementation Test_MacroAttributedString

- (void)setUp {
    NSLog(@"");
}

- (void)tearDown {
    NSLog(@"");
}

- (void)test_ASTR {
    NSAttributedString *output;
    
    output = ASTR(@"123");
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    
    output = ASTR(nil);
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    XCTAssertTrue(output.length == 0);
    
    output = ASTR(@10);
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    XCTAssertTrue(output.length == 0);
}

- (void)test_ASTR2 {
    NSAttributedString *output;
    NSDictionary *attrs;
    
    output = ASTR2(@"123", attrs);
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    
    output = ASTR2(nil, attrs);
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    XCTAssertTrue(output.length == 0);
    
    output = ASTR2(@"123", nil);
    XCTAssertTrue([output isKindOfClass:[NSAttributedString class]]);
    XCTAssertTrue(output.length == 3);
}

@end
