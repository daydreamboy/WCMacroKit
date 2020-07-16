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

- (void)test_ASTR_M {
    NSMutableAttributedString *output;
    
    output = ASTR_M(@"123");
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    
    output = ASTR_M(nil);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 0);
    
    output = ASTR_M(@10);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 0);
}

- (void)test_ASTR2_M {
    NSMutableAttributedString *output;
    NSDictionary *attrs;
    
    output = ASTR2_M(@"123", attrs);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    
    output = ASTR2_M(nil, attrs);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 0);
    
    output = ASTR2_M(@"123", nil);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 3);
}

- (void)test_ASTR_M_CATENATE {
    NSMutableAttributedString *output;
    NSAttributedString *str1;
    NSAttributedString *str2;

    output = ASTR_M_CATENATE(str1, str2);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 0);
    
    str1 = ASTR(@"12");
    output = ASTR_M_CATENATE(str1, nil);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 2);
    
    str1 = ASTR(@"12");
    str2 = ASTR(@"34");
    output = ASTR_M_CATENATE(str1, str2);
    XCTAssertTrue([output isKindOfClass:[NSMutableAttributedString class]]);
    XCTAssertTrue(output.length == 4);
}

@end
